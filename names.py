import sys
names = ["bill", "charlie", "fred", "george", "ginny"]

name = input("Name: ")

for n in names:
    if name == n:
        print("Found")
        sys.exit(0)
print("not found")
sys.exit(1)

## shorter version of the above program 

import sys
names = ["bill", "charlie", "fred", "george", "ginny"]

name = input("Name: ")

if n in names:
    print("Found")
    sys.exit(0)
print("not found")
sys.exit(1)
