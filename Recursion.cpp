#include<iostream>
using namespace std;

void fun1(int n){ //This can be the example of Tail Recursion
	if(n>0){
		cout<<n<<" ";
		fun1(n-1);
	}
}

void fun2(int n){ //This can be the example of Head Recursion
	if(n>0){
		fun2(n-1);
		cout<<n<<" ";
	}
}

int main(){
	int x=3;
	cout<<"Eg1: ";
	fun1(x);
	cout<<endl;
	cout<<"Eg2: ";
	fun2(x);
}
