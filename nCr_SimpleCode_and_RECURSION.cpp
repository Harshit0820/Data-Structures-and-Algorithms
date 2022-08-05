#include<iostream>
using namespace std;

//Simple code using factorial function
int fact(int n){
	if (n==0) return 1;	
	return (fact(n-1))*n;
}
int nCr_fact(int n,int r){
	int num,den;
	num=fact(n);
	den=fact(r)*fact(n-r);
	return num/den;
}

//USING RECURSION
int nCr_recur(int n, int r){
	if(n==r || r==0){
		return 1; 
	}
	else{
		return nCr_recur(n-1,r-1)+nCr_recur(n-1,r);
	}
}

int main(){
	cout<<"Simple method: "<<nCr_fact(4,2)<<endl;
	cout<<"Recursion: "<<nCr_recur(4,2);
}
