import math


def pri(a):
    for i in a:
        print("[", end="")
        for k in i:
            y = round(k, 4)
            if abs(y) < 1e-10:
                y = 0
            print(" %.4f " % y, end="")
        print("]")
    print()


def sumForCholesky(l, k, i):
    athr = 0
    for j in range(i):
        athr += l[i][j] * l[k][j]
    return athr


def cholesky(A):
    l = [[0.0] * len(A) for i in range(len(A))]

    for k in range(len(A)):
        for i in range(k + 1):
            s = sumForCholesky(l, k, i)
            if i == k:
                l[k][i] = math.sqrt(A[i][i] - s)
            else:
                l[k][i] = ((A[k][i] - s) / l[i][i])

    return l


A = [[6, 15, 55], [15, 55, 225], [55, 225, 979]]                            # παράδειγμα 1 (3x3)
# A = [[6, 3, 4, 8], [3, 6, 5, 1], [4, 5, 10, 7], [8, 1, 7, 25]]            # παράδειγμα 2 (4x4)
L = cholesky(A)

print("A:")
pri(A)

print("L:")
pri(L)


