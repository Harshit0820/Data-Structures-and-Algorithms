#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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

int count_recur(Node *p){
	if(p!=NULL){
		return count_recur(p->next)+1;
	}else{
		return 0;
	}
}
void Insert(Node *p,int index,int x){
	Node *t;
	int i;
	if(index < 0 || index > count_recur(p))
	return;
	t=new Node;
	t->data=x;
	if(index == 0){
		t->next=first;
		first=t;
	}
	else{
	for(i=0;i<index-1;i++)
		p=p->next;
	t->next=p->next;
	p->next=t;
	}
}

int main()
{
	int A[]={10,20,30,40,50};
	create(A,5);
	Insert(first,0,5);
	Insert(first,4,9);
	Insert(first,7,2);
	Display(first);
	return 0;
}
