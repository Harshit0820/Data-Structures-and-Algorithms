#include<iostream>
using namespace std;
void fun(int n){
	if(n>0){
		cout<<n<<" ";
		fun(n-1); //Tail Recursion as no code or operation is done after recursive call of function
		//So no operation is done at returning time of the recursion
	}
}

//TAIL RECURSION IN FORM OF LOOP (MORE EFFICIENT TO USE THIS FORM)
void fun_loop(int n){
	while(n>0){
		cout<<n<<" ";
		n--;
	}
}

int main(){
	int x=5;
	fun(x);
	cout<<endl;
	fun_loop(x);
}
