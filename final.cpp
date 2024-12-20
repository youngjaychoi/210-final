#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <queue>
#include <list>
using namespace std;

const int INITIAL_QUEUE = 3;
const int SIMULATION_ROUND = 10;

string names[] = {"customer1", "customer2", "customer3", "customer4", "customer5"};
string drinks[] = {"drink1", "drink2", "drink3", "drink4", "drink5"};

struct Coffeebooth {
    string customer;
    string order;
    Coffeebooth *next;
};

struct Customer {
    string name;
    string drink;
};

Coffeebooth *randomCustomer();
Customer randomCustomerStruct();
void serveCoffee(Coffeebooth *&head);
void displayCoffee(Coffeebooth *head);

int main() {
    srand(time(0));

    Coffeebooth *coffeeHead = nullptr;
    for (int i = 0; i < INITIAL_QUEUE; i++) {
        Coffeebooth *customer = randomCustomer();
        customer->next = coffeeHead;
        coffeeHead = customer;
    }

    deque<Customer> muffinQueue;
    vector<Customer> braceletQueue;
    queue<Customer> icecreamQueue;

    for (int i = 0; i < INITIAL_QUEUE; i++) {
        muffinQueue.push_back(randomCustomerStruct());
        braceletQueue.push_back(randomCustomerStruct());
        icecreamQueue.push(randomCustomerStruct());
    }
    
    for (int round = 1; round <= SIMULATION_ROUND; round++) {
        cout << "\nRound " << round << endl; 
    
        //coffee
        if (coffeeHead != nullptr) {
            cout << "Serveing coffee booth customer name: " << coffeeHead->customer << endl;
            serveCoffee(coffeeHead);
        }
        if (rand() % 2) {
            Coffeebooth *newCustomer = randomCustomer();
            newCustomer->next = coffeeHead;
            coffeeHead = newCustomer;
        }
        displayCoffee(coffeeHead);

        //muffin
        if (!muffinQueue.empty()) {
            cout << "Serveing muffin booth customer name: " << muffinQueue.front().name << endl;
            muffinQueue.pop_front();
        }
        if (rand() % 2) {
            muffinQueue.push_back(randomCustomerStruct());
        }
        cout << "Muffin Booth Queue" << endl;
        for (auto &customer : muffinQueue) {
            cout << "    name: " << customer.name << ", drink: " << customer.drink << endl;
        }
        cout << endl;

        //bracelet
        if (!braceletQueue.empty()) {
            cout << "Serveing bracelet booth customer name: " << braceletQueue.front().name << endl;
            braceletQueue.erase(braceletQueue.begin());
        }
        if (rand() % 2) {
            braceletQueue.push_back(randomCustomerStruct());
        }
        cout << "Bracelet Booth Queue" << endl;
        for (auto &customer : braceletQueue) {
            cout << "    name: " << customer.name << ", drink: " << customer.drink << endl;
        }
        cout << endl;
    
        //queue
        if (!icecreamQueue.empty()) {
            cout << "Serveing icecream booth customer: " << icecreamQueue.front().name << endl;
            icecreamQueue.pop();
        }
        if (rand() % 2) {
            icecreamQueue.push(randomCustomerStruct());
        }
        cout << "Icecream booth queue" << endl;
        queue<Customer> tempQueue = icecreamQueue;
        while (!tempQueue.empty()) {
            cout << "    name: " << tempQueue.front().name << ", drink: " << tempQueue.front().drink << endl;
            tempQueue.pop();
        }
        cout << endl;
        cout << "----------------------" << endl;
    }

    while (coffeeHead != nullptr) {
        serveCoffee(coffeeHead);
    }

    return 0;
}

Coffeebooth *randomCustomer() {
    Coffeebooth *newCustomer = new Coffeebooth;
    newCustomer->customer = names[rand() % 5];
    newCustomer->order = drinks[rand() % 5];
    newCustomer->next = nullptr;
    return newCustomer;
}

Customer randomCustomerStruct() {
    return {names[rand() % 5], drinks[rand() % 5]};
}

void serveCoffee(Coffeebooth *&head) {
    if (head != nullptr) {
        Coffeebooth *temp = head;
        head = head->next;
        delete temp;
    }
}

void displayCoffee(Coffeebooth *head) {
    cout << "Coffee booth queue" << endl;
    while (head != nullptr) {
        cout << "    name: " << head->customer << ", drink: " << head->order << endl;
        head = head->next;
    }
    cout << endl;
}
