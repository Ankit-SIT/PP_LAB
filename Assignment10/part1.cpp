#include<iostream>
#include<string>

// base classes item and sale
class item{
    protected:
    std::string title;
    float price;
};

class sale{
    protected:
    unsigned int month1;
    unsigned int month2;
    unsigned int month3;
};

// child classes hwitem and switem
class hwitem: public item, public sale{
    public:
    void getData();
    void displayData();
};

class switem: public item, public sale{
    public:
    void getData();
    void displayData();
};

void hwitem::getData(){
    std::cout<<"\n-- HARDWARE ITEM --";    
    std::cout<<"\nENTER DETAILS: ";

    std::cout<<"\nITEM NAME: ";

    // clear cin to prevent getline from not waiting for input
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    // use getline to input strings with spaces
    std::getline(std::cin,title);

    std::cout<<"ITEM COST: ";
    std::cin>>price;

    std::cout<<"SALES: ";
    std::cout<<"\nMONTH 1: ";
    std::cin>>month1;
    std::cout<<"MONTH 2: ";
    std::cin>>month2;
    std::cout<<"MONTH 3: ";
    std::cin>>month3;

    std::cout<<std::endl;
}

void switem::getData(){
    std::cout<<"\n-- SOFTWARE ITEM --";
    std::cout<<"\nENTER DETAILS: ";

    std::cout<<"\nITEM NAME: ";
    // clear cin to prevent getline from not waiting for input
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    // use getline to input strings with spaces
    std::getline(std::cin,title);

    std::cout<<"ITEM COST: ";
    std::cin>>price;

    std::cout<<"SALES: ";
    std::cout<<"\nMONTH 1: ";
    std::cin>>month1;
    std::cout<<"MONTH 2: ";
    std::cin>>month2;
    std::cout<<"MONTH 3: ";
    std::cin>>month3;

    std::cout<<std::endl;
}

void hwitem::displayData(){
     std::cout<<"\n-- HARDWARE ITEM --";
    std::cout<<"\nITEM NAME: "<<title;
    std::cout<<"\nITEM COST: "<<price;
    std::cout<<"\n\nSALES: ";
    std::cout<<"\nMONTH 1: "<<month1;
    std::cout<<"\nMONTH 2: "<<month2;
    std::cout<<"\nMONTH 3: "<<month3<<std::endl;
}

void switem::displayData(){
     std::cout<<"\n-- SOFTWARE ITEM --";
    std::cout<<"\nITEM NAME: "<<title;
    std::cout<<"\nITEM COST: "<<price;
    std::cout<<"\n\nSALES: ";
    std::cout<<"\nMONTH 1: "<<month1;
    std::cout<<"\nMONTH 2: "<<month2;
    std::cout<<"\nMONTH 3: "<<month3<<std::endl;
}

int main(){
    // MAX_SIZE of lists
    static int n = 0;

    // get user defined size
    std::cout<<"ENTER SIZE: ";
    std::cin>>n;

    // create list of items
    hwitem* hwlist = (hwitem*)malloc(n * sizeof(hwitem));
    switem* swlist = (switem*)malloc(n * sizeof(switem));

    // initialize variables
    int swsize = 0;
    int hwsize = 0;
    int choice = 0;
    int i = 0;
    
    // initialize temporary objects
    switem swtemp;
    hwitem hwtemp;

    while(true){
        // Main Menu
        std::cout<<"\n\n-- MENU --";
        std::cout<<"\n1. ENTER HW ITEM";
        std::cout<<"\n2. ENTER SW ITEM";
        std::cout<<"\n3. SHOW HW LIST";
        std::cout<<"\n4. SHOW SW LIST";
        std::cout<<"\n5. EXIT";
        std::cout<<"\n\nENTER CHOICE: ";
        std::cin>>choice;
        switch(choice){
            case 1:
                if(hwsize < n){
                hwtemp.getData();
                hwlist[hwsize] = hwtemp;
                hwsize++;
                }

                else{
                    std::cout<<"OverFlow Error! Cannot Insert Element";
                }
                break;

            case 2:
                if(swsize < n){
                swtemp.getData();
                swlist[swsize] = swtemp;
                swsize++;
                }

                else{
                    std::cout<<"OverFlow Error! Cannot Insert Element";
                }
                break;
            
            case 3:
                i = 0;
                while(i < hwsize){
                    hwlist[i].displayData();
                    i++;
                }
                break;
            
            case 4:
                i = 0;
                while(i < swsize){
                    swlist[i].displayData();
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
}

