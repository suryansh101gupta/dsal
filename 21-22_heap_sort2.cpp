#include <iostream>
using namespace std;
class heap_sort
{
    public:
    void Insert(int A[],int n)
    {
    int i=n,temp;
    temp=A[i];
    while(i>1 && temp>A[i/2])
    {
    A[i]=A[i/2];
    i=i/2;
    }
    A[i]=temp;
    }


    int Delete(int A[],int n)
    {
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;j=i*2;
    while(j<=n-1)
    {
    if(j<n-1 && A[j+1]>A[j])
    j=j+1;
    if(A[i]<A[j])
    {
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
    i=j;
    j=2*j;
    }
    else
    break;
    }
    return val;
    }
};

int main() 
{
    heap_sort obj;

    int n;
    cout<<"Enter the number of element in the array you want to sort: ";
    cin>>n;
    int H[n+1];
    H[0]=0;


    cout<<"Enter the elements: "<<endl;
    for(int j=1;j<=n;j++)
    {
        cin>>H[j];
    }

    int i;

    for(i=2;i<=n;i++)
    obj.Insert(H,i);

    cout<<"Heap is: "<<endl;
    for(i=1;i<=n;i++) 
    {
        cout<<H[i]<<" ";
    }

    cout<<"\nAfter sorting: "<<endl;
    for(i=n;i>1;i--) 
    {
    obj.Delete(H,i);
    }

    for(i=1;i<=n;i++)
    printf("%d ",H[i]);
    printf("\n");

    return 0;
} 

//Input: 10 20 30 25 5 40 35