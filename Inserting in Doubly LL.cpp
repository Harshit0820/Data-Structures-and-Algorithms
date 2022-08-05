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

void Insert(Node *p, int index, int x){
	Node *t;
	int i;
	if(index<0 || index>Length(first))
		return;
	if(index==0){
		t=new Node;
		t->data=x;
		t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
	}else{
		for(i=0;i<index-1;i++){
			p=p->next;
		}
		t=new Node;
		t->data=x;
		t->prev=p;
		t->next=p->next;
		if(p->next!=NULL){
			p->next->prev=t;
		}
		p->next=t;
	}
}

int main(){
	int A[]={10,20,30,40,50};
	create(A,5);
	Insert(first,2,25);
	Insert(first,0,5);
	Insert(first,7,55);
	Display(first);
}
