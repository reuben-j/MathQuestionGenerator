#include <iostream>
#include <cstdlib>
#include <time.h>
#include <tuple>


using namespace std;

double returnRandomNumInRange(int upper) {
    int sum = 1;
    for(int i = 0; i < upper; i++) {
        sum *= 10;
    }
    srand(time(0));
    return rand() % sum;
}
double returnSmallerNumInRange(int upper) {
    int sum = 1;
    for(int i = 0; i < upper -1; i++) {
        sum *= 10;
    }
    srand(time(0)+1);
    return rand() % sum;
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
    
    double actualAnswer = 0.00, userAnswer = 0.00;
    tuple<char, int> newTuple = getInfo();
    char div = '/', mult = '*', add = '+', sub = '-';
    
    if(get<0>(newTuple) == div) {
        cout << "We shall divide with " << get<1>(newTuple) << " digits!" << endl;
        cout << "What is " << returnRandomNumInRange(get<1>(newTuple)) << " " << div << " " <<  returnSmallerNumInRange(get<1>(newTuple)) << "?";
        actualAnswer = returnRandomNumInRange(get<1>(newTuple)) / returnSmallerNumInRange(get<1>(newTuple)) * 1.00;


    } else if(get<0>(newTuple) == mult) {
        cout << "We shall multiply with " << get<1>(newTuple) << " digits!" << endl;
        cout << "What is " << returnRandomNumInRange(get<1>(newTuple)) << " " << mult << " " << returnSmallerNumInRange(get<1>(newTuple)) << "?";
        actualAnswer = returnRandomNumInRange(get<1>(newTuple)) * returnSmallerNumInRange(get<1>(newTuple)) * 1.00;


    } else if(get<0>(newTuple) == add) {
        cout << "We shall add with " << get<1>(newTuple) << " digits!" << endl;
        cout << "What is " << returnRandomNumInRange(get<1>(newTuple)) << " " << add << " " << returnSmallerNumInRange(get<1>(newTuple)) << "?";
        actualAnswer = returnRandomNumInRange(get<1>(newTuple)) + returnSmallerNumInRange(get<1>(newTuple)) * 1.00;


    } else if(get<0>(newTuple) == sub) {
        cout << "we shall subtract with " << get<1>(newTuple) << " digits!" << endl;
        cout << "What is " << returnRandomNumInRange(get<1>(newTuple)) << " " << sub << " " << returnSmallerNumInRange(get<1>(newTuple)) << "?";
        actualAnswer = returnRandomNumInRange(get<1>(newTuple)) - returnSmallerNumInRange(get<1>(newTuple)) * 1.00;

    } else {
        cout << "Improper choice";
    }
    
    cout << endl << "Answer: ";
    cin >> userAnswer;
    if(userAnswer == roundf(actualAnswer * 100) / 100) {
        cout << "Nice one! The answer was: " << roundf(actualAnswer * 100) / 100;
    } else {
        cout << "Wrong, the answer was: " << roundf(actualAnswer * 100) / 100;
    }
    
}