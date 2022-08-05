#include<iostream>
using namespace std;
int main(){
	int i,j,n;
	cout<<"Enter size of array: ";
	cin>>n;
	int A[n][n];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>A[i][j];
		}
	}
	cout<<endl<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	int flag=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(A[i][j]!=A[j][i]){
				flag=1;
				goto sym;
			}
			else{
				flag=0;
			}
		}
	}
sym:
	if(flag==0){
		cout<<"Symmetric";
	}
	else if(flag==1){
		cout<<"NOT Symmetric";
	}
}
