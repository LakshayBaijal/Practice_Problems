import math
def calculate_eigenvalues(matrix: list[list[float|int]]) -> list[float]:

    a = matrix[0][0]
    b = matrix[0][1]
    c = matrix[1][0]
    d = matrix[1][1]

    T = a + d
    D = a * d - b * c

    Trace = T * T - 4 * D

    Lambda1 = (T + math.sqrt(Trace))/2
    Lambda2 = (T - math.sqrt(Trace))/2


	return sorted([Lambda1,Lambda2],reverse = True)
