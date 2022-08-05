//TAYLOR SERIES CODE USING HORNER'S RULE
#include<iostream>
using namespace std;
double Exp_hor(int x, int n){
	static double s=1;
	if (n==0){
		return s;	
	}	
	else{
		s=1+x*s/n; //multiply s in num to get double form of o/p i.e. decimal o/p and more precise o/p
		return Exp_hor(x,n-1);
	}
}
int main(){
	cout<<Exp_hor(2,10);
}
