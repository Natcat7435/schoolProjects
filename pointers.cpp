#include <iostream>
using namespace std;

int *getNum(int wholeNum) {
    cout << "Enter a number: ";
    cin >> wholeNum;
    return &wholeNum;
}

int main() {
  int wholeNum = 0;
int *pint = getNum(wholeNum);
cout << *pint;

}