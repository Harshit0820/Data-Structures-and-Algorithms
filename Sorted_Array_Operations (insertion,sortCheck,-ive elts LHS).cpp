#include<iostream>
using namespace std;

void display(int n, int arr[]){
	cout<<"Array is given as: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int isSorted(int arr[], int n){
	for(int i=0; i<n-1; i++){
		if(arr[i]>arr[i+1])
			return 0;
	}
	return 1;
}

void InsertSort(int arr[], int n, int x){
	int i=n-1;
	while(i>=0 && arr[i]>x){
		arr[i+1] = arr[i];
		i--;
	}
	arr[i+1]=x;
	display(n+1,arr);
}

void Rearrange(int arr[], int n){
	int i=0,j=n-1;
	while(i<j){
		while(arr[i]<0){
			i++;
		}
		while(arr[j]>0){
			j--;
		}
		if(i<j){
			swap(arr[i],arr[j]);
		}
	}
	display(n,arr);
}

int main(){
	int n;
	cout<<"Enter the length of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter "<<n<<" elements: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	InsertSort(arr,n,7);
	cout<<isSorted(arr,n);
	Rearrange(arr,n); //TO GET BETTER O/P COMMENT PREVIOUS COMMANDS OF OTHER OPERATIONS and vice versa
}
