
#include "link.h"

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
void LinkedList::empt()
{
    Elem* buf=first;
    sizeList=0;

    while(buf)
    {
        buf=first->next;
        cout<<(int)first<<" value="<<first->var<<" deleted\n";
        delete first;
        first=buf;
    }
    cout<<"All elements deleted";
}

