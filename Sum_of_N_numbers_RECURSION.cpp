#include<iostream>
using namespace std;
int Sum(int n){
	if (n==0){
		return 0;
	}	
	else{
		return Sum(n-1)+n;
	}
}
//direct formula for 1st N natural nos. is (n*(n+1))/2 
//we can even do this problem using loop
int main(){
	int x=5;
	cout<<Sum(x);
}
