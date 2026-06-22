#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    int mark[5];
    for(int i=0;i<5;i++)
    {
    cout<<"Enter your mark = ";
    cin>>mark[i];
    }
    for(int i=0;i<5;i++)
    {
        sum=sum+mark[i];
    }
    cout<<"Sum of array = "<<sum;
}
