#include<iostream>
using namespace std;

class Node{
	public:
		Node *lchild;
		int data;
		Node *rchild;
}*root=NULL;

class Queue{
	public:
		int size;
		int front;
		int rear;
		Node * *Q;
};

void create_queue(Queue *q, int size){
	q->size=size;
	q->front=q->rear=0;
	q->Q=new Node* [size];
}

void enqueue(Queue *q,Node * x){
	if((q->rear+1)%q->size==q->front){
		cout<<"Queue is full"<<endl;
	}
	else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	}
}

Node * dequeue(Queue *q){
	Node* x=NULL;
	if(q->front==q->rear){
		cout<<"Queue is empty"<<endl;
	}
	else{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(Queue q){
	return q.front==q.rear;
}

void create(){
	Node *p,*t;
	int x;
	Queue q;
	create_queue(&q,100);//making queue of size 100
	cout<<"Enter root value: ";
	cin>>x;
	root=new Node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	
	while(!isEmpty(q)){
		p=dequeue(&q);
		cout<<"Enter Left child of "<<p->data<<": ";
		cin>>x;
		if(x!=-1){
			t=new Node;
			t->data=x;
			t->lchild=NULL;
			t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		 
		cout<<"Enter Right child of "<<p->data<<": ";
		cin>>x;
		if(x!=-1){
			t=new Node;
			t->data=x;
			t->lchild=NULL;
			t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
}

void preorder(Node *p){
	if(p){
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);

	}
}

void inorder(Node *p){
	if(p){
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);

	}
}

void postorder(Node *p){
	if(p){
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<" ";


	}
}

void levelorder(Node *p){
	Queue q;
	create_queue(&q,100);//making queue of size 100
	cout<<p->data<<" ";
	enqueue(&q,p);
	while(!isEmpty(q)){
		p=dequeue(&q);
		if(p->lchild){
			cout<<p->lchild->data<<" ";
			enqueue(&q,p->lchild);
		}
		if(p->rchild){
			cout<<p->rchild->data<<" ";
			enqueue(&q,p->rchild);
		}
	}
	
}

int Count(Node *p) {
    int x;
    int y;
    if (p != NULL){
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int Height(Node *root){
	int x=0,y=0;
	if(root==0)
		return -1;
	x=Height(root->lchild);
	y=Height(root->rchild);
	if(x>y)
		return x+1;
	else
		return y+1;
}

int Sum(Node *p) {
    int x;
    int y;
    if (p != NULL){
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}
 
int deg2NodeCount(Node *p) {
    int x;
    int y;
    if (p != NULL){
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        if (p->lchild && p->rchild){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int leafNodeCount(Node *p) {
    int x;
    int y;
    if (p != NULL){
        x = leafNodeCount(p->lchild);
        y = leafNodeCount(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
int deg1ordeg2NodeCount(Node *p) {
    int x;
    int y;
    if (p != NULL){
        x = deg1ordeg2NodeCount(p->lchild);
        y = deg1ordeg2NodeCount(p->rchild);
        if (p->lchild != NULL || p->rchild != NULL){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
int deg1NodeCount(Node *p) {
    int x;
    int y;
    if (p != NULL){
        x = deg1NodeCount(p->lchild);
        y = deg1NodeCount(p->rchild);
        if (p->lchild != NULL ^ p->rchild != NULL){ // done using XOR ^
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int main(){
	create();
	
	cout<<"Preorder: ";
	preorder(root);//to display from left side
	cout<<endl;
	
	cout<<"Inorder: ";
	inorder(root);//to display from middle side
	cout<<endl;
	
	cout<<"Postorder: ";
	postorder(root);//to display from right side
	cout<<endl;
	
	cout<<"Levelorder: ";
	levelorder(root);//to display level by level
	cout<<endl;
	
	cout<<"No. of nodes in tree: "; 
	cout<<Count(root);//will give total no. of nodes in tree
	cout<<endl;
	
	cout<<"Height of Tree: "; 
	cout<<Height(root);//height of tree starts from 0 i.e. from root node
	cout<<endl;
	
	cout<<"Sum of elements of Tree: "; 
	cout<<Sum(root);//will give sum of all elts of tree
	cout<<endl;
	
	cout<<"Nodes with deg 2 in Tree: "; 
	cout<<deg2NodeCount(root);//will give no. of nodes with deg 2
	cout<<endl;
	
	cout<<"No. of Leaf Nodes: ";
	cout<<leafNodeCount(root);//will count no. of leaf nodes i.e. with deg 0
	cout<<endl;
	
	cout<<"No. of Non Leaf Nodes: ";
	cout<<deg1ordeg2NodeCount(root);//will count no. of non leaf nodes i.e. with deg 1 or 2
	cout<<endl;
	
	cout<<"Nodes with deg 1 in Tree: ";
	cout<<deg1NodeCount(root);//will give no. of nodes with deg 1
	cout<<endl;
	
}
