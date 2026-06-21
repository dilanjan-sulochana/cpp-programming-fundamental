#include <iostream>
using namespace std;
int main(){
    int num1,num2,temp;
    cout<<"Enter your number 01= ";
    cin>>num1;
    cout<<"Enter your number 02= ";
    cin>>num2;
    temp=num1;
    num1=num2;
    num2=temp;
    cout<<"---Initial---"<<endl;
    cout<<"Number01= "<<temp<<endl;
    cout<<"Number02= "<<num1<<endl;
    cout<<endl;
    cout<<"---Final---"<<endl;
    cout<<"Number01= "<<num1<<endl;
    cout<<"Number02= "<<num2;
    }
