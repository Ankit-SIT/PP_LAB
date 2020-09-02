import binary
import oddeve
import power
import typer
import greatest

run = True
while(run):    
        print("1.TYPE OF CHARACTER")
        print("2.GREATEST OF 3 NUMBERS")
        print("3.DECIMAL TO BINARY")
        print("4.ODD EVEN OPERATION")
        print("5.POWER OF 2")
        print("6.EXIT")
        print("ENTER CHOICE: ")

        try: 
            choice = int(input())
    
            if(choice == 1):
                typer.main()

            elif(choice == 2):
                greatest.main()

            elif(choice == 3):
                binary.main()

            elif(choice == 4):
                oddeve.main()

            elif(choice == 5):
                power.main()
    
            elif(choice == 6):
                run = False

            else:
                print("Invalid Choice! try again")

        except ValueError:
            print("Invalid Input! Enter a number!\n")
