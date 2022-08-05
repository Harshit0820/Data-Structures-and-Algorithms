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

void Delete(Node *p, int index){
	Node *q;
	int x=-1,i;
	if(index<0 || index>Length(first))
		return;
	if(index==1){
		first=first->next;
		if(first!=NULL){
			first->prev=NULL;
		}
		x=p->data;
		delete p;
	}else{
		for(i=0;i<index-1;i++){
			p=p->next;
		}
		p->prev->next=p->next;
		if(p->next!=NULL){
			p->next->prev=p->prev;
		}
		x=p->data;
		delete p;
	}
}

int main(){
	int A[]={10,20,30,40,50};
	create(A,5);
	Delete(first,1);//remove 10
	Delete(first,2);//remove 30
	Delete(first,3);//remove 50
	Display(first);
}
