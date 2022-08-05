#include<iostream>
using namespace std;
//TOWER OF HANOI USING RECURSION (V.V.V.V IMP)
void TOH(int n, int A, int B, int C){
	if(n>0){
		TOH(n-1,A,C,B);
		cout<<"From "<<A<<" to "<<C<<endl;
		TOH(n-1,B,A,C);
	}
}

int main(){
	TOH(3,1,2,3);
}
