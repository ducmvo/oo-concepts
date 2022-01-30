#include <iostream>
#include <memory>
using namespace std;

class Leak
{
private:
    const static int value = 100;
    int *heapData;

public:
    Leak(int val = 2)
    {
       
        heapData = new int[val];
    }

    ~Leak()
    {
        cout << "CLEAR MEMORY: " << this << endl;
        delete[] heapData;
    }

    Leak(const Leak &src)
    {
        cout << "COPY CONSTRUCTOR" << endl;
        heapData = new int[2];
    }

    Leak(Leak &&src)
    {
        cout << "MOVE CONSTRUCTOR" << endl;
        heapData = src.heapData;
        // prevent the src contructor to delete the heapData reference
        src.heapData = nullptr;
    }

    Leak &operator=(const Leak &src)
    {
        cout << "COPY OPERATOR" << endl;
        if (this == &src)
            return *this;
        delete[] heapData;
        heapData = new int[2];
        return *this;
    }

    void print()
    {
        cout << "HEAP DATA: " << heapData << endl;
    }
};

void leak1(Leak local)
{
    cout << "LOCAL ADDRESS 1: " << &local << endl;
    local.print();
}

int main()
{
    // Leak leak(2);

    // cout << "MAIN ADDRESS : " << &leak << endl;

    // // leak1((Leak &&) leak);

    // leak1(move(leak));
    // leak1(move(leak));


    unique_ptr<Leak> leakptr =  make_unique<Leak>(3);

    // leakptr->print();
    leak1(move(*leakptr));
    leak1(move(*leakptr));

    return 0;
    // 1111 1111  1111 1111  1111 1111  1111 1111
    // 32 bits
    // 4 bytes
    // xx xx xx xx
};
