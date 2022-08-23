# Guess the number game  -- Μάντεψε τον αριθμό

import random

guessesTaken = 0
print('Hello! What is your name? ', end='')

myName = input()
number = random.randint(1, 20)

#Αν θες να κλέψεις βγάλε το σχόλιο από την παρακάτω γραμμή :)
#print (number)

print('Well, ' + myName + ', I am thinking of a number between 1 and 20.')

while guessesTaken < 6:
    # Υπάρχουν 4 κενά πριν από την παρακάτω print 
    print('Take a guess: ',end='') 
    guess = input()
    guess = int(guess)

    guessesTaken = guessesTaken + 1

    # Υπάρχουν 8 κενά πριν από τις παρακάτω print & break -- Γιατί;
    if guess < number:    
        print('Your guess is too low.')

    if guess > number:
        print('Your guess is too high.')

    if guess == number:
        guessesTaken = str(guessesTaken)
        print('Good job, ' + myName + '! You guessed my number in ' + guessesTaken + ' guesses!')
        break
else:
    number = str(number)
    print('Nope. The number I was thinking of was ' + number)
