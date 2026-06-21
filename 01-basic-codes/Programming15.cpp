#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter your number=";
    cin>>num;
    int sum=0;
    for(int i=num;i>0;i--)
        sum=sum+i;
    cout<<"Sum="<<sum;
}
