#include<iostream>
using namespace std;
int main()
{

    int num1;
    cout<<"Enter number of age: ";
    cin>>num1;
    if(num1<12)
    {
        cout<<"Child"<<endl;
    }
    else if(num1<19)
    {
            cout<<"Teenager"<<endl;
    }
    else if(num1<64)
    {
        cout<<"Adult"<<endl;
    }
    else
    {
        cout<<"Senior"<<endl;
    }

}
