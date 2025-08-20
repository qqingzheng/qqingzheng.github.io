import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# --- 1. 设置模拟参数 ---
# 为了简化，我们令 k_B = 1, gamma = 1
k_B = 1.0        # 玻尔兹曼常数
gamma = 1.0      # 阻尼系数
k = 2.0          # 弹簧劲度系数 (势能 U = 0.5 * k * x^2)

# 模拟时间参数
dt = 0.01        # 时间步长
num_steps = 20000 # 总步数
total_time = dt * num_steps

# --- 2. 定义朗之万动力学模拟函数 ---
def simulate_langevin(temperature, x0=0.0):
    """
    模拟一个粒子在谐振子势中的朗之万动力学。

    Args:
        temperature (float): 环境温度 (T).
        x0 (float): 粒子的初始位置.

    Returns:
        numpy.ndarray: 粒子的运动轨迹.
    """
    # 初始化存储轨迹的数组
    path = np.zeros(num_steps)
    path[0] = x0
    
    # 预计算噪声项的系数，提高效率
    # 噪声强度与温度的平方根成正比
    noise_scale = np.sqrt(2 * gamma * k_B * temperature * dt)
    
    for i in range(num_steps - 1):
        # 计算确定性力 (弹簧的恢复力 F = -kx)
        deterministic_force = -k * path[i]
        
        # 计算随机力 (高斯白噪声)
        random_force = noise_scale * np.random.randn()
        
        # 更新位置
        # dx = (F_det / gamma) * dt + (F_rand / gamma)
        path[i+1] = path[i] + (deterministic_force / gamma) * dt + (random_force / gamma)
        
    return path

# --- 3. 运行不同温度下的模拟 ---
low_temp = 1.0
high_temp = 10.0

print(f"正在模拟低温 (T={low_temp})...")
path_low_temp = simulate_langevin(low_temp, x0=5.0)

print(f"正在模拟高温 (T={high_temp})...")
path_high_temp = simulate_langevin(high_temp, x0=5.0)

print("模拟完成.")

# --- 4. 可视化结果 ---
sns.set_style("whitegrid")
time_array = np.linspace(0, total_time, num_steps)

# 图1: 比较不同温度下的运动轨迹
plt.figure(figsize=(14, 6))
plt.plot(time_array, path_low_temp, label=f'Low Temperature T = {low_temp}', alpha=0.8, color='blue')
plt.plot(time_array, path_high_temp, label=f'High Temperature T = {high_temp}', alpha=0.8, color='red')
plt.title('Particle Motion in Harmonic Potential', fontsize=16)
plt.xlabel('Time (s)', fontsize=12)
plt.ylabel('Position (x)', fontsize=12)
plt.legend(fontsize=12)
plt.grid(True)
plt.tight_layout()
plt.savefig('boltzmann_motion.png')


# 图2: 分析粒子的最终位置分布 (直方图)
# 理论上，最终分布应为玻尔兹曼分布 p(x) ∝ exp(-U(x)/k_B*T)
# 对于谐振子势，这是一个高斯分布
def plot_distribution(path, temperature, ax):
    sns.histplot(path, bins=50, kde=True, stat="density", ax=ax, label='Simulation Results (Histogram)')
    
    # Plot theoretical distribution curve (Gaussian distribution)
    # U(x) = 0.5*k*x^2 => p(x) = N * exp(-0.5*k*x^2 / (k_B*T))
    # This is a Gaussian distribution with mean 0 and variance (k_B*T)/k
    variance = (k_B * temperature) / k
    std_dev = np.sqrt(variance)
    x = np.linspace(path.min(), path.max(), 200)
    theoretical_dist = (1 / (std_dev * np.sqrt(2 * np.pi))) * np.exp(-x**2 / (2 * variance))
    
    ax.plot(x, theoretical_dist, 'r--', linewidth=2, label='Theoretical Boltzmann Distribution')
    ax.set_title(f'Position Distribution at T = {temperature}', fontsize=14)
    ax.set_xlabel('Position (x)', fontsize=12)
    ax.set_ylabel('Probability Density', fontsize=12)
    ax.legend()

fig, axes = plt.subplots(1, 2, figsize=(16, 6))
plot_distribution(path_low_temp, low_temp, axes[0])
plot_distribution(path_high_temp, high_temp, axes[1])

plt.suptitle('Comparison of Simulation Results with Theoretical Boltzmann Distribution', fontsize=18, y=1.02)
plt.tight_layout()
plt.savefig('boltzmann_distribution.png')