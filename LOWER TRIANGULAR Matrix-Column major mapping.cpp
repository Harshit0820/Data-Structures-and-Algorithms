// NOTE: IN LOWER TRIANGULAR MATRIX ELEMENTS ABOVE DIAGONAL (I.E. UPPER PART) MUST BE 0 
// REGARDLESS OF LOWER TRIANGULAR PART AND DIAGONAL PART MAY OR MAY NOT HAVE 0 OR NON ZERO,
// MEANS LOWER TRIANGULAR ELEMENTS AND DIAGONAL ELEMENTS CAN HAVE 0 OR NON ZERO BOTH, BUT UPPER ELEMENTS MUST ALL BE 0 
#include<iostream>
using namespace std;
// Note: In matrix index starts from 1 and in array index starts from 0
void set(int A[],int i,int j,int x,int n){
	if(i>=j){
		A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
	}
}
int get(int A[],int i,int j,int n){
	if(i>=j){
		return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
	}
	else{
		return 0;
	}
}
void display(int A[],int n){
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i>=j){
				cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
			}
			else{
				cout<<"0"<<" ";
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
			set(A,i,j,x,n); // only non zero elts will be stored in A array
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
	// here we will take n=5 as notes eg
	
	
}
