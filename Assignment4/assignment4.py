import math

def add(x,y):
    return x + y

def subtract(x,y):
    return x - y

def multiply(x,y):
    return x*y

def divide(x,y):
    return x//y

def power(x,power): 
    if(power == 0): 
        return 1
          
    answer=x 
    increment=x 
      
    for i in range(1, power): 
        for j in range (1,x): 
            answer+=increment 
        increment=answer 
    return answer

def log(x,base):
    if(base != 1):
        result = ln(x)/ln(base)
    
    else:
        result = 0

    return result

def ln(x):
    return math.log(x)

def main():
    run = True
    while(run):
        print("1.ADD")
        print("2.SUBTRACT")
        print("3.MULTIPLY")
        print("4.DIVIDE")
        print("5.POWER")
        print("6.LOG")
        print("7.NATURAL LOG")
        print("8.EXIT")
        print("ENTER CHOICE: ")

        choice = int(input())
        
        if(choice < 7):
            print("\nENTER TWO NUMBERS: ")
            x = int(input())
            y =  int(input())
        
        elif(choice == 7):
            print("\nENTER A NUMBER: ")
            x = int(input())

        if(choice == 1):
            x = add(x,y)
            print("RESULT:" + str(x) + "\n")

        elif(choice == 2):
            x = subtract(x,y)
            print("RESULT:" + str(x) + "\n")

        elif(choice == 3):
            x = multiply(x,y)
            print("RESULT:" + str(x) + "\n")

        elif(choice == 4):
            x = divide(x,y)
            print("RESULT:" + str(x) + "\n")

        elif(choice == 5):
            x = power(x,y)
            print("RESULT:" + str(x) + "\n")

        elif(choice == 6):
            x = log(x,y)
            print("RESULT:" + str(x) + "\n")
        
        elif(choice == 7):
            x = ln(x)
            print("RESULT:" + str(x) + "\n")

        else:
            run = False

main()
