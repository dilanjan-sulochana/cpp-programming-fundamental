#include<iostream>
using namespace std;
int main()
{

    int num1;
    cout<<"Enter number of days: ";
    cin>>num1;
    if(num1<5)
    {
        cout<<"You pay $1."<<endl;
    }
    else if(num1<10)
    {
            cout<<"You pay $2"<<endl;
    }
    else if(num1<30)
    {
        cout<<"You pay $5."<<endl;
    }
    else
    {
        cout<<"Your membership is suspended."<<endl;
    }

}
