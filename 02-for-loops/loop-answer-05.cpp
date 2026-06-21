#include<iostream>
using namespace std;
int main()
{
    int mark;
    cout<<"Enter your marks=";
    cin>>mark;
    if(mark>=40)
    {
        cout<<"Pass"<<endl;
    }
    else
    {
        cout<<"Fail"<<endl;
    }
    int stars;
    if(mark>=90)
    {
        stars=5;
    }
    else if(mark>=80)
    {
        stars=4;
    }
    else if(mark>=70)
    {
        stars=3;
    }
    else if(mark>=60)
    {
        stars=2;
    }
    else if(mark>=50)
    {
        stars=1;
    }
    else
    {
        stars=0;
        cout<<"No stars";
    }
    for(int i=1;i<=stars;i++)
        cout<<"*";
}
