#include<iostream>
using namespace std;
int main()
{
    int num1,num2;
    cout<<"Enter your number=";
    cin>>num1;
    cout<<"Enter your number=";
    cin>>num2;
    if(num1>num2)
    {
        cout<<"num1 is greater"<<endl;
        for(int i=1;i<=10;i++)
        cout<<i<<"*"<<num1<<"="<<i*num1<<endl;
    }
       else
       {
           cout<<"num2 is greater"<<endl;
           for(int i=1;i<=10;i++)
            cout<<i<<"*"<<num2<<"="<<i*num2<<endl;
       }
}
