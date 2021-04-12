#include <iostream>
#include <string>
#include <list>
#include "Header.h"
int main()
{
    Stack* stek;
    stek = new Stack();
    stek->push(1);
    stek->push(2);
    stek->push(3);
    stek->push(4);
    stek->push(5);
    Stack* stuk;
    stuk = new Stack();
    stuk->push(5);
    stuk->push(4);
    stuk->push(55);
    stuk->push(2);
    stuk->push(1);
    stuk = stek;
    cout << stuk; 
}