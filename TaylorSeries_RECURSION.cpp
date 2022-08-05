//TAYLOR SERIES CODE USING RECURSION
#include<iostream>
using namespace std;
double Exp_recur(int x, int n){
// x is the power of e and n is no. of terms we want (greater n gives more precise ans)
// n is not the no. of terms after decimal in ans, it is no. of terms added in taylor series to get precise ans
	static double p=1, f=1;
	double r;
	if (n==0){
		return 1;
	}	
	else{
		r=Exp_recur(x,n-1);
		p=p*x;
		f=f*n;
		return r+p/f;
	}
}
int main(){
	cout<<Exp_recur(4,15);
}
