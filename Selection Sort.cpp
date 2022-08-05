#include<iostream>
using namespace std;

void swap(int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void Selection_Sort(int A[],int n){
	int i,j,k;
	for(i=0;i<n-1;i++){
		for(j=k=i;j<n;j++){
			if(A[j]<A[k]){
				k=j;
			}
		}
		swap(&A[i],&A[k]);
	}
}

int main(){
	int A[]={3,7,9,10,6,5,12,4,11,2};
	int n=10;
	Selection_Sort(A,10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
}
