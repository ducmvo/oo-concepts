// Author:      Duc Vo
// Filename:    jumpPrime.h
// Date:        January 28, 2022,
// Version:     1.0
// Description:
// Input:
// Process:
// Output:

#include <iostream>
#include "jumpPrime.h"

using namespace std;

int sampleFunc(void*);
// This function ...
// IN:
// MODIFY:
// OUT:

int main() {
    jumpPrime jp(64376);

    while (jp.isActive()) {
        jp.up();
    }
    jp.revive();
    cout << jp.up() << " | " << jp.isDead() << endl;
    jp.revive();

    cout << jp.up() << " | " << jp.isDead() << endl;
    cout << jp.up() << " | " << jp.isActive() << endl;

    return 0;
}