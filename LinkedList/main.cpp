#include <iostream>
// The file consist of class LinkedList and some cases using it methods.
#include <ctime>
#include <cstdlib>
using namespace std;

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void addEnd(int i);//add value to end list
    void lookAll();// all list to screen
    int get(int index);//get element with the index
private:
    int sizeList;//If list do not keep anything then ZERO

    class Elem //member of the list (elements)
    {
    public:
        Elem(int i);
        ~Elem();
        Elem *next;//Point to next element. Zero if the element is last
        int var;//a payload. We can use there point to value, array, or object
    };
    Elem *first;////If list do not keep anything then ZERO

};
int main()/////////////////////////////////////////////
{
    LinkedList lst;
    srand(time('\0'));
    int num=1;
    while(num!=2)
    {
        num=rand()%10;
        lst.addEnd(num);
        cout<<num<<' ';
    }
    cout<<endl;
    lst.lookAll();
    cout<<"put index=";
    int index;
    cin>>index;
    cout<<"\nvalue="<<lst.get(index)<<endl;

    return 0;
}/////////////////////////////////////////////////////////
LinkedList::LinkedList()
{
    cout<<"run constructor\n";
    sizeList=0;// if 0 that list do not keep anything
    int *Elem=NULL;////If list do not keep anything then ZERO
}
LinkedList::~LinkedList()
{
    cout<<"run destructor\n";
}
void LinkedList::addEnd(int i)
{
    if(!sizeList) //if list is empty
    {
        sizeList=1;
        first=new Elem(i);
    }
    else//find last element
    {
        Elem *last=first;
        while(last->next)//find element that has zero pointer
        {
            last=last->next;//go by chain
        }
        sizeList++;
        last->next=new Elem(i);

    }


}
LinkedList::Elem::Elem(int i)
{
    next=NULL;
    var=i;
}
LinkedList::Elem::~Elem() {}
void LinkedList::lookAll()
{
    if (!sizeList)
        return;
    Elem *last=first;
    while(last->next)
    {
        cout<< last->var <<' ';
        last=last->next;
    }
    cout<< last->var <<' ';
    cout<<endl;
}
int LinkedList::get(int index){
    if( index>=sizeList || !sizeList) return 0;
    int bufind=0;
    Elem *pindex=first;
    while(bufind!=index){
        pindex=pindex->next;
        bufind++;
    }
    return pindex->var;
}

