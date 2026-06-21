#include<iostream>
using namespace std;
int main()
{
    int num=1;
    cout<<"Enter number=";
    cin>>num;
    int sum=0;
    while(num>0)
        {
            sum=sum+num;
            num--;
        }
        cout<<"Sum="<<sum;

}
