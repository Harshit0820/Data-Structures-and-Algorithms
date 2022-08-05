#include<iostream>
using namespace std;
// Note: In matrix index starts from 1 and in array index starts from 0
void set(int A[],int i,int j,int x){
	if(i==j){
		A[i-1]=x;
	}
}
int get(int A[],int i,int j){
	if(i==j){
		return A[i-1];
	}
	else{
		return 0;
	}
}
void display(int A[],int n){
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i==j){
				cout<<A[i-1]<<" ";
			}
			else{
				cout<<"0"<<" ";
			}
		}
		cout<<endl;
	}
}
int main(){
	int n, A[n];
	cout<<"Enter size of array: ";
	cin>>n;
	// value of n will depend on number of values we are setting using set function
	set(A,1,1,3);set(A,2,2,7);set(A,3,3,4);set(A,4,4,9);set(A,5,5,6); 
	display(A,n);
	cout<<endl<<get(A,2,2); 
	cout<<endl<<get(A,2,4); 
}

