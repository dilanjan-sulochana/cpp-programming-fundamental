#include<iostream>
using namespace std;
int main()
{
    char word[]={"ghfyuhjhjgrdrgbjuhki"};
    int vowels=0;
    int consonants=0;
    for(int i=0;word[i]!='\0';i++){
    char ch=word[i];
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
    }
    cout<<"Vowels= "<<vowels<<endl;
    cout<<"Consonants= "<<consonants<<endl;
}
