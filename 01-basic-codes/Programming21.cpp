#include<iostream>
using namespace std;
int main()
{
    int num;
    int sum=0;
    cout<<"!....Enter numbers without 0, if you add 0 loop is stop....!"<<endl;
    cout<<endl;
    while(num!=0)
    {
       cout<<"Enter number=";
       cin>>num;
       sum=sum+num;
    }
    cout<<"Sum="<<sum;
}
