#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

class Queue{
	stack<int> s1;
	stack<int> s2;
	public:
		void enqueue(int data){
			s1.push(data);
		}
		int dequeue(){
			if(s2.empty()){
				if(s1.empty()){
					cout<<"Queue is empty";
					return -1;
				}
			}
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			int ans=s2.top();
			s2.pop();
			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}
			return ans;
		}
		
};

int main(){
	Queue q;
	q.enqueue(1);	
	q.enqueue(2);
	q.enqueue(3);
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;

}
