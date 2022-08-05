#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
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

int findMiddle(Node *f){
	int x=-1;
	Node *p = first;
	Node *q = first;
	while(q!=NULL){
		q=q->next;
		if(q!=NULL){
			q=q->next;
			if(q!=NULL){
				p=p->next;
				x=p->data;
			}
		}
	}
	return x;
}

int main(){
	int A[]={10,20,30,40,50,60};
	create(A,6);
	Display(first);
	cout<<endl;
	cout<<findMiddle(first);
}
