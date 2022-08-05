#include<iostream>
using namespace std;

void swap(int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int A[],int l,int h){
	int pivot=A[l];
	int i=l,j=h;
	do{
		do{i++;}while(A[i]<=pivot);
		do{j--;}while(A[j]>pivot);
		if(i<j){
			swap(&A[i],&A[j]);
		}
	}while(i<j);
	swap(A[l],A[j]);
	return j;
}

void Quick_Sort(int A[],int l,int h){
	int j;
	if(l<h){
		j=partition(A,l,h);
		Quick_Sort(A,l,j);
		Quick_Sort(A,j+1,h);
	}
}

int main(){
	int A[]={3,7,9,10,6,5,12,4,11,2,INT_MAX};
	int n=11;
	Quick_Sort(A,0,10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
}
