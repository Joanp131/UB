import random

def create_data(n):
    f = open("data.txt", "w+")
    for i in range (n):
        f.write("%d, " % random.randint(0, 10))
    f.close()

def get_data():
    f = open("data.txt", "r+")
    data = f.read()
    f.close()
    data = data.split(", ")[:-1]
    return list(map(int, data))

def mitjana(data):
    n = len(data)
    pre = 0;
    for i in range (n):
        pre += data[i]
    result = pre / n
    return result

def mediana(sorted_data):
    n = int(len(sorted_data))
    if n % 2 == 0:
        return (sorted_data[int(n/2)-1] + sorted_data[int(n/2)])/2
    else:
        return sorted_data[int((n-1)/2)]

def sort_data(data):
    n = len(data)
    sort = True
    while sort:
        sort = False
        for i in range (n-1):
            prev = data[i]
            if prev > data[i+1]:
                data[i] = data[i+1]
                data[i+1] = prev
                sort = True
    return data

def delete():
    f = open("data.txt", "w+")
    f.write("")
    f.close()

def main():
    f = open("data.txt", "r+")
    n = 1001
    text = f.read()
    if (text == ''):
        print("Text document with data is empty, filling up with %d numbers\n" % n)
        create_data(n)
        main()
    else:
        data = get_data()
        print("Exists data in text document, %d numbers\n" % len(data))
        sorted_data = sort_data(data)
        print("Mitjana: ", mitjana(data), "\n")
        print("Mediana: ", mediana(sorted_data), "\n")
    f.close()
    delete()
    

main()
