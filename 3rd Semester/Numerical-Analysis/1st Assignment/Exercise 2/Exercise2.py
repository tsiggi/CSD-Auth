from random import random


def f(x):
    return 54*pow(x, 6) + 45*pow(x, 5) - 102*pow(x, 4) - 69*pow(x, 3) + 35*pow(x, 2) + 16*x - 4


def f_1(x):
    return 54*6*pow(x, 5) + 45*5*pow(x, 4) - 102*4*pow(x, 3) - 69*3*pow(x, 2) + 35*2*x + 16


def f_2(x):
    return 54*6*5*pow(x, 4) + 45*5*4*pow(x, 3) - 102*4*3*pow(x, 2) - 69*3*2*x + 35*2


def changed_dixotomisi(x, y):
    print("[" + str(x) + "," + str(y) + "] ", end=" ")
    i = 1
    while True:
        rand = float(y-x) * random() + x
        if abs(f(rand)) < 0.5e-5:
            print("Η ρίζα είναι : %.10f" % round(rand, 10), " και χρειάστηκαν %d" % i, " επαναλήψεις")
            break
        if f(x) * f(rand) < 0:
            y = rand
        else:
            if f(rand) * f(y) < 0:
                x = rand
        i += 1


def changed_newton_raphson(x, y):
    print("[" + str(x) + "," + str(y) + "] ", end=" ")
    if f_2(x) * f(x) > 0:
        y = x
    i = 1
    while True:
        xn = y - 1 / ((f_1(y) / f(y)) - (f_2(y)/(2*f_1(y))))
        y = xn
        if abs(f(xn)) < 0.5e-5:
            print("Η ρίζα είναι : %.10f" % round(xn, 10), " και χρειάστηκαν %d" % i, " επαναλήψεις")
            break
        i += 1


def changed_temnousa(xn, xn2):
    print("["+str(xn)+","+str(xn2)+"] ", end=" ")
    i = 1
    xn1 = (xn+xn2)/2     # δλδ το xn+1 είναι το μέσο του xn και του xn+2
    while True:
        q = f(xn)/f(xn1)
        r = f(xn2)/f(xn1)
        s = f(xn2)/f(xn)
        temp = xn2 - (r * (r - q) * (xn2 - xn1) + (1 - r) * s * (xn2 - xn)) / ((q - 1) * (r - 1) * (s - 1))
        xn = xn1
        xn1 = xn2
        xn2 = temp
        if abs(f(temp)) < 0.5e-5:
            print("Η ρίζα είναι : %.10f" % round(temp, 10), " και χρειάστηκαν %d" % i, " επαναλήψεις")
            break
        i += 1


print("Μέθοδος Διχοτόμησης :")
changed_dixotomisi(-2, -1)                                        # όπου 0,3 το διάστημα που θα γίνει η δοχοτόμηση
changed_dixotomisi(-1, 0)
changed_dixotomisi(0, 0.25)
changed_dixotomisi(0.25, 1)
changed_dixotomisi(1, 2)
print()

print("Newton - Raphson    :")
changed_newton_raphson(-2, -1)
changed_newton_raphson(-1, 0)
changed_newton_raphson(0, 0.25)
changed_newton_raphson(0.25, 0.75)
changed_newton_raphson(1, 2)
print()

print("Μέθοδος Τέμνουσας   :")
changed_temnousa(-1.5, -1.2)
changed_temnousa(-1, 0)
changed_temnousa(0, 0.25)
changed_temnousa(0.25, 0.8)
changed_temnousa(1, 2)
print()

print("End of the Program!", end="")
