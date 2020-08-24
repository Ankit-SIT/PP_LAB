/*
Ankit Das
24th August 2020
Complex Number Operations using classes
*/

#include<iostream>

class complex_number{
    public:
    double real;
    double imaginary;

    complex_number(){
        real = 0;
        imaginary = 0;
    }

    void init(){
         std::cout<<"REAL: ";
         std::cin>>real;
         std::cout<<"IMAGINARY: ";
         std::cin>>imaginary;
    }

    void display(){
        std::cout<<real<<" + "<<imaginary<<"i"<<std::endl;
    }
};

complex_number add(complex_number c1, complex_number c2){        
    class complex_number result;

    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    
    return result;
}

complex_number subtract(complex_number c1, complex_number c2){
    class complex_number result;

    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;
    
    return result;
}

complex_number multiply(complex_number c1, complex_number c2){
    class complex_number result;

    result.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
    result.imaginary = (c1.real * c2.imaginary) + (c2.real * c1.imaginary);
    
    return result;
}

complex_number divide(complex_number c1, complex_number c2){
    class complex_number result;

    if(c2.real != 0 || c2.imaginary != 0)
    {
    int divisor = (c2.real*c2.real + c2.imaginary*c2.imaginary);
    result.real = (c1.real*c2.real) + (c1.imaginary*c2.imaginary);
    result.real /= divisor;

    result.imaginary = (c1.imaginary*c2.real) - (c1.real*c2.imaginary);
    result.imaginary /= divisor;
   }
    return result;
}



int main(){
    int m = 0, n = 0, choice = 0;
    complex_number c1,c2;

    std::cout<<"ENTER THE FIRST NUMBER\n";
    c1.init();

    while(true){
        std::cout<<"\nMENU\n";
        std::cout<<"1. ADD\n";
        std::cout<<"2. SUBTRACT\n";
        std::cout<<"3. MULTIPLY\n";
        std::cout<<"4. DIVIDE\n";
        std::cout<<"5. EXIT\n";
        std::cin>>choice;

        if(choice < 5){    
                std::cout<<"\nENTER THE SECOND NUMBER\n";
                c2.init();
        }

        switch (choice)
        {
        case 1:
            c1 = add(c1,c2);
            break;

        case 2:
            c1 = subtract(c1,c2);
            break;
        
        case 3:
            c1 = multiply(c1,c2);
            break;
        
        case 4:
            c1 = divide(c1,c2);
            break;
        
        case 5:
            return 0;

        default:
            std::cout<<"ERROR! INVALID CHOICE\n";
            break;
        }
    c1.display();
    } 
}
