// NOTE: FOR ADD AND SUBTRACT OF 2 MATRICES DIMENSIONS MUST BE SAME
#include<iostream>
using namespace std;
int main(){
	int m,n;
	cout<<"Enter dimensions: ";
	cin>>m>>n;
	int A[m][n],B[m][n];
	int sum[m][n],diff[m][n];
	cout<<"Enter elements of A matrix: ";
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>A[i][j];
		}
	}
	cout<<"Enter elements of B matrix: ";
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>B[i][j];
		}
	}
	cout<<"Sum of A and B matrices: "<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=A[i][j]+B[i][j];
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Difference of A and B matrices: "<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			diff[i][j]=A[i][j]-B[i][j];
			cout<<diff[i][j]<<" ";
		}
		cout<<endl;
	}
}
