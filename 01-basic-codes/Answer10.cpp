#include<iostream>
using namespace std;
int main()
{

    float num1,num2,BMI;
    cout<<"Enter number Weight: ";
    cin>>num1;
    cout<<"Enter number Height: ";
    cin>>num2;
    BMI=num1/(num2*num2);
    if(BMI<18.5)
    {
        cout<<"Underweight"<<endl;
    }
    else if(BMI<24.9)
    {
        cout<<"Normal weight"<<endl;
    }
    else if(BMI<29.9)
        cout<<"Overweight"<<endl;
    else
    {
        cout<<"Obesity";
    }
}
