from matplotlib.animation import FuncAnimation
import matplotlib.pyplot as plt
import numpy as np

# 定义矩阵A
A = np.array([[1, 2], [3, 4]])

# 计算特征值和特征向量
eigenvalues, eigenvectors = np.linalg.eig(A)

print("特征值:")
print(eigenvalues)
print("\n特征向量:")
print(eigenvectors)


# 创建图形和坐标轴
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

# 设置坐标轴范围
for ax in (ax1, ax2):
    ax.set_xlim(-5, 5)
    ax.set_ylim(-5, 5)
    ax.grid(True)
    ax.axhline(0, color="black", linewidth=0.5)
    ax.axvline(0, color="black", linewidth=0.5)

# 初始单位圆上的点
theta = np.linspace(0, 2 * np.pi, 100)
circle = np.vstack((np.cos(theta), np.sin(theta)))

# 绘制初始单位圆和基向量
(unit_circle,) = ax1.plot(circle[0], circle[1], "b-", alpha=0.5)
(original_i,) = ax1.plot([0, 1], [0, 0], "r-", label="i")
(original_j,) = ax1.plot([0, 0], [0, 1], "g-", label="j")
# 绘制初始特征向量
(eigenvec1,) = ax1.plot(
    [0, eigenvectors[0, 0]], [0, eigenvectors[1, 0]], "m--", label="v1"
)
(eigenvec2,) = ax1.plot(
    [0, eigenvectors[0, 1]], [0, eigenvectors[1, 1]], "c--", label="v2"
)
ax1.legend()
ax1.set_title("before")

# 变换后的图形
(transformed_circle,) = ax2.plot([], [], "b-", alpha=0.5)
(transformed_i,) = ax2.plot([], [], "r-", label="i")
(transformed_j,) = ax2.plot([], [], "g-", label="j")
# 变换后的特征向量
(transformed_eigenvec1,) = ax2.plot([], [], "m--", label="v1")
(transformed_eigenvec2,) = ax2.plot([], [], "c--", label="v2")
ax2.legend()
ax2.set_title("after")


# 动画更新函数
def update(frame):
    # 计算当前变换矩阵 (线性插值)

    alpha = frame / 100
    current_A = np.eye(2) * (1 - alpha) + A * alpha

    # 计算变换后的图形和特征向量
    transformed = current_A @ circle
    transformed_vec1 = current_A @ eigenvectors[:, 0]
    transformed_vec2 = current_A @ eigenvectors[:, 1]

    # 更新变换后的图形
    transformed_circle.set_data(transformed[0], transformed[1])
    transformed_i.set_data([0, current_A[0, 0]], [0, current_A[1, 0]])
    transformed_j.set_data([0, current_A[0, 1]], [0, current_A[1, 1]])
    transformed_eigenvec1.set_data([0, transformed_vec1[0]], [0, transformed_vec1[1]])
    transformed_eigenvec2.set_data([0, transformed_vec2[0]], [0, transformed_vec2[1]])

    return (
        transformed_circle,
        transformed_i,
        transformed_j,
        transformed_eigenvec1,
        transformed_eigenvec2,
    )


# 创建动画
ani = FuncAnimation(fig, update, frames=100, interval=50, blit=True)

# 保存为GIF
ani.save("matrix_transform.gif", writer="pillow", fps=20)

plt.close()
print("GIF动画已保存为 matrix_transform.gif")
