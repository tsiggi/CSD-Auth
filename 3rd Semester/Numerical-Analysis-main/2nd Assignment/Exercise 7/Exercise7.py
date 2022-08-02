import matplotlib.pyplot as plt
import math


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


def AT(A):
    a = []
    for j in range(len(A[0])):
        a.append([])
        for i in range(len(A)):
            a[j].append(A[i][j])
    return a


def initializeA_B(x, y, n):
    A = [[1.0]*n for i in range(len(x))]
    B = []
    for i in range(0, len(x)):
        for j in range(1, n):
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
    a, b = initializeA_B(xn, yn, i+1)
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


def forPlot(prosegish, day):
    temp = []
    for i in day:
        temp.append(Elaxista_Tetragvna_x(prosegish, i))
    return temp


def PlotSOL():
    d = [1, 4, 8, 11, 15, 19, 23, 27, 29, 32, 34, 38]
    plt.plot(d, [4.61, 6.43, 7.88, 9.22, 8.86, 11.47, 15.20, 13.20, 14.96, 13.10, 13.04, 14.23], label="SOL_USD")
    plt.plot(d, forPlot(solana2, d), label="SOL_USD Προσέγγιση 2ου βαθμού")
    plt.plot(d, forPlot(solana3, d), label="SOL_USD Προσέγγιση 3ου βαθμού")
    plt.plot(d, forPlot(solana4, d), label="SOL_USD Προσέγγιση 4ου βαθμού")
    plt.xlabel('Days')
    plt.ylabel('Price')
    plt.title('Price of Solana from 1 Feb - 10 Mar')
    plt.legend()
    plt.savefig('SOL_USD.png')
    plt.show()


def PlotETH():
    d = [1, 4, 8, 11, 15, 19, 23, 27, 29, 32, 34, 38]
    plt.plot(d, [1369.04, 1594.76, 1746.62, 1783.80, 1779.79, 1960.16, 1570.20, 1459.97, 1564.71, 1541.91, 1654.74,
                 1799.17], label="ETH_USD")
    plt.plot(d, forPlot(ethereum2, d), label="ETH_USD Προσέγγιση 2ου βαθμού")
    plt.plot(d, forPlot(ethereum3, d), label="ETH_USD Προσέγγιση 3ου βαθμού")
    plt.plot(d, forPlot(ethereum4, d), label="ETH_USD Προσέγγιση 4ου βαθμού")
    plt.xlabel('Days')
    plt.ylabel('Price')
    plt.title('Price of Ethereum from 1 Feb - 10 Mar')
    plt.legend()
    plt.savefig('Eth_USD.png')
    plt.show()


# οι Ημέρες (1=1 Feb,4=4Feb,...27=27 Feb,29=1 Mar,32=4 Mar,...)
days = [1, 4, 8, 11, 15, 19, 23, 27, 29, 32]
# ETH price for the days above
ETH_USD = [1369.04, 1594.76, 1746.62, 1783.80, 1779.79, 1960.16, 1570.20, 1459.97, 1564.71, 1541.91]
# SOL price for the days above
SOL_USD = [4.61, 6.43, 7.88, 9.22, 8.86, 11.47, 15.20, 13.20, 14.96, 13.10]
ethereum2 = Elaxista_Tetragvna(days, ETH_USD, 2)
ethereum3 = Elaxista_Tetragvna(days, ETH_USD, 3)
ethereum4 = Elaxista_Tetragvna(days, ETH_USD, 4)
solana2 = Elaxista_Tetragvna(days, SOL_USD, 2)
solana3 = Elaxista_Tetragvna(days, SOL_USD, 3)
solana4 = Elaxista_Tetragvna(days, SOL_USD, 4)

print("Προσεγγίσεις με την μέθοδο ελάχιστων τετραγώνων:\n Η τιμή του Ethereum στις 6 Μαρτίου: 1654.74")
print("     Προσέγγιση με πολυώνυμο 2ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(ethereum2, 34))
print("     Προσέγγιση με πολυώνυμο 3ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(ethereum3, 34))
print("     Προσέγγιση με πολυώνυμο 4ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(ethereum4, 34))
print(" Η τιμή του Solana στις 6 Μαρτίου: 13.04")
print("     Προσέγγιση με πολυώνυμο 2ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(solana2, 34))
print("     Προσέγγιση με πολυώνυμο 3ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(solana3, 34))
print("     Προσέγγιση με πολυώνυμο 4ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(solana4, 34))

print("\n Η τιμή του Ethereum στις 10 Μαρτίου: 1799.17")
print("     Προσέγγιση με πολυώνυμο 2ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(ethereum2, 38))
print("     Προσέγγιση με πολυώνυμο 3ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(ethereum3, 38))
print("     Προσέγγιση με πολυώνυμο 4ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(ethereum4, 38))
print(" Η τιμή του Solana στις 10 Μαρτίου: 14.23")
print("     Προσέγγιση με πολυώνυμο 2ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(solana2, 38))
print("     Προσέγγιση με πολυώνυμο 3ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(solana3, 38))
print("     Προσέγγιση με πολυώνυμο 4ου βαθμού: "+"%f" % Elaxista_Tetragvna_x(solana4, 38))

# PlotSOL()         # Συναρτήσεις που τυπώνουν τις γραφικές παραστάσεις
# PlotETH()         # SOS: Μπορεί να χρησιμοποιηθεί μια τη φορά
