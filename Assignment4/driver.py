import calculator
import reverse
import isPrime
import month
import Sorted

def main():
    run = True
    while(run):
        print("1.CALCULATOR")
        print("2.REVERSE A NUMBER")
        print("3.PRIME OR NOT")
        print("4.MONTH NAME")
        print("5.SORTED OR NOT")
        print("6.EXIT")
        print("ENTER CHOICE: ")
        
        try:
            choice = int(input())

            if(choice == 1):
                calculator.main()

            elif(choice == 2):
                reverse.main()

            elif(choice == 3):
                isPrime.main()
                
            elif(choice == 4):
                month.main()

            elif(choice == 5):
                Sorted.main()

            elif(choice == 6):
                run = False
                
            else:
                print("INVALID INPUT!")

        
        except ValueError:
            print("INVALID CHOICE! ENTER A NUMBER\n")

main()