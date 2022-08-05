#include<iostream>
using namespace std;
int main(){
	int A[5];
	A[0]=12;
	A[1]=15;
	A[2]=25;
	cout<<sizeof(A)<<endl;
	cout<<A[1]<<endl;
	
	int B[5]={2,4,6,8,10};
	cout<<B[1]<<endl;
	cout<<B[2]<<endl;
	
	int C[10]={2,4,6,8,10,12,14};
	cout<<C[5]<<endl;
	cout<<C[8]<<endl;
	cout<<C[9]<<endl;
	
	for(int i=0;i<10;i++){
		cout<<C[i];
	}
	cout<<endl;
	
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	for(int j=0;j<n;j++){
		cin>>arr[j];
	}
	for(int k=0;k<n;k++){
		cout<<arr[k];
	}
		
	return 0;
}
