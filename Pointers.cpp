#include<iostream>
using namespace std;
int main(){
	int a = 10;
	int *p;
	p = &a;
	cout<<a<<endl;
	cout<<"Value using pointer: "<<*p<<endl;
	cout<<"Address using pointer: "<<p<<" , Original address: "<<&a<<endl;
	
	//pointer in array
	int A[5] = {2,4,6,8,10};
	int *pt;
	pt = A;
	for(int i=0; i<5; i++){
		cout<<pt[i]<<" ";
	}
	cout<<endl;
	
	//pointer and heap
	int *p1;
	p1 = new int[5]; //dynamically created the memory of array in heap
	p1[0] = 10; p1[1] = 19; p1[2] = 27; p1[3] = 25; p1[4] = 36;
	for(int i=0; i<5; i++){
		cout<<p1[i]<<" ";
	}
	delete [] p1;
	//whenever we are dynamically allocating memory IN BIG PROJECTS
	//we must release the memory when we are finished using it
}
