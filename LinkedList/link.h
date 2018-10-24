#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
#include <iostream>
using namespace std;
class LinkedList
{
public:
    LinkedList();
    ~LinkedList()
    {
        cout<<"\nrun destructur\n";
        empt();
    };
    void addEnd(int i);//add value to end list
    void lookAll();// all list to screen
    int get(int index);//get element with the index
    void addMid(int i, int index);//a new element will be instead index-element
    void empt();//to empty the array
private:
    int sizeList;//If list do not keep anything then ZERO

    class Elem //member of the list (elements)
    {
    public:
        Elem(int i);
        ~Elem() {};
        Elem *next;//Point to next element. Zero if the element is last
        int var;//a payload. We can use there point to value, array, or object
    };
    Elem *first;////If list do not keep anything then ZERO

};


#endif // LINK_H_INCLUDED
