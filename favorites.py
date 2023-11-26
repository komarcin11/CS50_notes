import csv

with open("favorites.csv", "r") as file:
    print(f"file:{file}")
    reader = csv.reader(file)
    count = 0
    for row in reader:
        if len(row)>=3: #so if there is no value in the third element in the row 
            count += 1
            # print(f"{count}: ", end ="")
            favorite = row[2]
            print(favorite)
        



