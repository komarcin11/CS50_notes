## CS50 PYTHON CODE
## in terminal if you want to run a python code you write // python <filename>.py
name = input("what is your name?: ")
print(f"hello, {name}") 

## needs more work and checking
## spellcheck.py
words = set()

def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        words.add(line)
    file.close()# that should be close(file)
    return True

def size():
    return len(words)

def unload():
    return True 


##mario.py
from cs50 import get_int
def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        try:  ## here is a posibylytie of a ValueError if user will input str and the type cast wont work
            n = int(input("height: "))
            if n >0:
                return n
        except ValueError:
            print("Not an number try again")
        
main()

##meow.py
print("meow " * 3)

