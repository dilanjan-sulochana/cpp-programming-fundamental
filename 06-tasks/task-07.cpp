#include<iostream>
using namespace std;

    int findLow(int Marks[], int size){
    int Lowmark=Marks[0];
    int IndexLow=0;
    for(int i=0;i<size;i++)
    {
        if(Marks[i]<Lowmark)
        {
            Lowmark=Marks[i];
            IndexLow=i;
        }
    }
    cout<<"Lowmark= "<<Lowmark<<endl;
    cout<<"IndexLow= "<<IndexLow;
    return IndexLow;




    void findgrade(int Marks[],char grade[],int size);
    for(int i=0;i<size;i++)
        if(Marks[i]>=80)
    {
        grade[i]="A";
    }
    else if(Marks[i]>=70)
    {
        grade[i]="B";
    }
    else if(Marks[i]>=50)
    {
        grade[i]="C";
    }
    else if(Marks[i]>=35)
    {
        grade[i]="D";
    }
    else
    {
        grade[i]="F";
    }

    }
    }
int main()
{
    int Marks[10]={87,90,65,40,64,78,50,49,40,79};
    int size=10;
    char grade[10]={};
    }
