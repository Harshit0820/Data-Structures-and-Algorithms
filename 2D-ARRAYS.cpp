#include<iostream>
using namespace std;
int main(){
	//1st method (all in stack)
	int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//2nd method (pointer in stack, array in heap)
	int *B[3];
	B[0] = new int[4];
	B[1] = new int[4];
	B[2] = new int[4];
	
	//3rd method (double pointer in stack, pointers array and array in heap)
	int **C;
	C = new int *[3];
	C[0] = new int[4];
	C[1] = new int[4];
	C[2] = new int[4];
	
}
