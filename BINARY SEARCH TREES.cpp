#include<iostream>
using namespace std;

class Node{
	public:
		Node *lchild;
		int data;
		Node *rchild;
}*root=NULL,*root1=NULL;

void Insert(Node *t,int key){
	Node *r=NULL,*p;
	if(root==NULL){
		p=new Node;
		p->data=key;
		p->lchild=p->rchild=NULL;
		root=p;
		return;
	}
	while(t!=NULL){
		r=t;
		if(key==t->data){
			return;
		}else if(key<t->data){
			t=t->lchild;
		}else{
			t=t->rchild;
		}
	}
	p=new Node;
	p->data=key;
	p->lchild=p->rchild=NULL;
	if(p->data<r->data){
		r->lchild=p;
	}else{
		r->rchild=p;
	}
}

Node *RInsert(Node *p,int key){
	Node *t;
	if(p==NULL){
		t=new Node;
		t->data=key;
		t->lchild=t->rchild=NULL;
		return t;
	}
	if(key<p->data){
		p->lchild=RInsert(p->lchild,key);
	}else if(key>p->data){
		p->rchild=RInsert(p->rchild,key);
	}
	return p;
}

void RInorder(Node *p){
	if(p!=NULL){
		RInorder(p->lchild);
		cout<<p->data<<" ";
		RInorder(p->rchild);
	}
}

Node *Search(Node *t,int key){
	while(t!=NULL){
		if(key==t->data){
			return t;
		}else if(key<t->data){
			t=t->lchild;
		}else{
			t=t->rchild;
		}
	}
	return NULL;
}

Node *RSearch(Node *t,int key){
	if(t==NULL){
		return NULL;
	}
	if(key==t->data){
		return t;
	}
	else if(key<t->data){
		return RSearch(t->lchild,key);
	}
	else{
		return RSearch(t->rchild,key);
	}
}

int Height(Node *p) {
    int x;
    int y;
    if (p == NULL){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
 
Node* InPre(Node *p) {
    while (p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}
 
Node* InSucc(Node *p) {
    while (p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

Node* Delete(Node *p, int key) {
    Node* q;
 
    if (p == NULL){
        return NULL;
    }
 
    if (p->lchild == NULL && p->rchild == NULL){
        if (p == root){
            root = NULL;
        }
        delete p;
        return NULL;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main(){
	cout<<"------ITERATIVE PROCESS------"<<endl;
	Insert(root,10);
	Insert(root,5);
	Insert(root,20);
	Insert(root,8);
	Insert(root,30);

	Delete(root,10);
	
	RInorder(root);
	cout<<endl;
	
	Node *temp;
	temp=Search(root,20);
	if(temp!=NULL){
		cout<<"Element "<<temp->data<<" is found"<<endl;
	}
	else if(temp==NULL){
		cout<<"Element not found"<<endl;
	}
	
	cout<<endl<<"------RECURSION PROCESS------"<<endl;
	root1=RInsert(root1,50);
	RInsert(root1,10);
	RInsert(root1,40);
	RInsert(root1,20);
	RInsert(root1,30);
	
	Delete(root1,50);
	
	RInorder(root1);
	cout<<endl;
	
	Node *temp1;
	temp1=RSearch(root1,80);
	if(temp1!=NULL){
		cout<<"Element "<<temp1->data<<" is found"<<endl;
	}
	else if(temp1==NULL){
		cout<<"Element not found"<<endl;
	}
	
	
	
}
