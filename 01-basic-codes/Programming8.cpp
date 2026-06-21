#include<iostream>
using namespace std;
int main()
{
    int num1;
    cout<<"Enter your number: ";
    cin>>num1;
    if(num1>0)
    {
        if(num1>3)
        {
            cout<<"Your Number Is Positive Number and Your Number Is Greater Than 3"<<endl;
        }
            string result=(num1>100)? "The number is greater than 100." : "The number is not greater than 100.";
            cout<<result;
    }
    return 0;
}
