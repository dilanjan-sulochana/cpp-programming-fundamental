#include<iostream>
using namespace std;
int main()
{
    int age[6];
    for(int i=0;i<6;i++)
    {
        cout<<"Enter your age= ";
        cin>>age[i];
    }
    for(int i=0;i<6;i++)
    {
        age[i]=age[i]+3;
            cout<<age[i]<<" ";
    }
}
