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

Coffeebooth *randomCustomer();

int main() {
    srand(time(0));

    Coffeebooth *coffeeHead = nullptr;
    for (int i = 0; i < INTIIAL_QUUEUE; i++) {
        Coffeebooth
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
