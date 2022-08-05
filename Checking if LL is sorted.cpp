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

int isSorted(Node *p){
	int x=-32786;
	while(p!=NULL){
		if(p->data<x)
			return 0;
		x=p->data;
		p=p->next;
	}
	return 1;
}

int main(){
	int A[]={10,20,30,40,50};
	create(A,5);
	Display(first);
	cout<<endl;
	if(isSorted(first)==1){
		cout<<"LL is sorted";
	}else{
		cout<<"LL is not sorted";
	}
}
