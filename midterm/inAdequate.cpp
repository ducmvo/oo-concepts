//
// Created by Duc Vo on 2/7/22.
//

#include "inAdequate.h"
#include <iostream>
#include <memory>
using namespace std;

inAdequate::inAdequate(int num) {
    data = new int[num];
    this->num = num;
}
inAdequate::~inAdequate() {
    delete[] data;
    data = nullptr;
}
//inAdequate::inAdequate(const inAdequate& src) {
//    num = src.num;
//    data = new int[num];
//}

inAdequate& inAdequate::operator=(const inAdequate &src) {
    if (this != &src) {
        delete [] data;
        num = src.num;
        data = new int[num];
    }
    return *this;
}

//inAdequate& inAdequate::operator=(inAdequate &&src) {
//    if (this != &src) {
//        delete [] data;
//        num = src.num;
//        data = src.data;
//    }
//
//    src.data = nullptr;
//    src.num = 0;
//
//    return *this;
//}


class Adequate {
public:
    Adequate(int num) {
        cout << "Adequate Constructor " << num << endl;
    }
};

class yNot {
private:
    unsigned int num;

public:
    yNot(): num(0) {};
    yNot(unsigned int num): num(num) {};
    int getValue() {
        return num;
    }
};

yNot getDB(unsigned int seed, unsigned int size) {
    if (size == 0 || seed > size) return 0;
    yNot myDB[size];
    for (int k = 0; k < size; k++) {
        yNot local(seed * k);
        myDB[k] = local;
    }
    yNot minObj = myDB[0];
    for (int k = 1; k < size; k++) {
        if ( myDB[k].getValue() > minObj.getValue())  {
            minObj = myDB[k];
        }
    }
    cout << minObj.getValue() << endl;
    cout << &minObj << endl;
    cout << minObj.getValue() << endl;
    return minObj;
}

int main() {
    yNot obj = getDB(5,0);
    cout << obj.getValue() << endl;
    return 0;
}