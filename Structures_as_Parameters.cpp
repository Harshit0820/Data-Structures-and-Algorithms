#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

//Call by value
void fun_CBV(struct Rectangle r1){
	r1.length = 999;
	r1.breadth = 787;
	cout<<"Length_f "<<r1.length<<endl<<"Breadth_f "<<r1.breadth<<endl;
	//no changes will occur in actual parameter values
}

//Call by reference
void fun_CBR(struct Rectangle &r1){
	r1.length = 999;
	r1.breadth = 787;
	cout<<"Length_f "<<r1.length<<endl<<"Breadth_f "<<r1.breadth<<endl;
	//changes will occur in actual parameter values also
}

//Call by address
void fun_CBA(struct Rectangle *p){
	p->length = 999;
	p->breadth = 787;
	cout<<"Length_f "<<p->length<<endl<<"Breadth_f "<<p->breadth<<endl;
	//changes will occur in actual parameter values also
}

//Array in Structure
struct Test{
	int A[5];
};
void func_array(struct Test T1){
	T1.A[0]=92;
	T1.A[1]=63;
	T1.A[2]=27;
	for(int i=0;i<5;i++){
		cout<<T1.A[i]<<" ";
	}
}

//Variable type structure in heap
struct Rect{
	int l;
	int b;
};
struct Rect *func(){
	struct Rect *ptr;
	ptr = new Rect;
	ptr->l = 15;
	ptr->b = 7;
	return ptr;
}
//func is creating an obj of type rectangle using pointer in heap 
//we are setting l and b values and retuning address of that structure

int main(){
	Rectangle r = {10,5};
	fun_CBV(r);
	cout<<"Length "<<r.length<<endl<<"Breadth "<<r.breadth<<endl;
	
	cout<<"----------------"<<endl;
	fun_CBR(r);
	cout<<"Length "<<r.length<<endl<<"Breadth "<<r.breadth<<endl;
	
	cout<<"----------------"<<endl;
	fun_CBA(&r);
	cout<<"Length "<<r.length<<endl<<"Breadth "<<r.breadth<<endl;
	
	cout<<"----------------"<<endl;
	Test t = {1,2,3,4,5};
	func_array(t);
	
	cout<<endl<<"----------------"<<endl;
	Rect *p1 = func();
	cout<<"L "<<p1->l<<endl<<"B "<<p1->b;

}
