/* Ankit Das
Shopping List using Classes
19070122023
*/

#include<iostream>
 
struct item{                                                              // each element in the list is a structure
    int id;
    char name[30];
    int quantity;
    float price;
};

class shoppingList{
    struct item* items;
    int size;
    int total;
    int quantity;

    public:

        shoppingList(int n){                                              // construct list of size n
            items = (item*)malloc(n * sizeof(item));                          
            total = 0;
            quantity = 0;
            size = -1;
        }

        void addItem();
        void deleteItem(int index);
        void showList();
};

void shoppingList::addItem(){
    item a;
    std::cin.ignore(100,'\n');
    std::cout<<"\n\nENTER ITEM NAME: ";
    std::cin.getline(a.name,30);
    std::cout<<"ENTER ITEM CODE: ";
    std::cin>>a.id;
    std::cout<<"ENTER QUANTITY: ";
    std::cin>>a.quantity;
    std::cout<<"ENTER PRICE:";
    std::cin>>a.price;

    this->size++;
    items[size] = a;

    this->total += a.quantity * a.price;
    this->quantity += a.quantity;
}

void shoppingList::deleteItem(int index){

    if(this->size <= 0){
        std::cout<<"UNDERFLOW! CANNOT DELETE";
        return;
    }

    this->total -= items[index].quantity * items[index].price;
    this->quantity -= items[index].quantity;

    while(index < size){
        items[index] = items[index + 1];
        index++;
    }
    this->size--;
}

void shoppingList::showList(){
int i = 0;
while(i <= this->size){
    std::cout<<"\n---------------";
    std::cout<<"\nNAME: "<<items[i].name;
    std::cout<<"\nID: "<<items[i].id;
    std::cout<<"\nQUANTITY: "<<items[i].quantity;
    std::cout<<"\nPRICE: "<<items[i].price;
    std::cout<<"\n-------------";
    i++;
}

std::cout<<"\nNO. OF ITEMS: "<<this->quantity;
std::cout<<"\nTOTAL COST: "<<this->total;
}

int main(){
int n = 0;
int choice = 0;
int index = 0;

std::cout<<"ENTER SIZE: ";
std::cin>>n;

shoppingList list(n);

while(true){
std::cout<<"\n\n--- MENU ---";
std::cout<<"\n1. ADD ITEM";
std::cout<<"\n2. DELETE ITEM";
std::cout<<"\n3. DISPLAY";
std::cout<<"\n4. EXIT";
std::cout<<"\nENTER CHOICE: ";
std::cin>>choice;

switch(choice){
    case 1:
        list.addItem();
        break;
    
    case 2:
        std::cout<<"ENTER INDEX OF DELETION:";
        std::cin>>index;
        list.deleteItem(index);
        break;

    case 3:
        list.showList();
        break;

    case 4:
        return 0;

    default:
        std::cout<<"Invalid Choice! Try again!";
 }
}
return 0;
}

