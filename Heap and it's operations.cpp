#include <iostream>
using namespace std;
 
void Insert(int A[],int n){
      int temp,i=n;
      temp=A[n];
      while(i>1 && temp>A[i/2]){
           A[i]=A[i/2];
           i=i/2;
      }
      A[i]=temp;
}
 
void display(int A[],int k){
    int i = 0;
    for(i=1;i<k;i++){
        cout<<A[i]<<"  ";
    }
}

void Delete(int A[],int n){
	int x,i,j;
	x=A[n];
	A[1]=A[n];
	i=1;
	j=2*i;
	while(j<n-1){
		if(A[j+1]>A[j]){
			j=j+1;
		}
		if(A[i]<A[j]){
			swap(A[i],A[j]);
			i=j;
			j=2*j;
		}else{
			break;
		}
		A[n]=x;
	}
}
 
int main(){
 
    int A[]={0,10,20,30,25,5,40,35}; // In case of 1 based indexing parent is at i/2
    int n=sizeof(A)/sizeof(A[0]);
 
    for(int i=2;i<=7;i++){
    	Insert(A,i);
	}
 
 	cout<<"Heap is: ";
    display(A,n);
    cout<<endl<<endl<<"Heap after deleting root: ";
    Delete(A,n);
    display(A,n);
    
    
 
    
    return 0;
}
