def printAB(a, b):
    l = 0
    print()
    print("O επαυξημένος πίνακας Α|Β :")
    for i in a:
        print("[", end="")
        for k in i:
            if abs(k) < 1e-10:
                k = 0
            print(" %.3f " % k, end="")
        if abs(b[l]) < 1e-10:
            b[l] = 0
        print("|%.3f ]" % b[l])
        l += 1
    print()


def print_result(x):
    i = 1
    print("Με ρίζες : ")
    for k in x:
        if abs(k) < 1e-15:
            k = 0
        print("x"+str(i)+" =", k)
        i += 1
    print()


def initialize_a(n):
    A = [[0] * n for i in range(n)]
    for i in range(n):
        if i + 1 < n:
            A[i+1][i] = -2
            A[i][i+1] = -2
        A[i][i] = 5
    return A


def initialize_b(n):
    B = [1] * n
    B[0] = 3
    B[-1] = 3
    return B


def find(a, b, x):
    norma = a[0][0] * x[0] + a[0][1] * x[1] - b[0]
    n = len(a)

    for i in range(1, n):
        temp = 0
        temp += a[i][i - 1] * x[i - 1] + a[i][i] * x[i]
        if i + 1 < n:
            temp += a[i][i + 1] * x[i + 1]

        temp -= b[i]
        norma = max(abs(norma), abs(temp))

    if abs(norma) >= 0.5e-4:
        return True
    else:
        return False


def sumForCholesky(a, i, x0, xn):
    s = 0
    if i - 1 >= 0:
        s += a[i][i-1] * xn[i-1]
    if i + 1 < len(a):
        s += a[i][i+1] * x0[i+1]
    return s


def gauss_seidel(a, b):
    x0 = [0] * len(a)
    xn = [0] * len(a)
    flag = True
    counter = 0

    while flag:
        for i in range(0, len(a)):
            athrisma = sumForCholesky(a, i, x0, xn)
            xn[i] = (b[i] - athrisma) / a[i][i]
        counter += 1
        flag = find(a, b, xn)
        for i in range(0, len(a)):
            x0[i] = xn[i]

    print("Χρειάστηκαν", counter, "Επαναλήψεις ")
    return x0


a10 = initialize_a(10)                          # Αρχικοποιεί τον πίνακα Α10 (10x10) στοιχεία
b10 = initialize_b(10)                          # Αρχικοποιεί τον πίνακα Β10 (10) στοιχεία
a10000 = initialize_a(10000)                    # Αρχικοποιεί τον πίνακα Α10000 (10000x10000)
b10000 = initialize_b(10000)

print("Για n=10 : ")
# printAB(a10, b10)                             # Τυπώνει τον επαυξημένο πίνακα
x10 = gauss_seidel(a10, b10)                    # Κάνει Gauss_Seidel και επιστρέφει έναν πίνακα με τις ρίζες
# Η συνάρτηση Gauss_Seidel πριν ολοκληρωθεί τυπώνει τον αριθμό των επαναλήψεων που χρειάστηκαν
print_result(x10)                               # τυπώνει τον πίνακα με τις ρίζες

print("Για n=10000 : ")
gauss_seidel(a10000, b10000)                    # Παρόμοια με επάνω
# εδώ δεν τυπώνουμε τον πίνακα καθώς είναι πολύ μεγάλος

print()
print("End of program", end="")
