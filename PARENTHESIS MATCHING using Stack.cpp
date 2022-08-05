#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		char data;
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

void push(char x){
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

char pop(){
	Node *t;
	char x=-1;
	
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

int isBalanced(char *exp){
	for(int i=0;exp[i]!=NULL;i++){
		if(exp[i]=='('){
			push(exp[i]);
		}else if(exp[i]==')'){
			if(top==NULL){
				return 0;
			}
			pop();
		}
	}
	if(top==NULL){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	char E[]="((a+b)*(c-d))";
	cout<<isBalanced(E)<<endl;
	char G[]="((a+b)*(c-d)";
	cout<<isBalanced(G)<<endl;
	char H[]="((a+b)*(c-d))))";
	cout<<isBalanced(H)<<endl;

	
}


