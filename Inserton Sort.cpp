#include<iostream>
using namespace std;

void Insertion_Sort(int A[],int n){
	int i,j,x;
	for(i=1;i<n;i++){
		j=i-1;
		x=A[i];
		while(A[j]>x && j>-1){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
}

int main(){
	int A[]={3,7,9,10,6,5,12,4,11,2};
	int n=10;
	Insertion_Sort(A,10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
}
