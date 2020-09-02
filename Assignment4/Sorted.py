def isSorted(x,y,z):
    if(x < y and y < z):
        return True

    return False

def main():
    x = int(input())
    y = int(input())
    z = int(input())

    print(str(isSorted(x,y,z)) + "\n")
    