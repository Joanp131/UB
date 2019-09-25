import random
import math

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

def variancia(data):
    x_ = mitjana(data)
    pre = 0
    n = len(data)
    for i in range (n):
        pre += (data[i] - x_)*(data[i] - x_)

    return pre/n

def desv_tip(data):
    s2x = variancia(data)
    return math.sqrt(s2x)

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
        print("Mitjana: {}".format(mitjana(data), end='\n'))
        print("Mediana: {}".format(mediana(data), end='\n'))
        print("Variància: {}".format(variancia(data), end='\n'))
        print("Desviació típica: {}".format(desv_tip(data), end='\n'))
    f.close()
    delete()
    

main()
