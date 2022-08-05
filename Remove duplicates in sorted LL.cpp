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

int remove(Node *p){
	Node *q=p->next;
	while(q!=NULL){
		if(p->data!=q->data){
			p=q;
			q=q->next;
		}
		else{
			p->next=q->next;
			delete q;
			q=p->next;
		}
	}
}

int main(){
	int A[]={10,20,20,30,40,40,40,50,50};
	create(A,9);
	Display(first);
	remove(first);
	cout<<endl;
	Display(first);
}
