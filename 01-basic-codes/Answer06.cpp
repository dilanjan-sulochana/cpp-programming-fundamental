#include<iostream>
using namespace std;
int main()
{
    int num1;
    cout<<"Enter your temperature: ";
    cin>>num1;
    if(num1>30)
    {
        cout<<"It's hot."<<endl;
    }
        else if(num1<10)
        {
            cout<<"It's cold."<<endl;
        }
        else
        {
            cout<<"It's moderate.";
        }
        return 0;
}
