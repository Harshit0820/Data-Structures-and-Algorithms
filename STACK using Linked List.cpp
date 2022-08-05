#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
}*top=NULL;

void Display(){
	Node *p;
	p=top;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void push(int x){
	Node *t;
	t=new Node;
	if(t==NULL){
		cout<<"Stack is full"<<endl;
	}
	else{
		t->data=x;
		t->next=top;
		top=t;
	}
}

int pop(){
	Node *t;
	int x=-1;
	
	if(top==NULL){
		cout<<"Stack is empty"<<endl;
	}
	else{
		t=top;
		top=top->next;
		x=t->data;
		delete t;
	}
	return x;
}

int peek(int index){
	Node *p=top;
	for(int i;p!=NULL&&i<index-1;i++){
		p=p->next;
	}
	if(p!=NULL){
		return p->data;
	}
	return -1;
}

int isEmpty(){
	if(top!=NULL)
		return 0;
	return 1;
}

int isFull(){
	Node *t=new Node;
	if(t!=NULL)
		return 1;
	return 0;
}

int stackTop(){
	if(top!=NULL)
		return top->data;
	return -1;
}

int main(){
	push(10);
	push(20);
	push(30);
	push(40);

	Display();
	
	cout<<"Peeked: "<<peek(1)<<endl;
	cout<<"Peeked: "<<peek(2)<<endl;
	
	cout<<"Empty: "<<isEmpty()<<endl;
	
	cout<<"Full: "<<isFull()<<endl;
	
	cout<<"Top of stack: "<<stackTop()<<endl;
	
	cout<<"Deleted: "<<pop()<<endl;
	cout<<"Deleted: "<<pop()<<endl;

	Display();

}
