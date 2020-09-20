#include<iostream>

class Student{
    char clas[10];
    long prn;
    float marks[5];
    float total;
    char grade;
    float percentage;

    public:
    char name[30];

    Student(){
        prn = 0;
        percentage = 0;
        total = 0;
    }
    void newStudent();
    void getmarks();
    void display();
    void calculateGrade();
    void calculatePercentage();
};

void Student::newStudent(){
    std::cin.ignore(100,'\n');
    std::cout<<"\nENTER NAME: ";
    std::cin.getline(this->name,30);
    std::cout<<"ENTER CLASS: ";
    std::cin.getline(this->clas,10);
    std::cout<<"ENTER PRN: ";
    std::cin>>this->prn;
    getmarks();
    calculatePercentage();
    calculateGrade();
}

void Student::getmarks(){
    std::cout<<"ENTER MARKS IN SUBJECT";
    std::cout<<" 1: ";
    std::cin>>this->marks[0];
    std::cout<<" 2: ";
    std::cin>>this->marks[1];
    std::cout<<" 3: ";
    std::cin>>this->marks[2];
    std::cout<<" 4: ";
    std::cin>>this->marks[3];
    std::cout<<" 5: ";
    std::cin>>this->marks[4];
}

void Student::display(){
    std::cout<<" \n---------------------";
    std::cout<<"\nNAME: "<<this->name<<std::endl;
    std::cout<<"CLASS: "<<this->clas<<std::endl;
    std::cout<<"PRN: "<<this->prn<<std::endl;
    std::cout<<"TOTAL: "<<this->total<<std::endl;
    std::cout<<"GRADE: "<<this->grade<<std::endl;
    std::cout<<"PERCENTAGE: "<<this->percentage<<std::endl;
    

    if(this->grade == 'F'){
        std::cout<<"\nFAILED"<<std::endl;;
    } 

    else if(this->grade == 'I'){
        std::cout<<"\nINVALIDATED"<<std::endl;;
    }

    else{
        std::cout<<"\nPASSED WITH GRADE "<<this->grade<<std::endl;
    }

    std::cout<<" ---------------------\n";
}

void Student::calculatePercentage(){
    int i = 0;
    for(i = 0; i < 5; i++){
        this->total += this->marks[i];
    }

    this->percentage = (this->total / 500) * 100;
}

void Student::calculateGrade(){
    if(this->percentage > 90.00 && this->percentage <= 100.00){
        this->grade = 'A';
    }
    
    else if(this->percentage <= 90.00 && this->percentage > 80.00){
        this->grade = 'B';
    }
    
    else if(this->percentage <= 80.00 && this->percentage > 60.00){
        this->grade = 'C';
    }
    
    else if(this->percentage <= 60.00 && this->percentage > 40.00){
        this->grade = 'D';
    }
    
    else if(this->percentage <= 40.00 && this->percentage > 33.00){
        this->grade = 'E';
    }

    else if(this->percentage >= 0.00 && this->percentage <= 50.00){
        this->grade = 'F';
    }
    
    else{
        this->grade = 'I';
    }
}

int main(){

int n = 0;
int size = -1;
int choice = 0;
int temp = 0;
int i = 0;


std::cout<<"ENTER SIZE: ";
std::cin>>n;

Student *Students = (Student*)malloc(n * sizeof(Student));

while(true){
    std::cout<<"\n\n -- MENU --"<<std::endl;
    std::cout<<"1. ADD STUDENT"<<std::endl;
    std::cout<<"2. REMOVE STUDENT"<<std::endl;
    std::cout<<"3. DISPLAY LIST"<<std::endl;
    std::cout<<"4. EXIT"<<std::endl;
    std::cout<<"ENTER YOUR CHOICE: ";
    std::cin>>choice;

    switch (choice)
    {
    case 1:
    if(size == n){
        std::cout<<"OVERFLOW! CANNOT ADD MORE ELEMENTS!";
    }
    
    else{
        size++;
        Students[size].newStudent();
    }
    break;

    case 2:
        if(size > 0){
        std::cout<<"\nENTER REMOVAL INDEX: "<<std::endl;
        std::cin>>temp;
        std::cout<<"ELEMENT WITH NAME "<< Students[temp].name << " HAS BEEN DELETED";
         while(temp <= size){
          Students[temp] = Students[temp + 1];
          size--;
         }
        }

        else{
            std::cout<<"UNDERFLOW! NO MORE ELEMENTS!";
        }
        break;
    
    case 3:
        temp = 0;
        while(temp <= size){
            Students[temp].display();
            temp++;
        }
        break;
    
    case 4:
        return 0;
    
    default:
        std::cout<<"INVALID CHOICE! TRY AGAIN!"<<std::endl;
        break;
    }
}

return 0;
}
