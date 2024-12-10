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
void refillCoffee(Coffeebooth *&head);
void refillMuffin(deque<Customer> &queue);
void refillBracelet(vector<Customer> &queue);
void refillIcecream(queue<Customer> &queue);

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
            cout << "Coffee booth customer name: " << coffeeHead->customer << endl;
            serveCoffee(coffeeHead);
        }
        if (rand() % 2) {
            Coffeebooth *newCustomer = randomCustomer();
            newCustomer->next = coffeeHead;
            coffeeHead = newCustomer;
        }
        refillCoffee(coffeeHead);
        displayCoffee(coffeeHead);

        //muffin
        if (!muffinQueue.empty()) {
            cout << "Muffin booth customer name: " << muffinQueue.front().name << endl;
            muffinQueue.pop_front();
        }
        if (rand() % 2) {
            muffinQueue.push_back(randomCustomerStruct());
        }
        refillMuffin(muffinQueue);
        cout << "Muffin Booth Queue" << endl;
        for (auto &customer : muffinQueue) {
            cout << "    name: " << customer.name << ", drink: " << customer.drink << endl;
        }
        cout << endl;

        //bracelet
        if (!braceletQueue.empty()) {
            cout << "Bracelet booth customer name: " << braceletQueue.front().name << endl;
            braceletQueue.erase(braceletQueue.begin());
        }
        if (rand() % 2) {
            braceletQueue.push_back(randomCustomerStruct());
        }
        refillBracelet(braceletQueue);
        cout << "Bracelet Booth Queue" << endl;
        for (auto &customer : braceletQueue) {
            cout << "    name: " << customer.name << ", drink: " << customer.drink << endl;
        }
        cout << endl;
    
        //queue
        if (!icecreamQueue.empty()) {
            cout << "Icecream booth customer: " << icecreamQueue.front().name << endl;
            icecreamQueue.pop();
        }
        if (rand() % 2) {
            icecreamQueue.push(randomCustomerStruct());
        }
        refillIcecream(icecreamQueue);
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

void refillCoffee(Coffeebooth *&head) {
    int count = 0;
    Coffeebooth *temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        count++;
    }
    while (count < INITIAL_QUEUE) {
        Coffeebooth *newCustomer = randomCustomer();
        newCustomer->next = head;
        head = newCustomer;
        count++;
    }
}

void refillMuffin(deque<Customer> &queue) {
    queue.clear();
    for (int i = 0; i < INITIAL_QUEUE; i++) {
        queue.push_back(randomCustomerStruct());
    }
}

void refillBracelet(vector<Customer> &queue) {
    queue.clear();
    for (int i = 0; i < INITIAL_QUEUE; i++) {
        queue.push_back(randomCustomerStruct());
    }
}
void refillIcecream(queue<Customer> &queue) {
    while (!queue.empty()) {
        queue.pop();
    }
    for (int i = 0; i < INITIAL_QUEUE; i++) {
        queue.push(randomCustomerStruct());
    }
}
