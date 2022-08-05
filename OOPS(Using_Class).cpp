#include<iostream>
using namespace std;
class Rectangle{
	private:
		int length;
		int breadth;
		
	public:
		void initialize(int l, int b){
			length = l;
			breadth = b;
			cout<<"Length "<<l<<endl<<"Breadth "<<b<<endl;
		}
		int area(){
			return length*breadth;
		}
		void changeLength(int l){
			length = l;
			cout<<"Changed Length "<<length;
		}
};
int main(){
	Rectangle r;
	r.initialize(10,5);
	cout<<"Area "<< r.area() <<endl;
	r.changeLength(20);
}
