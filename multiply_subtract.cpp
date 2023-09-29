int multiply(int, int);
int subtract(int, int&);

int main() {
    int a = 3;
    int b = 2;
    int c = 0;             // After this line, c has the value 0
    c = multiply(2, 3);    // What is the value of c after this line? 3
    c = subtract(a, b =-1);    // What is the value of c after this line? 1
    c = b;                 // What is the value of c after this line? -1
    return 0;
}

int multiply(int p1, int p2) {
    return p1 * p2;
}

int subtract(int firstNum, int& secondNum) {
    int difference = firstNum - secondNum;
    secondNum = secondNum - firstNum;
    return difference;
}