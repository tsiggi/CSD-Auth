import copy


def pri(x):
    i = 1
    print()
    for k in x:
        if abs(k) < 1e-10:
            k = 0
        print("x"+str(i)+" = %.3f " % k)
        i += 1


def rerange(a, b, l, p, i):
    maximum = i
    for j in range(i, len(a)):
        if abs(a[j][i]) > abs(a[maximum][i]):
            maximum = j
    temp = a[i]
    a[i] = a[maximum]
    a[maximum] = temp
    temp = b[i]
    b[i] = b[maximum]
    b[maximum] = temp
    temp = l[i]
    l[i] = l[maximum]
    l[maximum] = temp
    temp = p[i]
    p[i] = p[maximum]
    p[maximum] = temp


def pa_lu(a, b):
    p = []
    u = copy.deepcopy(a)
    l = []
    for j in range(len(u)):
        p.append([0] * (len(a)))                                    # initialize P & L
        p[j][j] = 1
        l.append([0] * (len(a)))

    for k in range(0, len(u) - 1):
        # [x] [k]
        rerange(u, b, l, p, k)                                         # Creates the final P array
        for i in range(k + 1, len(u)):
            # [i] [x]
            l[i][k] = u[i][k] / u[k][k]                             # Creates the L array
            for x in range(len(u) - 1, k - 1, -1):
                # [i] [x]
                u[i][x] = u[i][x] - (u[k][x] * u[i][k]) / u[k][k]   # Creates the U array

    for j in range(len(u)):
        l[j][j] = 1                                                 # adds 1 in the main diagonal
    return p, a, l, u, b                                            # Returns the P,A,L,U arrays with PA=LU


def ly_z(l, z):
    y = [0] * (len(z))
    for i in range(len(l)):
        sum = 0
        for j in range(len(l)):
            if i != j:
                sum += l[i][j] * y[j]
        y[i] = (z[i] - sum) / l[i][i]
    return y


def ux_y(u, y):
    x = [0] * (len(y))
    for i in range(len(u)-1, -1, -1):
        sum = 0
        for j in range(len(u)):
            if i != j:
                sum += u[i][j] * x[j]
        x[i] = (y[i] - sum) / u[i][i]
    return x


def main():
    aep = []
    b1 = []
    n = int(input("Give the size of the array: "))
    for x in range(0, n):
        print("Δώσε την", x+1, "γραμμή του επαυξημένου: ", end="")
        o = list(map(float, input().split()))
        if len(o) == n + 1:
            b1.append(float(o[n]))
            o.pop(n)
            aep.append(o)

    p, a, l, u, z = pa_lu(aep, b1)
    y = ly_z(l, z)                                          # Βήμα 1 Λύνω το Ly = z (επιστρέφω τήν λίστα y)

    x = ux_y(u, y)                                          # Βήμα 2 Λύνω το Ux = y (επιστρέφω τήν λίστα x)
    pri(x)                                                  # Συνάρτηση που τυπώνει τις λύσεις


main()
