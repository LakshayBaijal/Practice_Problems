import numpy as np
def matrixmul(a:list[list[int|float]],
              b:list[list[int|float]])-> list[list[int|float]]:

                a_row = len(a)
                a_col = len(a[0])

                b_row = len(b)
                b_col = len(b[0])

                if b_row == a_col:
                    c = np.dot(a,b)
                else:
                    return -1
                
                

	            return c
