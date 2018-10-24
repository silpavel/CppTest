#include <iostream>
// The file consist of class LinkedList and some cases using it methods.
#include <ctime>
#include <cstdlib>
using namespace std;

class LinkedList
{
public:
    LinkedList();
    ~LinkedList(){cout<<"\nrun destructur\n";empt();};
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
        ~Elem(){};
        Elem *next;//Point to next element. Zero if the element is last
        int var;//a payload. We can use there point to value, array, or object
    };
    Elem *first;////If list do not keep anything then ZERO

};
int main()/////////////////////////////////////////////
{
    LinkedList lst;
    int index;
    srand(time('\0'));
    int num=1;
    //--------------------------
    cout<<"\nmake array addEnd\n";
    while(num!=2)//make array
    {
        num=rand()%10;
        lst.addEnd(num);
        cout<<num<<' ';
    }
    cout<<endl;
    //--------------------------
    cout<<"\nCheck array\n";
    lst.lookAll();//check "lookAll"
    //--------------------------
    /*
    cout<<"\nCheck finding value by index\n";
    cout<<"input index=";

    cin>>index;
    cout<<"value="<<lst.get(index);// check "get"
    */
    //--------------------------
    cout<<"\n\nCheck addMid\n";
    cout<<"put index=";
    cin>>index;
    cout<<"\nput value=";
    int value;
    cin>>value;
    lst.addMid(value,index);
    //--------------------------
    cout<<"\nCheck array\n";
    lst.lookAll();//check "lookAll"

    return 0;
}/////////////////////////////////////////////////////////
LinkedList::LinkedList()
{
    cout<<"run constructor\n";
    sizeList=0;// if 0 that list do not keep anything
    int *Elem=NULL;////If list do not keep anything then ZERO
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
int LinkedList::get(int index)
{
    if( index>=sizeList || !sizeList )
        return 0;
    int bufind=0;
    Elem *pindex=first;
    while(bufind!=index)
    {
        pindex=pindex->next;
        bufind++;
    }
    return pindex->var;
}
void LinkedList::addMid(int i, int index)
{


    if( index>=sizeList || !sizeList || index<0)
        addEnd(i);
    else if (!index)
    {
        Elem *bufnext=first;
        first=new Elem(i);
        first->next=bufnext;
        sizeList++;
    }
    else
    {
        int bufind=0;
        Elem *pindex=first;
        while(bufind!=index-1)
        {
            pindex=pindex->next;
            bufind++;
        }

        Elem *bufnext=pindex->next;
        pindex->next=new Elem(i);
        pindex->next->next=bufnext;
        sizeList++;
    }
}
void LinkedList::empt(){
    Elem* buf=first;
    sizeList=0;

    while(buf){
        buf=first->next;
        cout<<(int)first<<" value="<<first->var<<" deleted\n";
        delete first;
        first=buf;
    }
    cout<<"All elements deleted";
}

