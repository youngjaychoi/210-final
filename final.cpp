#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <queue>
#include <list>
using namespace std;

const int INTIIAL_QUUEUE = 3;
const int SIMULATION_ROUND = 10;

string names[] = {"customer1", "customer2", "customer3", "customer4", "customer5"};
string drinks[] = {"drink1", "drink2", "drink3", "drink4", "drink5"};

struct Coffeebooth {
    string custumer;
    string order;
    Coffeebooth *next;
};

struct Customer {
    string name;
    string drink;
};

Coffeebooth *randomCustomer();
Customer randomCustomerStruct();

void serveCoffee(Coffeebooth *&head) {
    if (head != nullptr) {
        Coffeebooth *temp = head;
        head = head->next;
        delete temp;
    }
}

void displayCoffee(Coffeebooth *head) {
    
}

int main() {
    srand(time(0));

    Coffeebooth *coffeeHead = nullptr;
    for (int i = 0; i < INTIIAL_QUUEUE; i++) {
        Coffeebooth *customer = randomCustomer();
        customer->next = coffeeHead;
        coffeeHead = customer;
    }

    deque<Customer> muffinQueue;
    vector<Customer> braceletQueue;
    queue<Customer> customQueue;
    
    for (int round = 1; round <= SIMULATION_ROUND; round++) {
        cout << "\nRound " << round << endl; 
    
        if (coffeeHead != nullptr) {
            cout << "Customer name: " << coffeeHead->custumer << endl;
            serveCoffee(coffeeHead);
        }
        if (rand() % 2) {
            Coffeebooth *newCustomer = randomCustomer();
            newCustomer->next = coffeeHead;
            coffeeHead = newCustomer;
        }

        if (!muffinQueue.empty()) {
            cout << "Customer name: " << muffinQueue.front().name << endl;
            muffinQueue.pop_front();
        }
        if (rand() % 2) {
            muffinQueue.push_back(randomCustomerStruct());
        }
        cout << "Muffin Booth Queue";
        for (auto &customer : muffinQueue) {
            cout << "    name: " << customer.name << ", drink: " << customer.drink << endl;
        }
        cout << endl;

        if (!braceletQueue.empty()) {
            cout << ""
        }
    
    
    
    
    
    
    }






    return 0;
}

Coffeebooth *randomCustomer() {
    Coffeebooth *newCustomer = new Coffeebooth;
    newCustomer->custumer = names[rand() % 5];
    newCustomer->order = drinks[rand() % 5];
    newCustomer->next = nullptr;
    return newCustomer;
}

Customer randomCustomerStruct() {
    return {names[rand() % 5], drinks[rand() % 5]};
}



