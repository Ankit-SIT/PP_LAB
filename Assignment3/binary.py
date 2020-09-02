def bin(num):
    if num != 0:
        bin(num//2)
        print(num % 2,end='')

def main():
    number = int(input())
    bin(number)
    print("\n")


