def main():
    string = list(input())
    for character in string:
        if character.isdigit():
            print(str(character) + " is a digit")
    
        elif character.isupper():
            print(str(character) + " is an upper case character")
        
        elif character.islower():
            print(str(character) + " is a lower case character")
        
        else:
            print(str(character) + " is a special character")
    
    print("\n")