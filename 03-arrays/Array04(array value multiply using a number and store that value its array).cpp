#include<iostream>
using namespace std;
int main()
{
    int number[6];
    for(int i=0;i<6;i++)
    {
        cout<<"Enter value= ";
        cin>>number[i];
    }
    for(int i=0;i<6;i++)
    {
        if(number[i]=number[i]*2)
        {
            cout<<number[i]<<" ";
        }
    }
}
