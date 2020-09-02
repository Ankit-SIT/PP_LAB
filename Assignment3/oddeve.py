def showResult(count,total):
    print("SUM OF ODD NUMBERS: " + str(total))
    print("NUMBER OF ODD NUMBERS: " + str(count))
    print("AVERAGE: " + str(total / count))
    print("\n")

def main():
    count = 1
    total = 0

    while True:


        try:
            number = int(input())

            if number == -1:
                showResult(count,total)
                break

            elif str(number).isdigit():
                    if (number % 2) != 0:
                        total += number
                        count += 1
        except ValueError:
                print("Invalid Input! Try again")
