#include<iostream>
using namespace std;

//Parameter as Array
void func(int A[], int n){ //A[] can also be written as *A
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	//we can even change elements of the array in the function
	A[0] = 15; 
	A[3] = 29;
}

//Function returning an array
int* new_func(int size){ //We can use [] instead of * but *is better as it will work on array as well as single element
	int *p;
	p = new int[size];
	for(int i=0; i<size; i++){
		p[i] = i+1;
	}
	return p;
}
//Function new_func is creating the array of given size and initializing all elts 
//and returning pointer of that array and main function is using the array and printing it

int main(){
	int A[] = {2,4,6,8,10};
	int n = 5;
	func(A,n);
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
	
	cout<<endl;
	int *ptr;
	int sz = 7;
	ptr = new_func(sz);
	for(int i=0; i<sz; i++){
		cout<<ptr[i]<<" ";
	}
}
