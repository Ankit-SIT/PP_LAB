def findMonth(number):
    if(number == 1):
        return "JANUARY"
    
    elif(number == 2):
        return "FEBRUARY"
    
    elif(number == 3):
        return "MARCH"
    
    elif(number == 4):
        return "APRIL"
    
    elif(number == 5):
        return "MAY"
    
    elif(number == 6):
        return "JUNE"
    
    elif(number == 7):
        return "JULY"
    
    elif(number == 8):
        return "AUGUST"
    
    elif(number == 9):
        return "SEPTEMBER"
    
    elif(number == 10):
        return "OCTOBER"
    
    elif(number == 11):
        return "NOVEMBER"
    
    elif(number == 12):
        return "DECEMBER"
    
    else:
        return "INVALID INPUT!"


def main(): 
    try:
        number = int(input())
        print(str(number) + " - " + findMonth(number) + "\n")
    except ValueError:
        print("PLEASE ENTER A VALID CHARACTER")
