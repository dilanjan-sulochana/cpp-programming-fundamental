#include<iostream>
using namespace std;
int main()
{
    float mon,mon2;
    cout<<"Enter your current balance: ";
    cin>>mon;
    cout<<"Enter your want money: ";
    cin>>mon2;
    if(mon2<=mon)
    {
        cout<<"Your current balance: "<<mon-mon2<<endl;
    }
    else
    {
        cout<<"---Insufficient Balance---";
    }
    return 0;
}
