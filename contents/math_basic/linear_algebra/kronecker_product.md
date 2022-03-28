# Kronecker积

> [!TIP] [数学概念] https://mathworld.wolfram.com/KroneckerProduct.html

## Numpy实现

使用Numpy的Broadcast机制可以进行加速运算：

```python
A = np.random.random((50,50))
B = np.random.random((50,50))
print(((A[:,None,:,None]*B[None,:,None,:]).reshape(2500,2500) == np.kron(A,B)).all())
```

结果反馈为：

```python
True
```