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

int Delete(Node *p, int pos){
	Node *q;
	int x=-1,i;
	if(pos == 1){
		x=first->data;
		p=first;
		first=first->next;
		delete p;
		return x;
	}
	else{
		p=first;
		q=NULL;
		for(i=0;i<pos-1&&p;i++){
			q=p;
			p=p->next;
		}
		if(p){
			q->next=p->next;
			x=p->data;
			delete p;
		}
	}
	return x;
}

int main(){
	int A[]={10,20,30,40,50};
	create(A,5);
	Display(first);
	Delete(first,1);
	cout<<endl;
	Display(first);
	Delete(first,3);
	cout<<endl;
	Display(first);
	Delete(first,3);
	cout<<endl;
	Display(first);
}
