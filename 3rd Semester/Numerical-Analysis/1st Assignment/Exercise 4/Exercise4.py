n = 15
q = 0.15


def initialize_a():
    a = [[0] * n for i in range(n)]
    a[0][1] = a[0][8] = a[1][2] = a[1][4] = a[1][6] = a[2][1] = a[2][5] = a[2][7] = a[3][2] = a[3][11] = 1
    a[4][0] = a[4][9] = a[5][9] = a[5][10] = a[6][9] = a[6][10] = a[7][3] = a[7][10] = a[8][4] = a[8][5] = 1
    a[8][9] = a[9][12] = a[10][14] = a[11][6] = a[11][7] = a[11][10] = a[12][8] = a[12][13] = a[13][9] = 1
    a[13][10] = a[13][12] = a[13][14] = a[14][11] = a[14][13] = 1
    return a


def print_array(p):
    print("     p= [", end="")
    n = len(p)
    for i in range(n-1):
        print("%.5f" % round(p[i], 5), end=", ")
    print("%.5f" % round(p[-1], 5), end="]\n\n")


def athrisma_i_grammhs(a, i):
    athrisma = 0
    n = len(a)
    for j in range(n):
        athrisma += a[i][j]
    return athrisma


def methodos_dynamewn(G):
    b0 = [G[i][0] for i in range(len(G))]
    b1 = [0]*len(G)
    for k in range(2*len(G)):
        for i in range(len(G)):
            b1[i] = 0
            for j in range(len(G)):
                b1[i] += b0[j] * G[i][j]
        if k < 2*len(G)-1:
            temp = b1[0]
        else:
            temp = sum(b1)
        for j in range(len(G)):
            b1[j] /= temp
            b0[j] = b1[j]
    return b1


def create_g(A):
    n = len(A)
    G = [[0.0] * n for i in range(n)]
    for j in range(n):
        for i in range(n):
            G[i][j] = q / n + A[j][i] * (1 - q) / athrisma_i_grammhs(A, j)
    return G


a = initialize_a()
g = create_g(a)      # Δημιουργεί τον πίνακα Google


print("1.Το άθροισμα κάθε στήλης του πίνακα G(oogle) : ")
for j in range(n):
    temp = sum(g[i][j] for i in range(n))           # επιστρέφει το άθροισμα της στήλης j και το τυπώνει αποδεικνύοντας
    print("     Άθροισμα στήλης", j+1, "=",  temp)  # έτσι ότι ο G είναι στοχαστικός και ειδικότερα
    # είναι αριστερά στοχαστικός


print("2.Το κανονικοποιημένο ιδιοδιάνυσμα της μέγιστης ιδιοτιμής: ", end="\n\n")
p = methodos_dynamewn(g)        # κάνω τήν μέθοδο της δυνάμεως και επιστρέφω το ιδιοδιάνυσμα
print_array(p)                  # τυπώνω το ιδιοδιάνυσμα


print("3.Αλλαγή πίνακα Α για βελτίωση της 1ης σελίδας με νέo ιδιοδιάνυσμα: ", end="\n\n")
a[0][7] = 0         # Αφαιρώ 1 σύνδεση
a[9][0] = 1         # Προσθέτω 4 συνδέσεις
a[10][0] = 1
a[12][0] = 1        # προσθαφαιρέσεις για να βελτιώσω τον βαθμό σημαντικότητας της 1ης ιστοσελίδας
a[14][0] = 1
g = create_g(a)     # Δημιουργώ τον νέο πίνακα Google
p = methodos_dynamewn(g)        # κάνω τήν μέθοδο της δυνάμεως και επιστρέφω το ιδιοδιάνυσμα για τον νέο πίνακα
print_array(p)                  # τυπώνω το νέο ιδιοδιάνυσμα


print("4.Αλλαγή της πιθανότητας μεταπήδηδης: ", end="\n\n")
print("   (a) Για q = 0.02: ")
q = 0.02
g = create_g(a)                 # δημιουργεί τον πίνακα Google για τήν νέα πιθανότητα μεταπήδησης
p = methodos_dynamewn(g)        # κάνει τήν μέθοδο της δυνάμεως για τον νέο πίνακα Google
print_array(p)                  # τυπώνει το νέο ιδιοδιάνυσμα

print("   (a) Για q = 0.6: ")
q = 0.6
g = create_g(a)                 # παρόμοια με πάνω
p = methodos_dynamewn(g)
print_array(p)
# Ο σκοπός της πιθανότητας μεταπήδησης είναι για να δείξει πόσο εύκολα μπορώ να μεταβώ απο μία σελίδα σε μία
# άλλη. Όσο πιο μεγάλη είναι η πιθανότητα αυτή τόσο μικραίνουν οι διαφορές σημαντικότητας των ιστοσελίδων
# και όσο μικραίνει τόσο αυξάνονται οι διαφορές στην τάξη των σελίδων.


print("5.Αλλαγή της σύνδεσης της ιστοσελίδας 11 με καλύτερο τρόπο: ")
q = 0.15
a = initialize_a()              # αρχικός πίνακας
print("     Απλή σύνδεση:")
g = create_g(a)
p = methodos_dynamewn(g)        # κάνω τήν μέθοδο της δυνάμεως και επιστρέφω το ιδιοδιάνυσμα
print_array(p)
print("     Καλύτερη σύνδεση:")
a[8][11] = 3
a[12][11] = 3
g = create_g(a)
p = methodos_dynamewn(g)        # κάνω τήν μέθοδο της δυνάμεως και επιστρέφω το ιδιοδιάνυσμα
print_array(p)
# Όπως παρατηρούμε δουλεύει δλδ αυξάνει τήν σημαντικότητα της 11 και μειώνει της 10
# Αυξάνει όμως και τήν σημαντικότητας της 12 & 14 & 8


print("6.Διαγραφή της σελίδας 10 απο το γράφημα: ")
print("     Πριν την διαγραφή της ιστοσελίδας 10:")
a = initialize_a()
g = create_g(a)
p = methodos_dynamewn(g)
print_array(p)

print("     Μετά την διαγραφή της ιστοσελίδας 10:")
a = [[0] * 14 for i in range(14)]
a[0][1] = a[0][8] = a[1][2] = a[1][4] = a[1][6] = a[2][1] = a[2][5] = a[2][7] = a[3][2] = a[3][10] = 1
a[4][0] = a[4][9] = a[5][9] = a[6][9] = a[7][3] = a[8][4] = a[8][5] = 1
a[8][9] = a[9][11] = a[10][6] = a[10][7] = a[11][8] = a[11][12] = a[12][9] = 1
a[12][11] = a[12][13] = a[13][10] = a[13][12] = 1
g = create_g(a)
p = methodos_dynamewn(g)
print_array(p)

print("End of the Program!", end="")