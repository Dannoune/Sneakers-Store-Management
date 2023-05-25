def search_sneakers():
    file_path = "C:/Users/Admin/Desktop/C/C_exo_2/sneakers.txt"
    import os


    for f in os.listdir("C:/Users/Admin/Desktop/C/C_exo_2/"):
        print(f)
    search_size = int(input("\nEnter your shoe size: "))
    search_gender = input("Enter your gender (male/female): ")
    search_brand = input("Enter the brand (Nike/Jordan): ")

    with open(file_path, "r") as file:
        lines = file.readlines()

    found_sneakers = []
    i = 0

    while i < len(lines):
        line = lines[i].strip()
        if line.startswith("Name:"):
            name = line.split("Name: ")[1]
            description = lines[i + 1].strip().split("Description: ")[1]
            year = int(lines[i + 2].strip().split("Year: ")[1])
            price = float(lines[i + 3].strip().split("Price: ")[1].split(" ")[0])
            brand = lines[i + 4].strip().split("Brand: ")[1]
            size = int(lines[i + 5].strip().split("Size: ")[1])
            gender = lines[i + 6].strip().split("Gender: ")[1]
            
            if size == search_size and gender.lower() == search_gender.lower() and brand.lower() == search_brand.lower():
                found_sneakers.append({
                    "Name": name,
                    "Description": description,
                    "Year": year,
                    "Price": price,
                    "Brand": brand,
                    "Size": size,
                    "Gender": gender
                })

        i += 1

    if found_sneakers:
        print("\nFound Sneakers:")
        for sneaker in found_sneakers:
            print("\tName:", sneaker["Name"])
            print("\tDescription:", sneaker["Description"])
            print("\tYear:", sneaker["Year"])
            print("\tPrice:", sneaker["Price"], "euro")
            print("\tBrand:", sneaker["Brand"])
            print("\tSize:", sneaker["Size"])
            print("\tGender:", sneaker["Gender"])
            print("----------------------------------------")
    else:
        print("\nNo sneakers found matching the criteria.")

search_sneakers()
