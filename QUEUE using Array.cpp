#include<iostream>
using namespace std;

class Queue{
	public:
		int size;
		int front;
		int rear;
		int *Q;
};

void create(Queue *q, int size){
	q->size=size;
	q->front=q->rear=-1;
	q->Q=new int [size];
}

void enqueue(Queue *q,int x){
	if(q->rear==q->size-1){
		cout<<"Queue is full"<<endl;
	}
	else{
		q->rear++;
		q->Q[q->rear]=x;
	}
}

int dequeue(Queue *q){
	int x=-1;
	if(q->front==q->rear){
		cout<<"Queue is empty"<<endl;
	}
	else{
		q->front++;
		x=q->Q[q->front];
	}
	return x;
}

void Display(Queue q){
	for(int i=q.front+1; i<=q.rear; i++){
		cout<<q.Q[i]<<" ";
	}
	cout<<endl;
}

int main(){
	Queue q;
	create(&q,5);
	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	enqueue(&q,40);
	enqueue(&q,50); 
	Display(q);
	cout<<"Deleted: "<<dequeue(&q)<<endl;
	cout<<"Deleted: "<<dequeue(&q)<<endl;
	Display(q);
	
	
}
