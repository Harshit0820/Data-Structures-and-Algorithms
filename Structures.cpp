#include<iostream>
using namespace std;
struct Rectangle{
	int length;
	int breadth;
	char x; //for char 4 bytes will be assigned but structure will only use 1 byte
}//r1,r2,r3 //we can even declare the structure variable/es here (before structure semi-colon)
//Now it is global variable and is accessible to all the functions in the code including main function
;

//struct Rectangle r1,r2,r3; //Now it is global variable/es and is
//accessible to all the functions in the code including main function

int main(){
//	struct Rectangle r1;
//	r1.length = 15;
//	r1.breadth = 10;
	struct Rectangle r1 = {15,10};
	r1.length = 10; //assigning new values
	r1.breadth = 5;  //assigning new values
	cout<<"Area of Rectangle is: "<<(r1.length*r1.breadth)<<endl;
	cout<<"Size of structure is: "<<sizeof(r1)<<endl;
	cout<<r1.length<<endl<<r1.breadth;
}
