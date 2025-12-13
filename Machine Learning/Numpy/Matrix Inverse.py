import numpy as np

def inverse_2x2(matrix: list[list[float]]) -> list[list[float]]:

    try:
        matrix_inverse = np.linalg.inv(matrix)

    except np.linalg.LinAlgError:
        return -1

	return matrix_inverse
