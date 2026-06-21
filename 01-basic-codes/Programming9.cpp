#include<iostream>
using namespace std;
int main()
{
    int num1,num2,num3;
    cout<<"Enter your First Number:";
    cin>>num1;
    cout<<"Enter your Second number:";
    cin>>num2;
    cout<<"Enter your Third number:";
    cin>>num3;
    if(num1>num2)
    {
        cout<<"Larger number is: "<<num1<<endl;
    }
        else
        {
            cout<<"Larger number is:"<<num2<<endl;
        }
        if(num3>num1)
        {
            cout<<"Lager number is:"<<num3<<endl;
        }
            else
            {
                cout<<"Larger number is:"<<num1<<endl;
            }



    return 0;
}
