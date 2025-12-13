import numpy as np
def solve_jacobi(A: np.ndarray, b: np.ndarray, n: int) -> list:

	row = len(A)
	x = [0.0]*row

	col = len(A[0])

	for k in range(n):
		x_new = [0.0] * row

		for i in range(row):
			s = 0.0
			for j in range(col):
				if i != j:
					s += A[i][j] * x[j]

			x_new[i] = (b[i] - s) / A[i][i]
		
		x = x_new


	return x
