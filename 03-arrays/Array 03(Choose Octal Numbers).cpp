#include<iostream>
using namespace std;
int main()
{
    int age[10];
    int f=1;
    for(int i=0;i<10;i++)
    {
        cout<<"Enter value "<<f<<" = ";
        cin>>age[i];
        f++;
    }
    for(int i=0;i<10;i++)
    {
        age[i]=age[i]*2;
        {
            cout<<age[i]<<" ";
        }
    }
}
