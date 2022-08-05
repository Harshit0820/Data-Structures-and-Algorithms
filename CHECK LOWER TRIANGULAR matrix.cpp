// NOTE: IN LOWER TRIANGULAR MATRIX ELEMENTS ABOVE DIAGONAL (I.E. UPPER PART) MUST BE 0 
// REGARDLESS OF LOWER TRIANGULAR PART AND DIAGONAL PART MAY OR MAY NOT HAVE 0 OR NON ZERO,
// MEANS LOWER TRIANGULAR ELEMENTS AND DIAGONAL ELEMENTS CAN HAVE 0 OR NON ZERO BOTH, BUT UPPER ELEMENTS MUST ALL BE 0
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
			if((i<j)&&(A[i][j]!=0)){
				flag=1;
				goto check;// will go to lower statement and act like break but fully break both loops and not run after
				// direct run lines of code after lower statement
				// goto is beneficiary to break through nested loops
			}
			else if((i>=j)&&(A[i][j]!=0)){
				flag=0;
			}
		}
	}
check:
	if(flag==0){
		cout<<"Lower Triangular";
	}
	else if(flag==1){
		cout<<"NOT Lower Triangular";
	}
}
