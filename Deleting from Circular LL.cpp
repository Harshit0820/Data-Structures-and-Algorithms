#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
}*Head;

void create(int A[], int n){
	int i;
	Node *t ,*last;
	Head=new Node;
	Head->data=A[0];
	Head->next=Head;
	last=Head;
	
	for(i=1;i<n;i++){
		t=new Node;
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}

void Display(Node *h){
	do{
		cout<<h->data<<" ";
		h=h->next;
	}while(h!=Head);
	cout<<endl;
}

int Length(Node *p){
	int len=0;
	do{
		len++;
		p=p->next;
	}while(p!=Head);
	return len;
}

void Delete(Node *p, int index){
	Node *q;
	int i,x;
	
	if(index<0 || index>Length(Head))
		return;
	
	if(index==1){
		while(p->next!=Head){
			p=p->next;
		}
		x=Head->data;
		if(Head==p){
			delete Head;
			Head=NULL;
		}
		else{
			p->next=Head->next;
			delete Head;
			Head=p->next;
		}
	}else{
		for(i=0;i<index-2;i++){
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		x=q->data;
		delete q;
		
	}
}

int main(){
	int A[]={2,3,4,5,6};
	create(A,5);
	Delete(Head,1);//remove 2
	Delete(Head,2);//remove 4
	Delete(Head,3);//remove 6
	Display(Head);
}
