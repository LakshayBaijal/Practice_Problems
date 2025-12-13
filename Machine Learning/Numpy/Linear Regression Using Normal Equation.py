import numpy as np
def linear_regression_normal_equation(X: list[list[float]], y: list[float]) -> list[float]:
	# Your code here, make sure to round

    X = np.array(X)
    Y = np.array(y)
    X_Transpose = X.T

    a = np.dot(X_Transpose,X)
    a_inverse = np.linalg.inv(a)

    b = np.dot(X_Transpose,y)

    theta = np.dot(a_inverse,b)
	return theta
