#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Node{
	public:
		Node *prev;
		int data;
		Node *next;
}*first=NULL;

void create(int A[],int n){
	Node *t,*last;
	int i;
	first=new Node;
	first->data=A[0];
	first->prev=first->next=NULL;
	last=first;
	for(i=1;i<n;i++){
		t=new Node;
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
}

void Display(Node *p){
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int Length(Node *p){
	int len=0;
	while(p!=NULL){
		len++;
		p=p->next;
	}
	return len;
}

void Reverse(Node *p){
	Node *temp;
	while(p!=NULL){
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		p=p->prev;
		if(p!=NULL && p->next==NULL){
			first=p;
		}
	}
}

int main(){
	int A[]={10,20,30,40,50};
	create(A,5);
	Reverse(first);
	Display(first);
}
