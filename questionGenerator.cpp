#include <iostream>
#include <cstdlib>
#include <time.h>
#include <tuple>

using namespace std;

int returnRandomNumInRange(int upper) {
    srand(time(0));
    return rand() % upper;
}

tuple<string, int> getInfo() {
    string answer1;
    int digits;
    cout << "Would you like an addition, substraction, multiplication or division question? ";
    cin >> answer1;
    cout << "How many digits would you like to work with? ";
    cin >> digits;

    auto newTuple = make_tuple(answer1, digits);
    return newTuple;
}

int main() {
    
    tuple<string, int> newTuple = getInfo();
    
    
}