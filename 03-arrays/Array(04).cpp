#include<iostream>
using namespace std;
int main()
{
    int Arr[5]={'a','b','c','d','e'};
    int vol=Arr[0];
    int cons=Arr[0];
    int count1=0;
    int count2=0;

    for(int i=0;i<5;i++)
    {
            if(Arr[i]='a','e','i','o','o')
        {
            Arr[i]++;
        }
        count1=count1+1;
            if(Arr[i]='b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z')
        {
            Arr[i]++;
        }
        count2=count2+1;
    }
        cout<<"Count of vovels="<<count1<<endl;
        cout<<"Count of constants="<<count2;
}

