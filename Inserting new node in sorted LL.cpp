#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Node{
	public:
		int data;
		struct Node *next;
}*first=NULL;

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

void Display(Node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}

void SortedInsert(Node *p,int x){
	Node *t = new Node;
	Node *q=NULL;
	t->data = x;
	t->next = NULL;
	if(first==NULL){
		first=t;
	}
	else{
		while(p && p->data<x){
			q=p;
			p=p->next;
		}
		if(p==first){
			t->next=first;
			first=t;
		}
		else{
			t->next=q->next;
			q->next=t;
		}
	}
}

int main(){
	int A[]={10,20,30,40,50};
	create(A,5);
	Display(first);
	SortedInsert(first,35);
	cout<<endl;
	Display(first);
	SortedInsert(first,65);
	cout<<endl;
	Display(first);
	SortedInsert(first,5);
	cout<<endl;
	Display(first);
	return 0;
}
