#include<iostream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int main(){
	// MAX HEAP
	priority_queue<int> pq;
	pq.push(5);
	pq.push(15);
	pq.push(10);
	pq.push(60);
	cout<<"size: "<<pq.size()<<endl;
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
		cout<<endl;
	}
	
	cout<<"------------"<<endl;
	
	// MIN HEAP
	priority_queue<int> pq2;
	pq2.push(-6);
	pq2.push(-19);
	pq2.push(-14);
	pq2.push(-2);
	cout<<"size: "<<pq2.size()<<endl;
	while(!pq2.empty()){
		cout<<-pq2.top();
		pq2.pop();
		cout<<endl;
	}
}
