//TAYLOR SERIES CODE USING ITERATIVE METHOD (using loop)
#include<iostream>
using namespace std;
double Exp_iter(int x, int n){
	double s=1;
	int i;
	double num=1;
	double den=1;
	
	for(i=1;i<=n;i++){
		num*=x;
		den*=i;
		s+=num/den;
	}
	return s;
}
int main(){
	cout<<Exp_iter(1,10);
}
