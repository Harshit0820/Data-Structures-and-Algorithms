//FIBONACCI SERIES USING 3 WAYS OF CODE (RECURSION, ITERATIVE, MEMOIZATION)
#include<iostream>
using namespace std;

//RECURSION METHOD
int fib_recur(int n){
	if(n<=1){
		return n;
	}
	return fib_recur(n-2)+fib_recur(n-1);
}

//ITERATIVE METHOD
int fib_iter(int n){
	int t0=0, t1=1, s=0, i;
	if(n<=1){
		return n;
	}
	for(i=2;i<=n;i++){
		s=t0+t1;
		t0=t1;
		t1=s;
	}
	return s;
}

//MEMOIZATION METHOD (to avoid excessive calls due to recursion method)
int F[10]; //global array for fib_memoi function
int fib_memoi(int n){
	if(n<=1){
		F[n]=n;
		return n;
	}
	else{
		if(F[n-2]==-1){
			F[n-2]=fib_memoi(n-2);
		}
		if(F[n-1]==-1){
			F[n-1]=fib_memoi(n-1);
		}
		F[n]=F[n-2]+F[n-1]; //to store fibonacci series values in global array F
		return F[n-2]+F[n-1];
	}
}

int main(){
	cout<<"Iterative: "<<fib_iter(6)<<endl;
	cout<<"Recursion: "<<fib_recur(6)<<endl;
	
	for(int i=0;i<10;i++){
		F[i]=-1;
	}
	cout<<"Memoization: "<<fib_memoi(6);
}
