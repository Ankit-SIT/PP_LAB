/*
Ankit Das
27th October
Runtime Polymorphism
*/

#include<iostream>

class polygon {
    protected:
    float height;
    float width;
    float area;

    public:
    void set_values(float height, float width){
        this->height = height;
        this->width = width;
    }

    virtual float getArea() = 0;
};

class Rectangle: public polygon {
    public:
    float getArea(){
        this->area = this->height * this->width;
        return this->area;
    }
};

class Triangle: public polygon {
    public:
    float getArea(){
        this->area = (this->width * this->height)/2;
        return this->area;
    }
};

int main(){
    Rectangle rectangle;
    Triangle triangle;

    float height = 0;
    float width = 0;
    int choice = 0;
    bool set = false;

    while(true){
    std::cout<<std::endl<<std::endl<<"-- MENU --"<<std::endl;
    std::cout<<"1. SET VALUES"<<std::endl;
    std::cout<<"2. GET AREA"<<std::endl;
    std::cout<<"3. EXIT"<<std::endl;
    
    std::cout<<"ENTER CHOICE: ";
    std::cin>>choice;

    switch(choice){
    case 1:
        std::cout<<"-- RECTANGLE --"<<std::endl;
        std::cout<<std::endl<<"HEIGHT: ";
        std::cin>>height;
        std::cout<<"WIDTH: ";
        std::cin>>width;

        rectangle.set_values(height,width);

        std::cout<<std::endl<<"-- TRIANGLE --";
        std::cout<<std::endl<<"HEIGHT: ";
        std::cin>>height;
        std::cout<<"BASE: ";
        std::cin>>width;

        triangle.set_values(height,width);
        set = true;
        break;

    case 2:
        if(set){
            std::cout<<std::endl<<"RECTANGLE: "<<rectangle.getArea()<<std::endl;
            std::cout<<"TRIANGLE: "<<triangle.getArea()<<std::endl;
            }
        
        else{
            std::cout<<"VALUES HAVE NOT BEEN SET! TRY AGAIN"<<std::endl;
        }

        break;
    
    case 3:
        return 0;
    
    default:
        std::cout<<"INVALID CHOICE! TRY AGAIN"<<std::endl;
        break;
        }
    }
}
