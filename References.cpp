#include<iostream>
using namespace std;
int main(){
	int a = 10;
	int &r = a;
	cout<<a<<endl;
	cout<<r<<endl;
	r++;
	cout<<a<<endl;
	cout<<r<<endl;
	a++;
	cout<<a<<endl;
	cout<<r<<endl;
	a=25;
	cout<<a<<endl;
	cout<<r<<endl;
	int b = 30;
	r = b;
	cout<<r<<endl;
	cout<<a;
}
