#include<iostream>
using namespace std;
int pow(int m, int n){
	if (n==0){
		return 1;
	}
	else{
		return pow(m,n-1)*m;
	}
}
//Direct way to do this using formula when power is even or odd
int Ipow(int m, int n){
	if(n==0){
		return 1;
	}
	if(n%2==0){//power (n) is even
		return Ipow(m*m,n/2);
	}
	else{//power (n) is odd
		return m*Ipow(m*m,(n-1)/2);
	}
}
int main(){
	int x=2;
	int y=9;
	cout<<"Using Recursion: "<<pow(x,y)<<endl;
	cout<<"Direct way: "<<Ipow(x,y);
}
