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

int peek(){
	Node *p=top;
	return p->data;
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

int isBalanced (char *exp){
    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i] == '(' or exp[i] == '[' or exp[i] == '{' ){
            push(exp[i]);
        }
        else if(exp[i] == ')' or exp[i]== ']' or exp[i] == '}'){
            if(top == NULL)return 0;
            int a=0;
            if(exp[i] == ')')a = peek()+1;
            if(exp[i] == ']')a = peek()+2;
            if(exp[i] == '}')a = peek()+2;
            if(exp[i] == a)pop();
        }
    }
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
	char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl;
    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl;
    

	
}


