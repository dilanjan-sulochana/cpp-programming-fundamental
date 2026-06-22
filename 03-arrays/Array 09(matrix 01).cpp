#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    int rowsum,columnsum=0;
    int matrix[3][2]={
              {2,3},
              {5,7},
              {6,8}};
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cout<<matrix[i][j]<<" ";
            sum=sum+matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Total sum= "<<sum;
    cout<<endl;

    for(int i=0;i<3;i++){
            rowsum=0;
        for(int j=0;j<2;j++){
            rowsum=rowsum+matrix[i][j];
        }
        cout<<endl;
        cout<<"Row"<<i+1<<"-"<<rowsum;
     }
     cout<<endl;
      for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            columnsum=0;
            columnsum=columnsum+matrix[i][j];
        }
    }
    for(int j=0;j<2;j++){
    cout<<"Column"<<j+1<<"-"<<columnsum<<endl;}
}
