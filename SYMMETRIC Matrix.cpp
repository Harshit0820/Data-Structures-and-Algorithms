#include<iostream>
using namespace std;
// Note: In matrix index starts from 1 and in array index starts from 0

// THIS CODE WILL AUTOMATICALLY MAKE ANY MATRIX INPUT VALUES SYMMETRIC EVEN IF WE GIVE LOWER TRI MATRIX VALUES
// OR FULL MATRIX VALUES (NO UPPER TRI MATRIX VALUES AS WE ARE USING LOWER TRI METHOD TO MAKE SYMM MATRIX)
// i.e. if we give any lower tri matrix values it will make symm matrix by making upper tri matrix values
// according to the inputted lower tri matrix values (as in symm matrix both tri parts are same and equal)

void set(int A[],int i,int j,int x){
	if(i>=j){
		A[i*(i-1)/2+(j-1)]=x; // setting lower triangular matrix
	}
}
int get(int A[],int i,int j){
	if(i>=j){
		return A[i*(i-1)/2+(j-1)]; // returning values acc to lower triangular matrix 
		// the way stored in array A
	}
	else{
		return A[j*(j-1)/2+(i-1)]; // returning rest values acc to upper triangular matrix 
		// from lower tri matrix values stored in array A
	}
}
void display(int A[],int n){
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i>=j){
				cout<<A[i*(i-1)/2+(j-1)]<<" "; // displaying values acc to lower triangular matrix 
				// the way stored in array A
			}
			else{
				cout<<A[j*(j-1)/2+(i-1)]<<" "; // displaying rest values acc to upper triangular matrix 
				// from lower tri matrix values stored in array A
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
	int A[n*(n+1)/2];// array to store non zero elts
	
	cout<<"Enter all elements: ";
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>x; // input of elts row wise
			set(A,i,j,x); // only non zero elts will be stored in A array
		}
	}
	cout<<endl<<endl;
	display(A,n);
	cout<<endl;
	cout<<get(A,2,4)<<" ";
	cout<<get(A,4,2)<<" ";
	cout<<get(A,1,4)<<" ";
	cout<<get(A,4,1)<<" ";
	cout<<get(A,5,4)<<" ";
	cout<<get(A,4,5);
	// here we will take n=5 as notes eg
	
	
	
}
