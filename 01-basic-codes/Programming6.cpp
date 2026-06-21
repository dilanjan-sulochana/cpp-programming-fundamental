#include<iostream>
using namespace std;
int main()
{
    double gpa=3.45;
    bool isPass=true;

    bool x=(gpa>3.0 && isPass);
    bool y=(gpa<3.0 || isPass);
    bool z=!(gpa<3.0 || isPass);
    cout<<"gpa > 3.0 && isPass)is "<<x<<endl;
    cout<<"(gpa < 3.0 || isPass)is "<<y<<endl;
    cout<<"!(gpa < 3.0 || isPass)is "<<z;
}
