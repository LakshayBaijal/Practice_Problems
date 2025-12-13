import numpy as np
def calculate_eigenvalues(matrix: list[list[float|int]]) -> list[float]:
	
    eigen = np.linalg.eigvals(matrix)
    
    return sorted(eigen.tolist(),reverse = True)
