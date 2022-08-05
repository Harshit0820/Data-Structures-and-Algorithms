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
			if((i-j==0)||(i-j==1)||(i-j==-1)){
				if(A[i][j]==0){
					flag=1;
				}
			}
			else{
				if(A[i][j]!=0){
					flag=1;
				}
			}
		}
	}
	if(flag==0){
		cout<<"Tri-Diagonal";
	}
	else if(flag==1){
		cout<<"NOT Tri-Diagonal";
	}
}
