#include<iostream>
using namespace std;
int main(){
    string name,address;
    int age;
    cout<<"Enter your name:";
    cin>>name;
    cin.ignore();
    cout<<"Enter your last name:";
    //cin>>Name;
    getline(cin,name);
    cout<<"Enter your age:";
    cin>>age;
    cout<<"Enter your address:";
    cin>>address;
    cin.ignore();
    cout<<"Enter your next address:";
    //cin>>Address;
    getline(cin,address);
    cout<<"Name:"<<name<< endl;
    cout<<"Age:"<<age<< endl;
    cout<<"Address:"<<address<< endl;
    cout<<"Next Address:"<<address;
    }
