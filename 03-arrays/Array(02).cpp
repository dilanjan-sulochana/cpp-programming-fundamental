#include<iostream>
using namespace std;
int main()
{
    int Arr[5]={2,4,6,8,10};
    int small=Arr[0];
    int large=Arr[0];

    for(int i=0;i<5;i++)
    {
            if(Arr[i]<small)
        {
            small=Arr[i];
        }
            if(Arr[i]>large)
        {
            large=Arr[i];
        }
    }
        cout<<"Large="<<large<<endl;
        cout<<"Small="<<small;
}
