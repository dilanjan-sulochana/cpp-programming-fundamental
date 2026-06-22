#include<iostream>
using namespace std;
int main()
{
    int marks[6]={57,78,98,54,100,80};
    int key;
    bool found= false;
    cout<<"Enter your mark: ";
    cin>>key;
    for(int i=0;i<6;i++)
    {
        if(marks[i]==key)
        {
            found=true;
            break;
        }
    }

        if(found==1true)
        {
            cout<<"Your mark in array";
        }
        else
        {
            cout<<"Your marks not in array";
        }
}
