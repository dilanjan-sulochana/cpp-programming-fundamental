#include<iostream>
using namespace std;
int main()
{
    int Arr[5];
    int i=0;
    while(i<5)
    {
        cout<<"Enter value "<<i<<" :";
        cin>>Arr[i];
        i++;
    }
    cout<<endl;
    cout<<endl;
    cout<<"Your array values are:"<<endl;
    cout<<endl;

    i=0;
    while(i<5)
    {
        cout<<Arr[i]<<" ";
        i++;
    }
}
