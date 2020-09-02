def reverse(number):
    reverse = 0
    while(number > 0):
        reverse = (reverse * 10) + (number % 10)
        number //= 10
    
    return reverse

def main():
    number = int(input())
    print("Reverse of " + str(number) + " is " + str(reverse(number)) + "\n")
