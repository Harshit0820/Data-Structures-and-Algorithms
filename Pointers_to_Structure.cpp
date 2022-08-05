#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

int main(){
	Rectangle r = {10,5};
	cout<< r.length <<endl;
	cout<< r.breadth <<endl;
	
	Rectangle *p = &r;
	cout<< p->length <<endl;
	cout<< p->breadth <<endl;
	
	//Object of Structure in Heap
	Rectangle *p1;
	p1 = new Rectangle; //will make a rectangle or a structure object in heap
	p1->length = 15;
	p1->breadth = 7;
	cout<< p1->length <<endl;
	cout<< p1->breadth <<endl;
}
