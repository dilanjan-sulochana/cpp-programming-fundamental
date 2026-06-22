#include<iostream>
using namespace std;
int main()
{
    int vowels=0;
    int consonants=0;
    string names[4];
    for(int i=0;i<4;i++)
    {
        cout<<"Enter four names in lowercase: ";
        cin>>names[i];
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<names[i].length();j++)
        {
            if(names[i]=='a' || names[i]=='a' || names[i]=='a' || names[i]=='a' || names[i]=='a')
            {
                vowels++ ;
            }
            else
            {
                cosonants++
            }
        }
    }
    cout<<"Count Of Vowels= "<<vowels<<endl;
    cout<<"Count Of Consonants= "<<consonants<<endl;
}
