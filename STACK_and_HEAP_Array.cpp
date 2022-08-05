#include<iostream>
using namespace std;
int main(){
	int i;
	int A[5]={2,4,6,8,10}; // Stack Array
	// To get Heap Array
	int *p;
	p=new int[5]; // Heap Array
	p[0]=3;
	p[1]=5;
	p[2]=7;
	p[3]=9;
	p[4]=11;
	for(i=0;i<5;i++){
		cout<<A[i]<<" "; // Printing Stack Array
	}
	
	cout<<endl;
	
	for(i=0;i<5;i++){
		cout<<p[i]<<" "; // Printing Heap Array
	}
}
