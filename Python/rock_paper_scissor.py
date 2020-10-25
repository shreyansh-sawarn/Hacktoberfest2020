import random


def call():
    print("Choose \n")
    x = int(input("1. Rock\n2. Papper\n3. Sessior\n4. Exit\n"))
    rand = random.randint(1, 3)
    gen(rand, x)


def gen(rand, x):
    if(rand == x):
        print("Draw")
        call()
    elif(rand == 1 and x == 2):
        print("You Win")
        call()
    elif(rand == 1 and x == 3):
        print("Computer Win")
        call()
    elif(rand == 2 and x == 1):
        print("Computer Win")
        call()
    elif(rand == 2 and x == 3):
        print("You Win")
        call()
    elif(rand == 3 and x == 1):
        print("Computer Win")
        call()
    elif(rand == 3 and x == 2):
        print("You Win")
        call()
    elif(x == 4):
         exit


call()