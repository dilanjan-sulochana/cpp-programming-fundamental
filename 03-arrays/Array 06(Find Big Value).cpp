#include<iostream>
using namespace std;
int main()
{
    int marks[6];
    for(int i=0;i<6;i++)
    {
        cout<<"Enter five marks: ";
        cin>>marks[i];
    }
    cout<<endl;
    for(int i=5;i>=0;i--)
    {
        cout<<marks[i]<<" ";
    }
}
