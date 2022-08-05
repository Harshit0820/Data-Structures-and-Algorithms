#include<iostream>
using namespace std;
int area(int l, int b){
	return l*b;
}
int perimeter(int l, int b){
	int p = 2*(l+b);
	return p;
}
int main(){
	int l=0,b=0;
	cout<<"Enter length and breadth: ";
	cin>>l>>b;
	int ar = area(l,b);
	int peri = perimeter(l,b);
	cout<<"Area: "<<ar<<endl<<"Perimeter: "<<peri;
}
