def isPower(number):
    return (number & (number - 1) == 0) and (number != 0)

def main():
    number = int(input())
    print(isPower(number))
    print("\n")

    