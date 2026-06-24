#include<iostream>
#include<string>
using namespace std;
int vowel_cou(string word)
{
   int vowel_cou=0;
   int j=word.length();
   for(int i=0;i<j;i++)
   {
       if(word[i]=='a'|| word[i]=='e'|| word[i]=='i'|| word[i]=='o'|| word[i]=='u')
       {
        vowel_cou=vowel_cou+1;
       }
   }
        return vowel_cou;
}
int main()
{
    string text;
    cout<<"Enter Text= ";
    cin>>text;
    int count=vowel_cou(text);
    cout<<"Count of vowel letters="<<count;
}

