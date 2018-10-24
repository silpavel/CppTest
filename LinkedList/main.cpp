#include <iostream>
// The file consist of class LinkedList and some cases using it methods.
#include <ctime>
#include <cstdlib>
#include "link.h"
using namespace std;


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

    cout<<"\nCheck finding value by index\n";
    cout<<"input index=";

    cin>>index;
    cout<<"value="<<lst.get(index);// check "get"

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
