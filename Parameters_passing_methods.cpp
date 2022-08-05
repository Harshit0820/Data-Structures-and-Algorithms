#include<iostream>
using namespace std;
//Call by value
int CBV(int a){
	a++;
	cout<<a;
	return 0;
}
//Call by address
void swap_CBA(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//Call by reference
void swap_CBR(int &a,int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main(){
	int num1=10;
	CBV(num1);
	cout<<endl<<num1<<endl;
	
	int n1=10, n2=20;
	swap_CBA(&n1,&n2);
	cout<<n1<<" "<<n2<<endl;
	
	int nu1=5, nu2=15;
	swap_CBR(nu1,nu2);
	cout<<nu1<<" "<<nu2;
}
