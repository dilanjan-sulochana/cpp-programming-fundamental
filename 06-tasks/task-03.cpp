#include<iostream>
using namespace std;
int main()
{
    int N;
    cout<<"Enter Number: ";
    cin>>N;
    int sum=0;
    for(int i=N;i>=1;i--)
    {
        cout<<"i="<<i<<endl;
        sum=sum+i;
    }
    cout<<"Sum of i values= "<<sum;
}
