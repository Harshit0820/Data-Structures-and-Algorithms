#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class Stack{
	queue<int> q1;
	queue<int> q2;
	public:
		void Push(int data){
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
			q1.push(data);
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
			}
		}
		int Pop(){
			int ans=q1.front();
			q1.pop();
			return ans;
		}
};

int main(){
	Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;



}
