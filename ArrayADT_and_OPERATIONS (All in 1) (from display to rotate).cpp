// THIS PROJECT CONTAINS OPERATIONS FROM display TO rotate ACCORDING TO NOTES
// FROM VIDEO 94 TO VIDEO 111 ACCORDING TO COURSE 
#include<iostream>
using namespace std;

void display(int n, int arr[]){
	cout<<"Array is given as: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void append(int n, int arr[], int x){
	arr[n]=x;
	for(int i=0; i<=n; i++){
		cout<<arr[i]<<" ";
	}
}

void insert(int i,int x,int n,int arr[]){
	for(int j=n;j>=i;j--){
		arr[j] = arr[j-1];
	}
	arr[i]=x;
	for(int z=0; z<=n; z++){
		cout<<arr[z]<<" ";
	}
}

void Delete(int n, int arr[], int i){
	for(int j=i+1;j<=n;j++){
		arr[i] = arr[j];
		i++;
	}
	for(int z=0; z<n; z++){
		cout<<arr[z]<<" ";
	}
}

void linearsearch(int n, int arr[]){ 
	int i = 0, x, flag = 0, pos = 0; 
	cout << "\nEnter the element you want to search: "; 
	cin >> x; 
	while (i < n){ 
		if (arr[i] == x){ 
			flag = 1; 
			pos = i ; 
		} 
		i++; 
	} 
	if (flag == 1){ 
		cout << "Element " << x << " is found at index "<<pos<<" in the array after LINEAR SEARCH"; 
	} 
	else 
		cout << "Element not found!!!"; 
}

void sortarr(int n, int arr[]){ 
	int temp = 0; 
	for (int i = 0; i <= n; i++){ 
		for (int j = i + 1; j <= n; j++){ 
			if (arr[j] < arr[i]){ 
				temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp;
			} 
		} 
	} 
	cout << "\nArray after sorting is: "; 
	for (int i = 0; i <= n;i++){ 
		cout << arr[i] << " "; 
	} 
}

// BINARY SEARCH IS DONE USING RECURSION HERE (NORMAL METHOD OF BINARY SEARCH IN NOTES)
int binarysearch(int n, int arr[], int x, int first, int last){ 
	if (first <= last){ 
		int mid = (last + first) / 2; 
		if (arr[mid] == x){ 
			cout << "Element "<<x<<" found at index " << mid << " after BINARY SEARCH";
			return mid; 
		} 
		else if (x < arr[mid]){ 
			last = mid - 1; 
			return binarysearch(n, arr, x, first, last); 
		} 
		else{ 
			first = mid + 1; 
			return binarysearch(n, arr, x, first, last); 
		}
	} 
	else{ 
	cout << "Element not found!!"; 
	return 0; 
	} 
}

void get(int arr[], int n, int i){
	if(i>=0 && i<=n){
		cout<<"Value at index "<< i <<" is: "<<arr[i];
	}
	else{
		cout<<"No value at that index!!!";
	}
}

void set(int n, int arr[], int i, int x){
	arr[i] = x; 
	cout << "New array is given as : "; 
	for (int j = 0; j <= n; j++){ 
		cout << arr[j] << " "; 
	}
}

void Max(int arr[], int n){
	long long int max = -1999999999;
	for(int i=0; i<n; i++){
		if (arr[i] > max){
			max = arr[i];
		}
	}
	cout<<"\nMaximum element of array is: "<<max;
}

void Min(int arr[], int n){ 
	long long int min = 1999999999; 
	for (int i = 0; i < n; i++){ 
		if (arr[i] < min){ 
			min = arr[i]; 
				} 
	} 
	cout << "\nMinimum element of array is: " << min;
}

void Sum(int arr[], int n){
	int total = 0;
	for(int i=0; i < n; i++){
		total = total + arr[i];
	}
	cout<<"\nSum of elements of array is: "<<total;
}

void Avg(int arr[], int n){
	int total = 0;
	for(int i=0; i < n; i++){
		total = total + arr[i];
	}
	float avg = (float) total/n;
	cout<<"\nAverage of array elements is: "<<avg;
}

// WE HAVE USED 2ND METHOD FOR REVERSING THE ARRAY ACCORDING TO NOTES (SEE 1ST METHOD CODE IN NOTES)
void reverse(int n, int arr[]){
	int temp = 0, start = 0, last = n;
	while(start <= last){
		temp = arr[start];
		arr[start] = arr[last];
		arr[last] = temp;
		start++;
		last--;
	}
	cout<<"\nThe Reversed array is: ";
	for(int i=0; i<=n; i++){
		cout << arr[i] << " ";
	}
}

// HERE WE ARE RIGHT SHIFTING THE REVERSED ARRAY
void shift(int n,int arr[]){
	for(int i=n; i>0; i--){
		arr[i]=arr[i-1];
	}
	arr[0]=0;
	cout<<"\nThe Shifted Array is: ";
	for(int i=0; i<=n; i++){
		cout<<arr[i]<<" ";
	}
}

// HERE WE ARE RIGHT ROTATING THE REVERSED ARRAY AND RIGHT SHIFTED ARRAY
void rotate(int n, int arr[]){
	int temp = arr[n];
	for(int j=n; j>0; j--){
		arr[j]=arr[j-1];
	}
	arr[0]=temp;
	cout<<"\nThe Rotated Array is: ";
	for(int i=0; i<=n; i++){
		cout<<arr[i]<<" ";
	}
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
	display(n,arr);
	cout<<endl;
	
	int x;
	cout<<"Enter the element to append: ";
	cin>>x;
	append(n,arr,x);
	cout<<endl;

	int i;
	cout << "\nEnter the element to insert: ";
	cin>>x;
	cout << "Enter the index to insert: "; 
	cin >> i; 
	insert(i , x, n+1, arr);
	cout<<endl;
	
	cout<<"\nEnter the index to delete: ";
	cin>>i;
	Delete(n+1,arr,i);
	cout<<endl;
	
	linearsearch(n+1, arr);
	cout<<endl;
	
	sortarr(n,arr);
	int first = 0; 
	int last = n+1; 
	cout << "\nEnter the element you want to search: "; 
	cin >> x; 
	binarysearch(n+1, arr, x, first, last);
	cout<<endl;
	
	cout << "\nEnter the index you want to get value of: "; 
	cin >> i;
	get(arr,n,i);
	cout<<endl;
	
	cout << "\nEnter the index you want to set value of: ";
	cin >> i; 
	cout << "Enter the value: "; 
	cin >> x; 
	set(n, arr,i,x);
	cout<<endl;
	
	Max(arr,n+1);
	cout<<endl;
	
	Min(arr,n+1);
	cout<<endl;
	
	Sum(arr,n+1);
	cout<<endl;
	
	Avg(arr,n+1);
	cout<<endl;
	
	reverse(n,arr);
    cout<<endl;
	
	shift(n+1,arr);
    cout<<endl;
	
	rotate(n+1,arr); //TO GET BETTER O/P DON'T SHIFT BEFORE ROTATE JUST DO THE ROTATE OPERATION WITH n LENGTH
    cout<<endl;
}

