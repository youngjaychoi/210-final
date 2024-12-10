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

string names[] = {};
string drinks[] = {};

struct Coffeebooth {
    string custumer;
    string order;
    Coffeebooth *next;
};

Coffeebooth *randomCustomer();


int main() {
    srand(time(0));

    





    return 0;
}

Coffeebooth *randomCustomer() {
    Coffeebooth *newCustomer = new Coffeebooth;
    



}
