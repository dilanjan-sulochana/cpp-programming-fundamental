#include<iostream>
using namespace std;
double averagecal(int x,int y,int z)
{
    double sum=x+y+z;
    double average=sum/3;
    return average;
}
double averagecal2()
{
    int x=30;
    int y=10;
    int z=40;
    double sum2=x+y+z;
    double average2=sum2/3;
    return average2;
}
double averagecal3(int x,int y,int z)
{
    double sum3=x+y+z;
    double average3=sum3/3;
    cout<<average3;
}
int main()
{
    double output=averagecal(2,6,5);
    cout<<output<<endl;

    double output2=averagecal2();
    cout<<output2<<endl;

    double output3=averagecal3(3,6,8);
}
