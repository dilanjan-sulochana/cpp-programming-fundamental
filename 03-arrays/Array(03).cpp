#include<iostream>
using namespace std;
int main()
{
    int Arr[5]={2,4,6,8,10};

    {
    Arr[0]=Arr[4];
    Arr[1]=Arr[3];
    Arr[2]=Arr[2];
    Arr[3]=Arr[1];
    Arr[4]=Arr[0];
    }
    cout<<Arr[0]<<Arr[1]<<Arr[2]<<Arr[1]<<Arr[0];

}
