def matrix_scale(mat,num):
    ''' (matrix, num) -> (matrix)

    Return mat with each element multiplied by num
    '''
    for row in range(len(mat)):
        for column in range(len(mat[row])):
            mat[row][column] *= num
    return mat

def matrix_sum(mat1, mat2):
    ''' (matrix, matrix) -> (matrix)

    Return mat3 as a summation of the elements of mat1 and mat2
    '''
    mat3 = mat1
    for row in range(len(mat1)):
        for column in range (len(mat1[row])):
            mat3[row][column] = mat1[row][column] + mat2[row][column]
    return mat3

def matrix_sym(mat):
    ''' (matrix) -> (boolean) or None

    Check and return whether the matrix is symmetrical (same as transpose)
    '''
    if len(mat) != len(mat[0]):
        return None
    for i in range(len(mat)):
        list1 = []
        for j in range(len(mat)):
            list1.append(mat[j][i])
        if list1 != mat[i]:
             return None
    return True

def matrix_mul(mat1, mat2):
    ''' (matrix, matrix) -> matrix

    Return mat3 as a matrix multiplication of mat1 and mat2
    '''
    mat3 = [0]*len(mat1)
    for h in range(len(mat1)):
        mat3[h] = [0]*len(mat2[0])

    if len(mat1[0]) != len(mat2):    # Check mat1 column dimension
        return None                  # equals mat2 row dimension

    for i in range(len(mat1)):
        for j in range(len(mat2[0])):
            for k in range(len(mat2)):
                mat3[i][j] += mat1[i][k] * mat2[k][j]
    return mat3

def column_sum_square(mat):
    ''' (matrix) -> list

    Return list of which the elements are composed of the sum of the squares
    of each element in the columns of the matrix
    '''
    list = [0] * len(mat[0])
    for row in range(len(mat)):
        for column in range(len(mat[row])):
            list[column] += mat[row][column]**2
    return list
