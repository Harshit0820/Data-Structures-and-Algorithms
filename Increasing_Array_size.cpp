#include<iostream>
using namespace std;
int main(){
	int *p,*q;
	int i;
	p=new int[5]; // array of size 5
	p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;

	q=new int[10]; // making bigger array

	for(i=0;i<5;i++)
		q[i]=p[i]; // shifting all values or elts of p to q

	delete []p; // deleting small array by deleting pointer as pointer was the small array itself
	p=q; // assigning bigger array to pointer p
	q=NULL; // null the other pointer

	for(i=0;i<5;i++)
		cout<<p[i]<<" "; // printing 1st pointer values as it is now the bigger array
		// the rest 5 values of p is garbage values so we are printing 1st 5 values only
}
