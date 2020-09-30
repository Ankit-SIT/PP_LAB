/* 
  Ankit Das
  29th September 2020
  Friend Functions and Constructor Overloading
*/

#include <iostream>

class Complex
{
    private:
      float real;
      float imaginary;

    public:
       Complex(){                                   
           this->real = 0;
           this->imaginary = 0;
        }

       Complex(float real){                         // overload
           this->real = real;
           this->imaginary = real;
       }
       
       Complex(float real, float imaginary){       // overload
           this->real = real;
           this->imaginary = imaginary;
       }

       // prototypes       
    
       void get();
       friend void show(Complex);                 // friends     
       friend Complex clear();
       Complex operator +(Complex);               // operators
       Complex operator -(Complex);

};  
     
     
     
     // Member Function Definitions

       void Complex::get(){
           std::cout<<"real imaginary\n";   
           std::cin>>this->real;
           std::cin>>this->imaginary;
       }
       
       Complex Complex::operator + (Complex c2)        // overload
       {
           Complex temp;
           temp.real = this->real + c2.real;
           temp.imaginary = this->imaginary + c2.imaginary;

           return temp;
       }

       Complex Complex::operator - (Complex c2)
       {
           Complex temp;
           temp.real = this->real - c2.real;
           temp.imaginary = this->imaginary - c2.imaginary;

           return temp;
       }


      // Friend Function Definitions

       void show(Complex Result)                        
       {
           (Result.imaginary < 0)? std::cout<<Result.real<<" - "<<abs(Result.imaginary)<<"i" :std::cout<<Result.real<<" + "<<Result.imaginary<<"i";
       }

       Complex clear(){
         Complex Blank;
         return Blank;
       }




int main()
{
    Complex c1(0,0), c2(0);             
    int choice;

    c1.get();

    
while(true){
    std::cout<<"\n\n-- MENU --";        // Menu
    std::cout<<"\n1. ADD\n";
    std::cout<<"2. SUBTRACT\n";
    std::cout<<"3. DISPLAY\n";
    std::cout<<"4. CLEAR\n";
    std::cout<<"5. EXIT\n";
    std::cout<<"ENTER CHOICE: ";
    std::cin>>choice;
    
    if(choice < 3){
        c2.get();
    }

    switch(choice)
    {
    case 1:
        c1 = c1 + c2;
        break;
    
    case 2:
        c1 = c1 - c2;
        break;

    case 3:
        show(c1);
        break;
    
    case 4:
        c1 = clear();
        std::cout<<"\n\nCLEARED\n";
        show(c1);
        break;

    case 5:
        return 0;

    default:
        break;
    }
    
}
  
return 0;
}
