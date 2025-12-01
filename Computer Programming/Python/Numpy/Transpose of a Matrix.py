def transpose_matrix(a: list[list[int|float]]) -> list[list[int|float]]:

    row = len(a)
    col = len(a[0])

    result = []

    for i in range(col):
        new_row = []
        for j in range(row):

            new_row.append(a[j][i])

        result.append(new_row)

	return result
