#include<iostream>
using namespace std;
void funB(int n);//declaration of funB to use it afterwards in funA
void funA(int n){
	if(n>0){
		cout<<n<<" ";
		funB(n-1);
	}
}
void funB(int n){//definition of funB and declaring it before funA as we using it in funA
	if(n>1){
		cout<<n<<" ";
		funA(n/2);
	}
}
int main(){
	funA(20);
}
