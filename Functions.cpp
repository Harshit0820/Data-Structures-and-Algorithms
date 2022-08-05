#include<iostream>
using namespace std;

int add(int a, int b){
	int c = a + b;
	return c;
}

int main(){
	int x=10,y=15,z;
	z=add(x,y);
	cout<<"Sum is: "<<z;
}
