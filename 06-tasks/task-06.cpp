#include <iostream>


using namespace std;
//2.Find the lowest mark and display its index
    //: findLow(int marks[])
 int findLow(int marks[],int sizeOfArry){
 int lowest=marks[0];
 int indexOfSmallestValue=0;
    for(int i=0;i<sizeOfArry;i++){//for loop to execute the array elements
            if(marks[i]<lowest){//this is we use to compare array values with smallest value
            lowest=marks[i];
            indexOfSmallestValue=i;
            }

    }
    cout<< "lowest value: "<< lowest << endl;
    cout<< "Index value of lowest value: "<< indexOfSmallestValue << endl;

    return indexOfSmallestValue;

 }

//3.3. Check whether any of the students have the same marks.
    //: isSame(int marks[])

//4.Declare another array Grade and assign the grades of the marks based on the following scheme:
  // : findGrade(int marks[])


int main(){
//1.. Declare and initialize an array of Marks of type integer with the following value:
	//87, 90, 65, 40, 64, 78, 50,49,40,79
	int marks[10]={87, 90, 65, 40, 64, 78, 50,49,40,79};
	int sizeOfArry=10;
	//2.find lowest value
	int lowestIndex=findLow(marks,sizeOfArry);

    for(int i=0;i<sizeOfArry;i++)
        if(marks[i]>=80)
    {
        cout<<"grade=A"<<endl;
    }
    else if(marks[i]>=70)
    {
        cout<<"grade=B"<<endl;
    }
    else if(marks[i]>=50)
    {
        cout<<"grade=C"<<endl;
    }
    else if(marks[i]>=35)
    {
        cout<<"grade=D"<<endl;
    }
    else
    {
        cout<<"grade=F"<<endl;
    }
    }
