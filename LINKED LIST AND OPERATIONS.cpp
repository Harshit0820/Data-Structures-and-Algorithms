#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};

void Display(struct Node *p){
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}

void recur_display(Node *p){
	if(p!=NULL){
		cout<<p->data<<" ";
		recur_display(p->next);
	}	
}

void recur_display2(Node *p){
	if(p!=NULL){
		recur_display2(p->next);
		cout<<p->data<<" ";
	}
}

void count(Node *p){
	int count = 0;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	cout<<endl<<"Number of nodes: "<<count;
}

int count_recur(Node *p){
	if(p!=NULL){
		return count_recur(p->next)+1;
	}else{
		return 0;
	}
}

void sum(Node *p){
	int sum=0;
	while(p!=NULL){
		sum = sum+p->data;
		p = p->next;
	}
	cout<<endl<<"Sum: "<<sum;
}

int sum_recur(Node *p){
	if(p!=NULL){
		return sum_recur(p->next)+p->data;
	}else{
		return 0;
	}
}

void max(Node *p){
	int m = INT_MIN;
	while(p!=NULL){
		if(p->data > m)
			m = p->data;
		p = p->next;
	}
	cout<<endl<<"Max is: "<<m;
}

int max_recur(Node *p){
	int x = 0;
	if(p==NULL){
		return INT_MIN;
	}
	else{
		x = max_recur(p->next);
		if(x>p->data){
			return x;
		}else{
			return p->data;
		}
	}
}

Node *search(Node *p, int key){
	while(p!=NULL){
		if(key == p->data){
			return p;
			
		}
		p = p->next;
	}
	return NULL;
}

Node *search_recur(Node *p, int key){
	if(p==NULL){
		return NULL;
	}
	if(key==p->data){
		return p;
	}
	return search_recur(p->next,key);
}

int main(){
	int A[] = {1,3,5,7,9,8,2};
	
	Node *head = new Node;
	
	Node *temp;
	Node *last;
	
	head->data = A[0];
	head->next = NULL;
	last = head;
	
	for(int i=1;i<sizeof(A)/sizeof(A[0]);i++){
		temp = new Node;
		
		temp->data = A[i];
		temp->next = NULL;
		
		last->next = temp;
		last = temp;
	}
	
	Node *p = head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p = p->next;
	}
	
	cout<<endl<<"Recursion: ";
	recur_display(head);
	
	cout<<endl<<"Recursion other: ";
	recur_display2(head);
	
	count(head);
	
	cout<<endl<<"Number of nodes using recursion: "<<count_recur(head);
	
	sum(head);
	
	cout<<endl<<"Sum using recursion: "<<sum_recur(head);
	
	max(head);
	
	cout<<endl<<"Max using recursion is: "<<max_recur(head);
	
	cout<<endl<<"Searching the key: "<<search(head,9);
	
	cout<<endl<<"Searching the key using recursion: "<<search(head,9);
	
	
	
	
}
