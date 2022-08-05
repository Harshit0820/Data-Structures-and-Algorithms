#include<iostream>
using namespace std;
// Note: In matrix index starts from 1 and in array index starts from 0
void set(int A[],int i,int j,int x,int n){
	if(i<=j){
		A[j-i]=x; // storing 1st row (elts like of upper tri part and diag part)
	}
	else if(i>j){
		A[n+i-j-1]=x; // storing 1st col without repeating elt (elts like of lower tri part)
	}
}
int get(int A[],int i,int j,int n){
	if(i<=j){
		return A[j-i]; // returning elts of upper tri part and diag part i.e. same as 1st row elts
	}
	else if(i>j){
		return A[n+i-j-1]; // returning elts of lower tri i.e. same as 1st col elts without repeating elt
	}
	else{
		return 0;
	}
}
void display(int A[],int n){
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i<=j){
				cout<<A[j-i]<<" "; // printing elts of upper tri part and diag part 
			}
			else if(i>j){
				cout<<A[n+i-j-1]<<" "; // printing elts of lower tri 
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
}
int main(){
	int n;
	int i,j,x;
	cout<<"Enter size of matrix: ";
	cin>>n;
	int A[2*n-1];// array to store firstly 1st row then 1st col elts of matrix without repeating elt
	
	cout<<"Enter all elements: ";
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>x; // input of elts firstly 1st row then secondly 1st col without repeating elt
			set(A,i,j,x,n); // only 1st row and 1st col elts will be stored in A without repeating elt
		}
	}
	cout<<endl<<endl;
	display(A,n);
	cout<<endl;
	cout<<get(A,2,4,n)<<" ";
	cout<<get(A,3,2,n)<<" ";
	cout<<get(A,1,4,n)<<" ";
	cout<<get(A,4,3,n)<<" ";
	cout<<get(A,5,5,n);
}

