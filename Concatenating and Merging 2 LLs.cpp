#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Node{
	public:
		int data;
		struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n){
	int i;
	Node *t,*last;
	first=new Node;
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(i=1;i<n;i++)
	{
		t=new Node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void create2(int A[],int n){
	int i;
	Node *t,*last;
	second=new Node;
	second->data=A[0];
	second->next=NULL;
	last=second;
	for(i=1;i<n;i++)
	{
		t=new Node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void Display(Node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}

void Concat(Node *p, Node *q){
	third=p;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=q;
}

void Merge(Node *p, Node *q){
	Node *last;
	if(p->data<q->data){
		third=last=p;
		p=p->next;
		third->next=NULL;
	}
	else if(q->data<p->data){
		third=last=q;
		q=q->next;
		third->next=NULL;
	}
	while(p!=NULL && q!=NULL){
		if(p->data<q->data){
			last->next=p;
			last=p;
			p=p->next;
			last->next=NULL;
		}
		else if(q->data<p->data){
			last->next=q;
			last=q;
			q=q->next;
			last->next=NULL;
		}
	}
	if(p!=NULL){
		last->next=p;
	}
	else if(q!=NULL){
		last->next=q;
	}
}

int main(){
	int A[]={10,20,30,40,50};
	int B[]={5,15,25,35,45};
	create(A,5);
	create2(B,5);
	cout<<"First: ";
	Display(first);
	cout<<"\nSecond: ";
	Display(second);
//	cout<<"\nConcatenated LL: ";
//	Concat(first,second);
//	Display(third);
	cout<<"\nMerged LL: ";
	Merge(first,second);
	Display(third);
}
