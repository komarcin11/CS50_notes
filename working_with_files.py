##WORKING WITH FILES (.CSV)

file = open('new.csv', 'r') # 'r' is opening the file in read mode
file = open('new.csv', 'w') # 'w' is a write mode and it will overwrite what was on the file
file = open('new.csv', 'a') # 'a' is append mode 
file = open('new.csv', 'wb')  #wb is combination of 'w' and 'b' so it is write binary mode
file = open('new.csv', 'r') 
file.close() # ALWAYS CLOSE THE FILE AFTER OPENING IT!!!

file = open('new.csv')
print(file.read(7)) # read method will read the file // the specified numer that signifies the nubmer of bytes that will be read 1 byte = 1 ASCII charecter  
print(file.read(6)) # second read will read the next bytes
print(file.read()) # if the read has not been given number of bytes i will read the rest of the file
file.close() # ALWAYS CLOSE THE FILE AFTER OPENING IT!!!

file = open('new.csv')
for line in file.readlines()[::-1]: # readlines will open the file and create a list that every other line is a separat element
    print(line,end="") #end="" is added so that there is no additional enter or \n bettwien the created elements
file.close() # ALWAYS CLOSE THE FILE AFTER OPENING IT!!!


file = open('new.csv')
for line in file: # if there is no need to create a list fo every other line you can just simple iterate
    print(line, end="") 
file.close() 

file = open('newfile.txt', 'w') #'w' mode will create a file and write in it or if there is a file it will overwrite it 
starter_line=file.write('This is a new file for an example\n') # \n means newline os it will create a new line after the string 
print(starter_line) #the .write method stores nmber of bytes writen in to the file
file.close()

file = open('newfile.txt', 'a') #'a' this is a append mode it will add at the end of the file 
file.write('and i added a new line \n')
file.close()

try:
    f = open('newfile.txt')
    print(f.read())
    print(type(f.read()))
finally:                        #if you dont want to remember to close the file you can add a finally:
    f.close()

with open('newfile.txt') as f: # the with is better becouse after the tasks in the code block are done the file will automaticly close
    print(f.read(),end="")


## working with CSV files open and append a element to a file
import csv
file = open("phonebook.csv", "a",newline='') # open a file in append mode and assign to a variable 

name = input("name: ") # ask for values
number = input ("number: ", end ="")

write = csv.writer(file) #assign a csv.writer() function
write.writerow([name,number]) # use writerow() method to write a row

file.close()

## with use of "with .... as"
import csv
with open("phonebook.csv", "a" ,newline='') as file: # open a file in append mode and assign to a variable 

    name = input("name: ") # ask for values
    number = input ("number: ")

    write = csv.writer(file) #assign a csv.writer() function
    write.writerow([name,number]) # use writerow() method to write a row

## modified so you can use a dictonary so the next code reader will understand
import csv
with open("phonebook.csv", "a" ,newline='') as file: # open a file in append mode and assign to a variable 

    name = input("name: ") # ask for values
    number = input ("number: ")

    write = csv.DictWriter(file, fieldnames=["name", "number"]) #here you create a dictionary writer insted of list
    write.writerow({"name":name, "number": number}) # here you assign values to the dictionary values

#________________________________
#favorites.csv
#
import csv
with open("favorites.csv", "r") as file:
    print(f"file:{file}")
    reader = csv.reader(file) #here we create a list of the individual lies/rows
    count = 0
    for row in reader:
        if len(row)>=3: #so if there is no value in the third element in the row 
            count += 1
            # print(f"{count}: ", end ="")
            favorite = row[2]
            print(favorite)

#small improvement adding a counter
import csv
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    count = 0
    Python, Java, c = 0,0,0 # declering a counter variables
    for row in reader:
        if len(row)>=3: #so if there is no value in the third element in the row 
            count += 1
            # print(f"{count}: ", end ="")
            favorite = row["Programming Language"]
            if favorite == "Python": ##very primitive way of counting 
                Python +=1 
            elif favorite == "C":
                c +=1
            elif favorite == "Java":
                Java +=1
print(f"Java: {Java}")
print(f"Python: {Python}")
print(f"C: {c}")

#a big improvement making it universla to work
import csv
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    count = {}
    
    for row in reader:
        
        if len(row)>=3: #so if there is no value in the third element in the row 
            favorite = row["Programming Language"]
            if favorite in count:
                count[favorite] += 1
            else:
                count[favorite] = 1
            
        else:
            print(f"row len: {len(row)}")
            print(f"{row}")

for f in count: # iterate thru the count dict
    if count[f]>1:
        print(f"{f}: {count[f]}")

#modifing the counter so it will show from the bigest values of dict
import csv
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    count = {}
    
    for row in reader:
        
        if len(row)>=3: #so if there is no value in the third element in the row 
            favorite = row["Programming Language"]
            if favorite in count:
                count[favorite] += 1
            else:
                count[favorite] = 1
            
        else:
            print(f"row len: {len(row)}")
            print(f"{row}")

ordered= dict(sorted(count.items(), reverse= True, key= lambda x:x[1])) ## this is the way to sortd by the values not keys
for f in ordered: # iterate thru the count dict
    if ordered[f]>1:
        print(f"{f}: {ordered[f]}")
# print(dict(sorted(count.items(), key= lambda x:x[1]), reverse=True))








