#include<iostream>
using namespace std;
int main()
{
    int marks[5];
    cout << "Enter 5 marks: " << endl;

    for(int i = 0; i < 5; i++)
    {
    cin >> marks[i]; // මෙතන i කියන එක 0, 1, 2, 3, 4 විදිහට මාරු වෙනවා
    }
    for(int i = 0; i < 5; i++)
    {
    cout<<marks[i]<<" ";
    }
}
