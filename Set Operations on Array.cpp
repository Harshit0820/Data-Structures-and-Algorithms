#include<iostream>
using namespace std;

void sortarr(int n, int arr[]){ 
	int temp = 0; 
	for (int i = 0; i < n; i++){ 
		for (int j = i + 1; j < n; j++){ 
			if (arr[j] < arr[i]){ 
				temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp;
			} 
		} 
	} 
	cout << "\nArray after sorting is: "; 
	for (int i = 0; i < n;i++){ 
		cout << arr[i] << " "; 
	} 
}

// FOR ALL SET OPERATIONS WE HAVE USED 2ND METHOD ACCORDING TO NOTES I.E. USING MERGE OPERATION

void Union(int m, int n, int arr1[], int arr2[]){
	int p=m+n;
	int arr3[p];
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(arr1[i]<arr2[j]){
			arr3[k++]=arr1[i++];
		}
		else if(arr2[j]<arr1[i]){
			arr3[k++]=arr2[j++];
		}
		else{
			arr3[k++]=arr1[i++];
			j++;
		}
	}
	for(;i<m;i++){
		arr3[k++]=arr1[i];
	}
	for(;j<n;j++){
		arr3[k++]=arr2[j];
	}
	cout << "\nThe Union of arrays is:" << endl; 
	for(int i = 0; i < k; i++){ 
		cout << arr3[i] << " "; 
	} 
}

void intersection(int m, int n, int arr1[], int arr2[]){
	int p=m+n;
	int arr3[p];
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(arr1[i]<arr2[j]){
			i++;
		}
		else if(arr2[j]<arr1[i]){
			j++;
		}
		else if(arr1[i]==arr2[j]){
			arr3[k++]=arr1[i++];
			j++;
		}
	}
	cout << "\nIntersection of the arrays is :" << endl; 
	for(int i = 0; i < k; i++){ 
		cout << arr3[i] << " "; 
	} 
}

// HERE WE ARE DOING arr1-arr2 SO O/P IS ELTS OF arr1 ELTS NOT PRESENT IN arr2 (i.e. we get subsets of A only)
// (IF arr2-arr1 THEN VICE VERSA)
void difference(int m, int n, int arr1[], int arr2[]){
	int p=m+n;
	int arr3[p];
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(arr1[i]<arr2[j]){
			arr3[k++]=arr1[i++];
		}
		else if(arr2[j]<arr1[i]){
			j++;
		}
		else{
			i++;
			j++;
		}
	}
	for(;i<m;i++){
		arr3[k++]=arr1[i];
	}
	cout << "\nThe Difference of arrays is:" << endl; 
	for(int i = 0; i < k; i++){ 
		cout << arr3[i] << " "; 
	} 
}

// SET MEMBERSHIP OPERATION IS SAME AS SEARCH SO WE CAN USE EITHER LINEAR OR BINARY SEARCH TO PERFORM IT

int main(){
	int m, n, r1, r2; 
	int arr1[m], arr2[n]; 
	cout << "Enter size of array 1: "; 
	cin >> m; 
	cout << "Enter array elements 1: "; 
	for (int i = 0; i < m; i++) { 
		cin >> arr1[i]; 
	}
	cout << "Enter size of array 2: "; 
	cin >> n; 
	cout << "Enter array elements 2: "; 
	for (int i = 0; i < n; i++) { 
		cin >> arr2[i]; 
	}
	
	sortarr(m,arr1);
	sortarr(n,arr2);
	
	Union(m,n,arr1,arr2);
	cout<<endl;
	
	intersection(m,n,arr1,arr2);
	cout<<endl;
	
	difference(m,n,arr1,arr2);
}
