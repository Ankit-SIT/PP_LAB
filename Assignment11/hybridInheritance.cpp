/*
Ankit Das
12th November
Example for Hybrid Inheritance

Classes UTMarks and Sports Inherit Student
and
Class result inherits UTMarks and Sports

        Student
        /     \
       /       \
    UTMarks   Sports
       \       /
        \     /
         result


*/

#include<iostream>
#include<string>

class Student{
    private:
    std::string name;
    long long unsigned int prn;

    public:

    Student(){
        name = "";
        prn = 0;
    }

    void getInfo();
    void showInfo();
};

class UTMarks : protected Student{
    private:
    float marks[5];
    float total;
    char grade;

    public:
    UTMarks(){
        int i = 0;

        while(i < 5){
            marks[i] = 0;
            i++;
        }

        total = 0;
        grade = 'I';
    }

    void getMarks();
    void showMarks();
};

class Sports : protected Student{
    private:
    float fitnessIndex;
    char fitnessGrade;

    public:
    Sports(){
        fitnessIndex = 0;
        fitnessGrade = 'I';
    }

    void getSport();
    void showSport();
};

class result : protected UTMarks, protected Sports{
    public:
    void getData();
    void showData();
};

void Student::getInfo(){
    std::cout<<"\n\n-- ENTER STUDENT DATA --";
    std::cout<<"\nENTER NAME: ";
    std::cin.clear();
    std::cin.ignore(10,'\n');
    std::getline(std::cin,name);
    std::cout<<"ENTER PRN: ";
    std::cin>>prn;
}

void Student::showInfo(){
    std::cout<<"\nNAME: "<<name;
    std::cout<<"\nPRN: "<<prn;
}

void UTMarks::getMarks(){
    std::cout<<"\n\n-- ENTER STUDENT MARKS --\n";

    int i = 0;
    while (i < 5){
        std::cout<<"ENTER MARKS "<<i<<": ";
        std::cin>>marks[i];
        total += marks[i];
        i++;
    }

    total = total / 5;

    if(total > 90 && total <= 100){
        grade = 'A';
    }

    else if(total > 70 && total <= 90){
        grade = 'B';
    }
    
    else if(total > 50 && total <= 70){
        grade = 'C';
    }
    
    else if(total >= 33 && total <= 50){
        grade = 'D';
    }

    else if(total >= 0 && total < 33){
        grade = 'F';
    }

    else{
        grade = 'I';
    }
}

void UTMarks::showMarks(){
    int i = 0;
    
    while(i < 5){
    std::cout<<"\nMARKS "<<i + 1<<": "<<marks[i];
    i++;
    }

    std::cout<<"\nTOTAL: "<<total;
    
    if(grade != 'F' && grade != 'I'){
        std::cout<<"\n\nSTUDENT HAS PASSED WITH GRADE "<<grade;
    }
    
    else if(grade == 'F'){
        std::cout<<"\n\nSTUDENT HAS FAILED!";
    }

    else if(grade == 'I'){
        std::cout<<"\n\nINVALID DETAILS ENTERED!";
    }
}

void Sports::getSport(){
    std::cout<<"ENTER FITNESS INDEX: ";
    std::cin>>fitnessIndex;
    
    if (fitnessIndex > 90 && fitnessIndex <= 100){
        fitnessGrade = 'A';
    }
    
    else if(fitnessIndex > 70 && fitnessIndex <= 90){
        fitnessGrade = 'B';
    }
    
    else if(fitnessIndex > 50 && fitnessIndex <= 70){
        fitnessGrade = 'C';
    }
    
    else if(fitnessIndex >= 33 && fitnessIndex <= 50){
        fitnessGrade = 'D';
    }

    else if(fitnessIndex >= 0 && fitnessIndex < 33){
        fitnessGrade = 'F';
    }

    else{
        fitnessGrade = 'I';
    }
}

void Sports::showSport(){
    std::cout<<"\n\nFITNESS INDEX: "<<fitnessIndex;

    if(fitnessGrade != 'I'){
        std::cout<<"\nFITNESS GRADE: "<<fitnessGrade;
    }

    else{
        std::cout<<"\nINVALID DATA ENTERED!";
    }
}

void result::getData(){
    UTMarks::getInfo();
    getMarks();
    getSport();
}

void result::showData(){
    std::cout<<"\n-- STUDENT DATA --";
    UTMarks::showInfo();
    showMarks();
    showSport();
    std::cout<<"\n-------------------\n";
}

int main(){
 static unsigned int n;

 std::cout<<"ENTER SIZE: ";
 std::cin>>n;
 
 unsigned int listSize = 0;
 unsigned int index = 0;
 unsigned int choice = 0;

 result* studentList = new result[n];
 result temp;

 while(true){
     std::cout<<"\n\n-- MENU --";
     std::cout<<"\n1. ADD ENTRY";
     std::cout<<"\n2. DELETE ENTRY";
     std::cout<<"\n3. SHOW LIST";
     std::cout<<"\n4. EXIT";
     std::cout<<"\n\nENTER CHOICE: ";
     std::cin>>choice;

     switch(choice){
         case 1:
            if(listSize < n){
            temp.getData();
            studentList[listSize] = temp;
            listSize++;
            }

            else{
                std::cout<<"LIST FULL!";
            }

            break;
         
         case 2:
            if(listSize > 0){
                std::cout<<"ENTER INDEX: ";
                std::cin>>index;

                if(index > listSize){
                    std::cout<<"CANNOT DELETE! INVALID INDEX!";
                    break;
                }

                while(index < listSize){
                    studentList[index] = studentList[index + 1];
                    index++;
                }

                listSize--;
            }

            else{
                std::cout<<"LIST EMPTY!";
            }

            break;

         case 3:
            if(listSize < 1){
                std::cout<<"LIST EMPTY!";
                break;
            }
            
            std::cout<<"-- STUDENT LIST --\n\n";
            index = 0;

            while(index < listSize){
                studentList[index].showData();
                index++;
            }

            std::cout<<"\n-- END OF LIST --";
            break;  
         
         case 4:
            return 0;
         
         default:
            std::cout<<"INVALID CHOICE! TRY AGAIN!";
            break;
     }
 }


 return 0;   
}
