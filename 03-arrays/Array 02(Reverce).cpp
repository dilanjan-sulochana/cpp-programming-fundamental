#include<iostream>
using namespace std;
int main()
{
    int marks[5];
    for(int i=0;i<5;i++)
    {
        cout<<"Enter your value=";
        cin>>marks[i];
    }
    for(int i=0;i<5;i++)
    {
        cout<<marks[i]<<" ";
    }
    cout<<endl;
    cout<<"Reverce Order"<<endl;
    cout<<endl;
    for(int i=4;i>=0;i--)
    {
        cout<<marks[i]<<" ";
    }
}
