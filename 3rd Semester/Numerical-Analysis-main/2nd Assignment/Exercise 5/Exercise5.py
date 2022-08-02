import matplotlib.pyplot as plt
import math


def lagrange(k):         # Συνάρτηση που προσομοιάζει τον υπολογισμό του ημίτονου(k)
    pn = 0
    for i in range(len(xn)):
        li = 1
        for j in range(len(yn)):
            if i != j:
                li *= (k - xn[j]) / (xn[i] - xn[j])
        pn += li*yn[i]
    return pn


def find(a, b, x):
    norma = 0
    n = len(a)

    for i in range(0, n):
        temp = 0
        for j in range(n):
            temp += a[i][j] * x[j]
        temp -= b[i]
        norma = max(abs(norma), abs(temp))

    if abs(norma) >= 0.5e-4:
        return True
    else:
        return False


def gauss_seidel(a, b):
    x0 = [0] * len(a)
    xn = [0] * len(a)
    flag = True
    counter = 0
    while flag:
        for i in range(0, len(a)):
            athrisma = 0
            for j in range(len(a)):
                if i != j:
                    athrisma += a[i][j]*xn[j]
            xn[i] = (b[i] - athrisma) / a[i][i]
        counter += 1
        flag = find(a, b, xn)
        for i in range(0, len(a)):
            x0[i] = xn[i]
    return x0


def Splines(x_values, y_values):
    n = len(x_values)
    dy = [0.0] * (n - 1)
    h = [0.0] * (n - 1)
    A = [[0.0]*n for i in range(n)]
    A[0][0] = 1
    A[-1][-1] = 1
    alpha = [0.0] * n
    # οι άγνωστοι που ψάχνουμε
    d = [0.0] * n
    c = [0.0] * n
    b = [0.0] * n
    for i in range(n - 1):
        h[i] = x_values[i + 1] - x_values[i]
        dy[i] = y_values[i + 1] - y_values[i]
    for i in range(1, n - 1):
        A[i][i] = 2 * (h[i-1] + h[i])
        A[i][i + 1] = h[i]
        A[i][i - 1] = h[i - 1]
        alpha[i] = 3*(dy[i] / h[i]) - 3*(dy[i-1] / h[i - 1])
    # Λύση του συστήματος
    c = gauss_seidel(A, alpha)
    # Βρίσκουμε και τους αγνώστους b, d με βάση το c
    for j in range(n - 2, -1, -1):
        b[j] = dy[j] / h[j] - h[j] * (2 * c[j] + c[j + 1]) / 3
        d[j] = (c[j + 1] - c[j]) / (3 * h[j])
    # επιστρέφει τους πίνακες με τις σταθερές που βρήκαμε
    return d, c, b, y_values


def Spline_x(x):
    # Γυρνάμε τήν λύση για το x που εισάχθηκε
    for i in range(len(xn) - 1):
        if xn[i] <= x <= xn[i + 1]:
            return d[i] + c[i] * (x - xn[i]) + b[i] * (x - xn[i]) ** 2 + a[i] * (x - xn[i]) ** 3


def AT(A):
    a = []
    for j in range(len(A[0])):
        a.append([])
        for i in range(len(A)):
            a[j].append(A[i][j])
    return a


def initializeA_B(x, y, n):
    A = [[1.0]*(n-1) for i in range(len(x))]
    B = []
    for i in range(0, len(x)):
        for j in range(1, n-1):
            A[i][j] = x[i] ** j
        B.append(y[i])
    return A, B


def ginomeno(AT, A):
    n = len(AT)
    m = len(A)
    if len(AT) != len(A[0]) or len(A) != len(AT[0]):
        print("Λάθος πολλαπλασιασμός πινάκων (Μέγεθος)")
        return

    gin = [[0.0]*n for i in range(n)]
    for i in range(0, n):
        for j in range(0, n):
            gin[i][j] = 0
            for k in range(0, m):
                gin[i][j] += AT[i][k] * A[k][j]
    return gin


def ginomeno_B(AT, B):
    if len(AT[0]) != len(B):
        print("Λάθος πολλαπλασιασμός πινάκων (Μέγεθος)")
        return
    gin = [0.0 for i in range(len(AT))]
    for i in range(0, len(AT)):
        gin[i] = 0.0
        for j in range(0, len(AT[0])):
            gin[i] += AT[i][j] * B[j]
    return gin


def Elaxista_Tetragvna(xn, yn, i):
    a, b = initializeA_B(xn, yn, i+2)
    at = AT(a)
    gin1 = ginomeno(at, a)
    gin2 = ginomeno_B(at, b)
    return gauss_seidel(gin1, gin2)


def Elaxista_Tetragvna_x(a, x):
    # Γυρνάμε τήν λύση για το x που εισάχθηκε
    temp = 0
    for i in range(len(a)):
        temp += a[i] * x**i
    return temp


# Πίνακες που χρησιμοποιούνται και μέσα στις συναρτήσεις
xn = [-math.pi, -3*math.pi/4, -math.pi/2, -math.pi/3, -math.pi/6, 0, math.pi/4, math.pi/2, 3*math.pi/4, math.pi]
yn = [0, -0.70710678, -1, -1*math.sqrt(3)/2, -1/2, 0, math.sqrt(2)/2, 1, 0.70710678, 0]
a, b, c, d = Splines(xn, yn)
statheres_Elaxistvn = Elaxista_Tetragvna(xn, yn, 8)   # 8ου βαθμού πολυώνυμο


# Ερώτημα για τα σφάλματα των μεθόδων
x = []
y = []
y1 = []
y2 = []
y3 = []
test = -math.pi
while test <= math.pi:
    x.append(test)
    y.append(math.sin(test))
    y1.append(abs(abs(math.sin(test))-abs(lagrange(test))))
    y2.append(abs(abs(math.sin(test))-abs(Spline_x(test))))
    y3.append(abs(abs(math.sin(test))-abs(Elaxista_Tetragvna_x(statheres_Elaxistvn, test))))
    test += math.pi/99.5

plt.plot(x, y1, label="Error με Lagrange")
plt.plot(x, y2, label="Error με Splines")
plt.plot(x, y3, label="Error με Ελάχιστα τετράγωνα")
plt.xlabel('Τιμές απο [-π,π]')
plt.ylabel('Σφάλμα')
plt.title('Τα σφάλματα για τις προσεγγίσεις!')
plt.legend()

plt.savefig('Errors.png')
plt.show()





