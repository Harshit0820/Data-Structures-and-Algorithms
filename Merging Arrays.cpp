#include<iostream>
using namespace std;

void display(int x, int arr[]){
	cout<<"Array is given as: ";
	for(int i=0; i<x; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void merge(int arr1[], int arr2[], int m, int n){
	int p=m+n;
	int arr3[p];
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(arr1[i]<arr2[j]){
			arr3[k++]=arr1[i++];
		}
		else{
			arr3[k++]=arr2[j++];
		}
	}
	for(;i<m;i++){
		arr3[k++]=arr1[i];
	}
	for(;j<n;j++){
		arr3[k++]=arr2[j];
	}
	display(p,arr3);
}

int main(){
	int m;
	cout<<"Enter the length of the array: ";
	cin>>m;
	int arr1[m];
	cout<<"Enter "<<m<<" elements: ";
	for(int i=0; i<m; i++){
		cin>>arr1[i];
	}
	display(m,arr1);
	
	int n;
	cout<<"Enter the length of the array: ";
	cin>>n;
	int arr2[n];
	cout<<"Enter "<<n<<" elements: ";
	for(int i=0; i<n; i++){
		cin>>arr2[i];
	}
	display(n,arr2);
	
	merge(arr1,arr2,m,n);
}
