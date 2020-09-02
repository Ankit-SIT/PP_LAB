def isPrime(number):
    for i in range(2,number//2+1):
        if(number % i == 0):
            return False
    
    return True


def main():
    number = int(input())
    print(str(isPrime(number)) + "\n")
