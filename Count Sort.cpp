#include<iostream>
using namespace std;

int findMax(int A[],int n){
	int max=INT_MIN;
	int i;
	for(i=0;i<n;i++){
		if(A[i]>max)
		max=A[i];
	}
	return max;
}

void Count_Sort(int A[],int n){
	int max;
	int *C;
	max=findMax(A,n);
	C=new int[max];
	for(int i=0;i<max+1;i++){
		C[i]=0;
	}
	for(int i=0;i<n;i++){
		C[A[i]]++;
	}
	int i=0,j=0;
	while(j<max+1){
		if(C[j]>0){
			A[i]=j;
			i++;
			C[j]--;
		}else{
			j++;
		}
	}
}

int main(){
	int A[]={3,7,9,10,6,5,12,4,11,2};
	int n=10;
	Count_Sort(A,10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
}
