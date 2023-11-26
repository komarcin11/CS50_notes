
import csv
with open("phonebook.csv", "a" ,newline='') as file: # open a file in append mode and assign to a variable 

    name = input("name: ") # ask for values
    number = input ("number: ")

    write = csv.DictWriter(file, fieldnames=["name", "number"]) #here you create a dictionary writer insted of list
    write.writerow({"name":name, "number": number}) # here you assign values to the dictionary values


