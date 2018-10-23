#include <iostream>
// The file consist of class LinkedList and some cases using it methods.
using namespace std;

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    //void addEnd();
private:
    int sizeList;//If list do not keep anything then ZERO
    int *Elem;////If list do not keep anything then ZERO
    struct Elem //member of the list (elements)
    {
        Elem *next;//Point to next element. Zero if the element is last
        int pi;//a payload. We can use there point to value, array, or object
    };

};
int main()
{
    LinkedList lst;
    return 0;
}
LinkedList::LinkedList()
{
    cout<<"run constructor\n";
    sizeList=0;// if 0 that list do not keep anything
}
LinkedList::~LinkedList()
{
    cout<<"run destructor\n";
}
