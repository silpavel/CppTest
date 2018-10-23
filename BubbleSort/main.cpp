#include <iostream>
#include <cstdlib>
//bobble sort (only for int)
using namespace std;
void bubbleSort(int *, int);//find min from n members, then find min  from n-1  etc

int main()
{
    int size=1;
    int arr[size];
    for(int i=0; i<size; i++)
    {
        arr[i]=rand()%10;
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    bubbleSort(arr,size);
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
void bubbleSort(int *pi, int size)//"pi" is a pointer to int array, "size" is size of an array
{
    if(!pi || size<=1)
        return;
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(pi[j]<pi[i])
            {
                int buf=pi[j];
                pi[j]=pi[i];
                pi[i]=buf;
            }
        }
    }
}
