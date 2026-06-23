#include<iostream>
using namespace std;
int main()
{
    int num;
    int sum=0;
    cout<<"Enter your number: ";
    cin>>num;
    for(int i=1;i<10;i++)
    {
      int n;
      cout<<"Enter your number: ";
      cin>>num;
      sum=sum+num;
    }
    {
        cout<<"Sum="<<sum;
    }
}
