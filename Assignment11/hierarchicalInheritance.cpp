/*
Ankit Das
12th November
Example utilizing Hierarchical Inheritance

classes Student and Employee Inherit class person

              Person
              /     \
             /       \
         Student    Employee
*/

#include<iostream>
#include<string>

class person{
    protected:
    std::string name;
    std::string dob;
    unsigned int age;
};

class Student : protected person{
    public:
        void getData();
        void showData();
}; 


class Employee : protected person{
    public:
        void getData();
        void showData();
}; 

void Student::getData(){
    std::cout<<"\n\n-- ENTER STUDENT DATA --";
    std::cout<<"\nENTER NAME: ";
    std::cin.clear();
    std::cin.ignore(10,'\n');
    std::getline(std::cin,name);
    std::cout<<"ENTER DATE OF BIRTH: ";
    std::getline(std::cin,dob);
    std::cout<<"ENTER AGE: ";
    std::cin>>age;
}

void Student::showData(){
    std::cout<<"\n\n-- STUDENT DATA --";
    std::cout<<"\nNAME: "<<name;
    std::cout<<"\nDATE OF BIRTH: "<<dob;
    std::cout<<"\nAGE: "<<age<<std::endl;
}


void Employee::getData(){
    std::cout<<"\n\n-- ENTER EMPLOYEE DATA --";
    std::cout<<"\nENTER NAME: ";
    std::cin.clear();
    std::cin.ignore(10,'\n');
    std::getline(std::cin,name);
    std::cout<<"ENTER DATE OF BIRTH: ";
    std::getline(std::cin,dob);
    std::cout<<"ENTER AGE: ";
    std::cin>>age;
}

void Employee::showData(){
    std::cout<<"\n\n-- EMPLOYEE DATA --";
    std::cout<<"\nNAME: "<<name;
    std::cout<<"\nDATE OF BIRTH: "<<dob;
    std::cout<<"\nAGE: "<<age<<std::endl;
}

int main(){
    static unsigned int n;
    std::cout<<"ENTER SIZE: ";
    std::cin>>n;

    Employee *employeeList = (Employee*)malloc(n * sizeof(Employee));
    Student *studentList = (Student*)malloc(n * sizeof(Student));

    Employee tempEmployee;
    Student tempStudent;

    unsigned int employeeSize = 0;
    unsigned int studentSize = 0;
    unsigned int i = 0;
    unsigned int choice = 0;


    

        while(true){
        // Main Menu
        std::cout<<"\n\n-- MENU --";
        std::cout<<"\n1. ENTER EMPLOYEE DATA";
        std::cout<<"\n2. ENTER STUDENT DATA";
        std::cout<<"\n3. SHOW EMPLOYEE LIST";
        std::cout<<"\n4. SHOW STUDENT LIST";
        std::cout<<"\n5. EXIT";
        std::cout<<"\n\nENTER CHOICE: ";
        std::cin>>choice;
        switch(choice){
            case 1:
                if(employeeSize < n){
                tempEmployee.getData();
                employeeList[employeeSize] = tempEmployee;
                employeeSize++;
                }

                else{
                    std::cout<<"OverFlow Error! Cannot Insert Element";
                }
                break;

            case 2:
                if(studentSize < n){
                tempStudent.getData();
                studentList[studentSize] = tempStudent;
                studentSize++;
                }

                else{
                    std::cout<<"OverFlow Error! Cannot Insert Element";
                }
                break;
            
            case 3:
                if(employeeSize == 0){
                    std::cout<<"LIST EMPTY!";
                }

                i = 0;
                while(i < employeeSize){
                    employeeList[i].showData();
                    i++;
                }
                break;
            
            case 4:

                if(studentSize == 0){
                    std::cout<<"LIST EMPTY!";
                }

                i = 0;
                while(i < studentSize){
                    studentList[i].showData();
                    i++;
                }
                break;
            
            case 5:
                return 0;
            
            default:
                std::cout<<"INVALID CHOICE! TRY AGAIN";
                break;
        }
    }
    return 0;
}
