#include<iostream>
using namespace std;
void fun(int n){
	if(n>0){
		fun(n-1); //Head Recursion as all code or operation is done after recursive call of function
		//So all operation is done at returning time of the recursion
		cout<<n<<" ";
	}
}

//HEAD RECURSION CANNOT BE TURN IN FORM OF LOOP EASILY WE HAVE TO MODIFY THE CODE VERY VERY MUCH
//WE HAVE NOT TAKEN AS IT IS CODE AS DONE IN TAIL, WE HAVE MODIFY CODE TO MAKE HEAD RECURSION IN FORM OF LOOP
void fun_loop(int n){
	int i=1;
	while(i<=n){
		cout<<i<<" ";
		i++;
	}
}

int main(){
	int x=5;
	fun(x);
	cout<<endl;
	fun_loop(x);
}
