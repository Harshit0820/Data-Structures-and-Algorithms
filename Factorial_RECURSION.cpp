#include<iostream>
using namespace std;
int Fact(int n){
	if (n==0){
		return 1;
	}	
	else{
		return (Fact(n-1))*n;
	}
}
int main(){
	int x=5;
	cout<<Fact(x);
}
