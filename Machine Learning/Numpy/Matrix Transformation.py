import numpy as np

def transform_matrix(A: list[list[int|float]], T: list[list[int|float]], S: list[list[int|float]]) -> list[list[int|float]]:


    T_inverse = np.linalg.inv(T)

    Transform = np.dot(T_inverse, A)
    Transform = np.dot(Transform, S)


	return Transform
