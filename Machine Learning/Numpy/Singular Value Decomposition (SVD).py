import numpy as np 
 def svd_2x2_singular_values(A: np.ndarray) -> tuple:
    U, S, V_T = np.linalg.svd(A)

    print("U:\n", U)
    print("Singular values:", S)
    print("V^T:\n", V_T)

    return U,S,V_T
