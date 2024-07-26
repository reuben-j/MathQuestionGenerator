#include <iostream>
#include <cstdlib>
#include <time.h>
#include <tuple>

using namespace std;

int returnRandomNumInRange(int upper) {
    srand(time(0));
    return rand() % upper;
}

tuple<char, int> getInfo() {
    char answer1;
    int digits;
    cout << "Would you like an addition, substraction, multiplication or division question? ";
    cin >> answer1;
    cout << "How many digits would you like to work with? ";
    cin >> digits;

    auto newTuple = make_tuple(answer1, digits);
    return newTuple;
}

int main() {
    
    tuple<char, int> newTuple = getInfo();
    char div = '/', mult = '*', add = '+', sub = '-';
    
    if(get<0>(newTuple) == div) {
        cout << "We shall divide with " << get<1>(newTuple) << " digits!";
    } else if(get<0>(newTuple) == mult) {
        cout << "We shall multiply with " << get<1>(newTuple) << " digits!";
    } else if(get<0>(newTuple) == add) {
        cout << "We shall add with " << get<1>(newTuple) << " digits!";
    } else if(get<0>(newTuple) == sub) {
        cout << "we shall subtract with " << get<1>(newTuple) << " digits!";
    } else {
        cout << "Improper choice";
    }
     
}