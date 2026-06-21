#include<iostream>
using namespace std;
int main()
{
    int num1,num2,num3;
    cout<<"Your first number: ";
    cin>>num1;
    cout<<"Your second number: ";
    cin>>num2;
    cout<<"Your third number: ";
    cin>>num3;
    if(num1>num2 && num1>num3)
    {
        cout<<"Larger number is: "<<num1;
    }
    else if(num2>num1 && num2>num3)
    {
        cout<<"Larger number is: "<<num2;
    }
    else
    {
        cout<<"Larger number is: "<<num3;
    }
    return 0;
}
