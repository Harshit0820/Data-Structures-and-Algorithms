#include<iostream>
#include<queue>
using namespace std;

void BFS(int G[][7],int start,int n){
	int i=start;
	int j;
	queue<int> q;
	int visited[7]={0};
	
	cout<<i<<" ";
	visited[i]=1;
	q.push(i);
	
	while(!q.empty()){
		i=q.front();
		q.pop();
		for(j=1;j<n;j++){
			if(G[i][j]==1 && visited[j]==0){
				cout<<j<<" ";
				visited[j]=1;
				q.push(j);
			}
		}
	}
}

void DFS(int G[][7],int start,int n){
	static int visited[7]={0};
	int i=start,j;
	
	if(visited[i]==0){
		cout<<i<<" ";
		visited[i]=1;
		for(j=1;j<n;j++){
			if(G[i][j]==1 && visited[j]==0){
				DFS(G,j,n);
			}
		}
	}
}

int main(){
	int G[7][7]={{0,0,0,0,0,0,0},
 				 {0,0,1,1,0,0,0},
 				 {0,1,0,0,1,0,0},
 				 {0,1,0,0,1,0,0},
 				 {0,0,1,1,0,1,1},
 				 {0,0,0,0,1,0,0},
 				 {0,0,0,0,1,0,0}};
 	
	cout<<"BFS of graph is: ";			 
	BFS(G,5,7);
	cout<<endl<<endl;
	cout<<"DFS of graph is: ";			 
	DFS(G,4,7);
}
