#include <iostream>
#include <string>
#include <list>
#include "Header.h"
int main()
{
    Stack<int>* stek;
    stek = new Stack<int>();
    stek->push(1);
    stek->push(20);
    stek->push(33);
    stek->push(41);
    stek->push(52);
    stek->peek();
    stek->del();
    stek->peek();
    cout << endl << stek << endl; 
}