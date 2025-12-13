import numpy as np

def linear_regression_gradient_descent(X: np.ndarray, y: np.ndarray, alpha: float, iterations: int) -> np.ndarray:
	"""
	Perform linear regression using gradient descent.

	m = number of training examples
	n = number of parameters (features), technically n-1 features, 1st column is for intercept

	X: shape (m, n), `m` training examples with `n` input values for each feature
	y: shape (m, 1) array with the target values (ground truth)
	alpha: learning rate
	iterations: number of gradient descent steps
	"""

	m, n = X.shape
	y = y.reshape(-1, 1) 	# Make sure y is a column vector
	theta = np.zeros((n, 1))

	X_transpose = X.T

	for _ in range(iterations):
		
		a = np.dot(X_transpose,X)
		a = np.dot(a,theta)

		b = np.dot(X_transpose,y)
		minus = a - b
		c = np.dot(alpha,minus)
		c = c / m
		theta = theta - c


	

	# TODO: Your code here

	return np.round(theta.flatten(), 4) 	# Rounded to 4 decimals
