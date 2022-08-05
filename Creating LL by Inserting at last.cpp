#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
}*first=NULL;

void Display(Node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}

void InsertLast(int x){
	Node *t = new Node;
	t->data = x;
	t->next = NULL;
	Node *last;
	if(first==NULL){
		first=last=t;
	}
	else{
		last->next = t;
		last = t;
	}
}

int main(){
	InsertLast(8);
	InsertLast(4);
	InsertLast(5);
	InsertLast(1);
	Display(first);
}
