#include<iostream>
using namespace std;
int main(){
    int N1,N2;
    cout<<"Enter your first number:";
    cin>>N1;

    cout<<"Enter your second number:";
    cin>>N2;

    cout<<"Sum of numbers="<<N1+N2<< endl;
    cout<<"Difference of numbers="<<N1-N2<< endl;
    N1+=N2;
    cout<<"Result No.01="<<N1<<endl;
    N1-=N2;
    cout<<"Result No.02="<<N1<< endl;
    N1*=N2;
    cout<<"Result No.03="<<N1;


    }
