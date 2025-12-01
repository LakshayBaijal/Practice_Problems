import numpy as np

a = [1, 2, 3]
b = [4, 5, 6]

total = 0
for i in range(len(a)):
    total += a[i] * b[i]

print(total)
