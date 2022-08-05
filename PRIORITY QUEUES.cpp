#include<iostream>
using namespace std;

class Queue{
	public:
		int size;
		int front;
		int *Q;
};

void create(Queue *q,int n){
	q->size=n;
	q->front=-1;
	q->Q=new int[n];
}

void enqueue(Queue *q, int n){
	if(q->front==-1){
		q->Q[++q->front]=n;
	}
	else{
		int i=q->front;
		while(i!=-1 && q->Q[i]<n){
			q->Q[i+1]=q->Q[i];
			i--;
		}
		q->Q[i+1]=n;
		q->front++;
	}
}

int dequeue(Queue *q){
	return q->Q[q->front--];
}

int main(){
	Queue q;
	int A[]={3,5,7,23,15,88,82,2,10,94};
	int x=sizeof(A)/sizeof(A[0]);
	create(&q,x);
	for(int i=0;i<x;i++){
        enqueue(&q,A[i]);
    }
    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
}
