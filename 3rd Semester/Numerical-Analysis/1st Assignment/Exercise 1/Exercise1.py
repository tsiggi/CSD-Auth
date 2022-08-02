import math


def f(x):
    return 14 * x * math.exp(x-2) - 12 * math.exp(x-2) - 7 * pow(x, 3) + 20*pow(x, 2) - 26 * x + 12


def f_1(x):
    return 14 * x * math.exp(x-2) + 14 * math.exp(x-2) - 12 * math.exp(x-2) - 21 * pow(x, 2) + 40 * x - 26


def f_2(x):
    return 2 * 14 * math.exp(x-2) + 14 * x * math.exp(x-2) - 12 * math.exp(x-2) - 42 * x + 40


def dixotomisi(x, y):
    i = 1
    print("Διάστημα [%.1f," % x, "%.1f]" % y)
    while True:
        mid = (x + y)/2
        if abs(f(mid)) < 0.5e-5:
            print("Η ρίζα είναι : %.10f" % round(mid, 10), " και χρειάστηκαν %d" % i, " επαναλήψεις")
            # print(f(temp))
            break
        if f(x) * f(mid) < 0:
            y = mid
        else:
            if f(mid) * f(y) < 0:
                x = mid
        i += 1


def newton_raphson(x, y):
    print("Διάστημα [%.1f," % x, "%.1f]" % y)
    if f_2(x) * f(x) > 0:
        y = x
    i = 1
    while True:
        xn = y - f(y) / f_1(y)
        y = xn
        if abs(f(xn)) < 0.5e-5:
            print("Η ρίζα είναι : %.10f" % round(xn, 10), " και χρειάστηκαν %d" % i, " επαναλήψεις")
            # print(f(temp))
            break
        i += 1


def temnousa(x0, x1):
    print("Διάστημα [%.1f," % x0, "%.1f]" % x1)
    i = 1
    while True:
        temp = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0))
        x0 = x1
        x1 = temp
        if abs(f(temp)) < 0.5e-5:
            print("Η ρίζα είναι : %.10f" % round(temp, 10), " και χρειάστηκαν %d" % i, " επαναλήψεις")
            # print(f(temp))
            break
        i += 1


print("Μέθοδος Διχοτόμησης :")
dixotomisi(0, 1.5)              # όπου 0,1.5 το κατάλληλο διάστημα που θα γίνει η δοχοτόμηση για την εύρεση της ρίζας
dixotomisi(1.5, 3)              # όπου 1.5,3 για τήν δεύτερη ρίζα
print()
print("Newton - Raphson    :")
newton_raphson(0, 1.5)
newton_raphson(1.5, 3)
print()
print("Μέθοδος Τέμνουσας   :")
temnousa(0, 1.1)
temnousa(1.1, 3)
print()
print("End of the Program!", end="")
