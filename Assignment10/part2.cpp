/*
Ankit Das
3rd November 2020
Types of Inheritance
*/

#include<iostream>

class student{
    protected:
        std::string studentName;
        std::string classID;
        unsigned long long int prn;
    
        void getInfo();
    
    public:
        student(){
            studentName = "";
            classID = "";
            prn = 0;
        }
};

class marks: protected student{
    protected:
        float mathMarks;
        float scienceMarks;
        float historyMarks;
        float languageMarks;

        void getMarks();
    
    public:
        marks(){
            mathMarks = 0;
            scienceMarks = 0;
            historyMarks = 0;
            languageMarks = 0;
        }
};

class result: protected marks{
    private:
        float total;
        char grade;

    public:
        result(){
            total = 0;
            grade = 'G';
        }

        void getData();
        void displayData();
};

void student::getInfo(){
    std::cout<<"ENTER INFO: \n";

    std::cout<<"NAME: ";
    std::cin.clear();
    std::cin.ignore(1000,'\n');

    std::getline(std::cin,studentName);

    std::cout<<"CLASS: ";
    std::cin.clear();
    std::cin.ignore(1000,'\n');

    std::getline(std::cin,classID);
    std::cout<<"PRN: ";
    std::cin>>prn;
}

void marks::getMarks(){
    std::cout<<"ENTER MARKS: \n";
    
    std::cout<<"MATH: ";
    std::cin>>mathMarks;
    std::cout<<"SCIENCE: ";
    std::cin>>scienceMarks;
    std::cout<<"HISTORY: ";
    std::cin>>historyMarks;
    std::cout<<"LANGUAGE: ";
    std::cin>>languageMarks;
}

void result::getData(){
    getInfo();
    getMarks();

    total += mathMarks;
    total += scienceMarks;
    total += historyMarks;
    total += languageMarks;

    if(total >= 90){
        grade = 'A';
    }

    else if(total >= 80 && total < 90){
        grade = 'B';
    }
    
    else if(total >= 60 && total < 80){
        grade = 'C';
    }
    
    else if(total >= 35 && total < 60){
        grade = 'D';
    }
    
    else if(total < 35){
        grade = 'F';
    }
}

void result::displayData(){
    std::cout<<"\n-- RESULT -- ";

    std::cout<<"\n-INFO-";
    std::cout<<"\nNAME: "<<studentName;
    std::cout<<"\nCLASS: "<<classID;
    std::cout<<"\nPRN: "<<prn;

    std::cout<<"\n\n-MARKS-";
    std::cout<<"\nMATH: "<<mathMarks;
    std::cout<<"\nSCIENCE: "<<scienceMarks;
    std::cout<<"\nHISTORY: "<<historyMarks;
    std::cout<<"\nLANGUAGE: "<<languageMarks;


    std::cout<<"\nTOTAL: "<<total <<" / 400";
    if(grade != 'F'){
        std::cout<<"\nSTUDENT PASSED WITH "<<grade<<" GRADE"<<std::endl;
    }

    else{
        std::cout<<"\nSTUDENT HAS FAILED!"<<std::endl;
    }
}

int main(){
    result res;

    res.getData();
    res.displayData();
    return 0;
}
