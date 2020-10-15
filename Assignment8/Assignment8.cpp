#include<iostream>
#include<math.h>

class ComplexNumber{
    private:
        float real;
        float imaginary;
    
    public:
        ComplexNumber(){
            this->real = 0;
            this->imaginary = 0;
        }

        ComplexNumber(float real, float imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }

        void Display(){
            std::cout<<this->real<<" + "<<this->imaginary<<"i"<<std::endl;
        }

        ComplexNumber operator ++ ();
        ComplexNumber operator ++ (int temp);
        bool operator < (ComplexNumber C1);
        friend ComplexNumber operator + (ComplexNumber C1,ComplexNumber C2);
        friend float findMagnitude(ComplexNumber C1);
};

float findMagnitude(ComplexNumber C1){
    return sqrt(pow(C1.real,2) + pow(C1.imaginary,2));
}

ComplexNumber ComplexNumber::operator++(){
    this->real = this->real + 1;       // Increments current values and returns results
    this->imaginary = this->imaginary + 1;
    return *this;
}

ComplexNumber ComplexNumber::operator++(int temp){
    ComplexNumber C1 = (*this);   //Stores Current in Temporary Variable, Increments then returns previous values
    this->real = this->real + 1;
    this->imaginary = this->imaginary + 1;
    return C1;
}

ComplexNumber operator + (ComplexNumber C1,ComplexNumber C2){
            ComplexNumber temp;
            temp.real = C1.real + C2.real;
            temp.imaginary = C1.imaginary + C2.imaginary;
            return temp;
        }

bool ComplexNumber::operator < (ComplexNumber C1){
    if(this->imaginary == 0){
        return true;
    }

    float magnitude1 = findMagnitude(*this);
    float magnitude2 = findMagnitude(C1);

    if(magnitude1 < magnitude2){
        return true;
    }

    else{
        return false;
    }
}

int main(){
    int choice = 0;
    float real = 0;
    float imaginary = 0;


    std::cout<<"\n-- C1 --";
    std::cout<<"\nENTER DATA: ";
    std::cin>>real>>imaginary;
    ComplexNumber C1(real,imaginary);

    std::cout<<"\n-- C2 --";
    std::cout<<"\nENTER DATA: ";
    std::cin>>real>>imaginary;
    ComplexNumber C2(real,imaginary);

    

    while(true){
        std::cout<<"\n\n-- MENU --";
        std::cout<<"\n1. C1++";
        std::cout<<"\n2. ++C1";
        std::cout<<"\n3. C1 + C2";
        std::cout<<"\n4. C1 < C2?";
        std::cout<<"\n5. DISPLAY";
        std::cout<<"\n6. EXIT";
        std::cout<<"\n\nENTER CHOICE: ";
        std::cin>>choice;

        switch(choice){
            case 1:
                C1++.Display();
                break;
            
            case 2:
                ++C1;
                C1.Display();
                break;
            
            case 3:
                C1 = C1 + C2;
                C1.Display();
                break;
            
            case 4:
                if(C1 < C2){
                    C2.Display();
                    std::cout<<"is greater than\n";
                    C1.Display();
                }

                else{
                    C1.Display();
                    std::cout<<"is greater than\n";
                    C2.Display();
                }

                break;
            
            case 5:
                std::cout<<"\nC1: ";
                C1.Display();
                
                std::cout<<"\nC2: ";
                C2.Display();
                break;
            
            case 6:
                return 0;
            
            default:
                std::cout<<"INVALID CHOICE! TRY AGAIN";
        }
    }

    return 0;
}
