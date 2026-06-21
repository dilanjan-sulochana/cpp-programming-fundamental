#include<iostream>
using namespace std;
int main()
{
    int size1, add_on, quantity;
    cout<<"Enter size (1=Small, 2=Medium, 3=Large): ";
    cin>>size1;
    cout<<"Add-ons? (1=Yes, 0=No): ";
    cin>>add_on;
    cout<<"Quantity: ";
    cin>>quantity;

    //Calculate Base price and find coffee size text
    int price1;
    string sizeTxt;
    if(size1==1)
    {
        price1=80;
        sizeTxt="Small";
    }
    else if(size1==2)
    {
        price1=110;
        sizeTxt="Medium";
    }
    else if(size1==3)
    {
        price1=140;
        sizeTxt="Large";
    }
    else
    {
        cout<<"Error!";
    }


    //Calculate Total(With add on option) price and find Add on text
    int total=0;
    string AddonTxt;
    if(add_on==1)
    {
        total=price1+20;
        AddonTxt="with cream & sugar";
    }
    else
    {
        total=price1+0;
        AddonTxt="without cream & sugar";
    }

    //Calculate Total bill
    int Final_Bill=total*quantity;









}
