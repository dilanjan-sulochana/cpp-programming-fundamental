#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter number between 1 to 10=";
    cin>>num;
    while(num<1 || num>10)
    {
         cout<<"Invalid number try again"<<endl;
         cout<<"Enter other number=";
         cin>>num;
    }
    {
        cout<<"Thank you "<<num<<" enter to system";
    }

}
