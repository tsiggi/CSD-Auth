import math


def trapezioy():
    sum1 = 0.0
    for i in x:
        if i == 0 or i == math.pi/2:
            sum1 += math.sin(i)
        else:
            sum1 += 2 * math.sin(i)
    return (x[-1] - x[0]) * sum1 / (2*10)


def sfalma_trapezioy():
    maxf__ = 1          # Max |f''(x)| = |-sin(π/2)| = 1 , [0,π/2] με f''= -sin(x)
    temp = (x[-1] - x[0])*(x[-1] - x[0])*(x[-1] - x[0])
    return (temp/(12*10*10)) * maxf__


def simpson():
    sum1 = 0.0
    k = 0
    for i in x:
        if i == 0 or i == math.pi/2:
            sum1 += math.sin(i)
        else:
            if k % 2 == 0:
                sum1 += 2 * math.sin(i)
            else:
                sum1 += 4 * math.sin(i)
        k += 1
    return ((x[-1] - x[0]) / (3*10)) * sum1


def sfalma_simpson():
    maxf__ = 1          # Max |f''''(x)| = sin(π/2) = 1 , [0,π/2] με f''''= sin(x)
    temp = (x[-1] - x[0])*(x[-1] - x[0])*(x[-1] - x[0])*(x[-1] - x[0])*(x[-1] - x[0])
    return (temp/(180*10*10*10*10)) * maxf__


x = []
y = []
for j in range(0, 11):
    x.append(j*math.pi/20)
    y.append(math.sin(x[j]))

print("\nΜέθοδος Τραπεζίου:")
print("     Το ολοκλήρωμα της συνάρτησης του ημίτονου στο διάστημα [0,π/2]  είναι: ", trapezioy())
print("     Το σφάλμα προσέγγισης αριθμητικά είναι :", abs(1 - trapezioy()))  # f=sin(x) , f'=cos(x)
print("     Το σφάλμα προσέγγισης θεωρητικά  είναι :", sfalma_trapezioy())
print("\nΜέθοδος Simpson:")
print("     Το ολοκλήρωμα της συνάρτησης του ημίτονου στο διάστημα [0,π/2]  είναι: ", simpson())
print("     Το σφάλμα προσέγγισης αριθμητικά είναι : "+"%.19f" % abs(1 - simpson()))  # f=sin(x) , f'=cos(x)
print("     Το σφάλμα προσέγγισης θεωρητικά  είναι : "+"%.19f" % sfalma_simpson())
