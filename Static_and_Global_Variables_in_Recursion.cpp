#include<iostream>
using namespace std;

int y=0;//global variable used in fun_global func 

int fun_static(int n){
	static int x=0;//static variable used in fun_static func
	if(n>0){
		x++;
		return fun_static(n-1)+x;
	}
	return 0;
}

int fun_global(int n){
	if(n>0){
		y++;
		return fun_global(n-1)+y;
	}
	return 0;
}

int main(){
	int s;
	s=fun_static(5);
	cout<<"static: "<<s<<endl;
	
	int g;
	g=fun_global(5);
	cout<<"global: "<<g<<endl;
	g=fun_global(5);
	cout<<"global again: "<<g;//when we call and print again we get 50 
	//as after first call and print x has now the new fix value i.e. 5 
	//before x was having a fix value 0
}
