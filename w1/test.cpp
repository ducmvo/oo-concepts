#include <iostream>
using namespace std;

int main() {
    unsigned        x = 5;
    int             y;
    bool            flag = true;
    float           pi = 3.14159;
    const int       two = 2;
    float           floatX = two * pi;

    // string str = (x>0)?"true":"false";
    // cout << floatX << endl;
    // executable statement #1
    // while ( x > 0){
        
    //     // y--;
    //     x/=10;
    //     x--;
    //     cout << x << endl;
    //     // break;
    // }

    // executable statement #2
    // while ( y > 0){
    //     cout << y << endl;
    //     y--;
    //     x--;
    //     break;
    // }

    // executable statement #3
          
    cin >> y;
    string str = (two<y)?"true":"false";
    cout << str << endl;

    // executable statement #4
    // cin >> y;
    // if (two < y)
    //     flag = true;
    // else
    //     flag = false;

    return 0;
}