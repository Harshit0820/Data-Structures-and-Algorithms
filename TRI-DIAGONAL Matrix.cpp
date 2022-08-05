#include<iostream>
using namespace std;
// Note: In matrix index starts from 1 and in array index starts from 0
void set(int A[],int i,int j,int x,int n){
	if(i-j==1){
		A[i-2]=x; // lower diagonal
	}
	else if(i-j==0){
		A[n-1+i-1]=x; // main diagonal
	}
	else if(i-j==-1){
		A[2*n-1+i-1]=x; // upper diagonal
	}
}
int get(int A[],int i,int j,int n){
	if(i-j==1){
		return A[i-2]; // o/p particular position lower diag elt
	}
	else if(i-j==0){
		return A[n-1+i-1]; // o/p particular position main diag elt
	}
	else if(i-j==-1){
		return A[2*n-1+i-1]; // o/p particular position upper diag elt
	}
	else{
		return 0; // o/p particular position 0 value
	}
}
void display(int A[],int n){
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i-j==1){
				cout<<A[i-2]<<" "; // o/p all lower diag elts
			}
			else if(i-j==0){
				cout<<A[n-1+i-1]<<" "; // o/p all main diag elts
			}
			else if(i-j==-1){
				cout<<A[2*n-1+i-1]<<" "; // o/p all upper diag elts
			}
			else{
				cout<<"0 "; // o/p all rest 0's
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
	int A[3*n-2];// array to store non zero elts
	
	cout<<"Enter all elements: ";
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>x; // input of elts diagonal wise
			set(A,i,j,x,n); // only non zero elts will be stored in A array diagonal wise (lower,main,upper)
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

