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

void Insert(Node *p, int index, int x){
	Node *t;
	int i;
	
	if(index<0 || index>Length(Head))
		return;
	
	if(index==0){
		t=new Node;
		t->data=x;
		if(Head==NULL){
			Head=t;
			Head->next=Head;
		}
		else{
			while(p->next!=Head){
				p=p->next;
			}
			p->next=t;
			t->next=Head;
			Head=t;
		}
	}else{
		for(i=0;i<index-1;i++){
			p=p->next;
		}
		t=new Node;
		t->data=x;
		t->next=p->next;
		p->next=t;
	}
}

int main(){
	int A[]={2,3,4,5,6};
	create(A,5);
	Insert(Head,2,10);
	Insert(Head,0,1);
	Insert(Head,7,8);
	Display(Head);
	
}
