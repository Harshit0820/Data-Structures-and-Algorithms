#include<iostream>
using namespace std;

class Node{
	public:
		Node *lchild;
		int data;
		int height;
		Node *rchild;
}*root=NULL;

int NodeHeight(Node *p){
	int hl,hr;
	hl=p && p->lchild ? p->lchild->height:0;
	hr=p && p->rchild ? p->rchild->height:0;
	
	return hl>hr ? hl+1 : hr+1;
}

int BalanceFactor(Node *p){
	int hl,hr;
	hl=p && p->lchild ? p->lchild->height:0;
	hr=p && p->rchild ? p->rchild->height:0;
	
	return hl-hr;
}

Node *LLRotation(Node *p){
	Node *pl=p->lchild;
	Node *plr=pl->rchild;
	
	pl->rchild=p;
	p->lchild=plr;
	p->height=NodeHeight(p);
	pl->height=NodeHeight(pl);
	
	if(root==p)
		root=pl;
	
	return pl;
}

Node *LRRotation(Node *p){
	Node *pl=p->lchild;
	Node *plr=pl->rchild;
	
	pl->rchild=plr->lchild;
	p->lchild=plr->rchild;
	
	plr->lchild=pl;
	plr->rchild=p; 
	
	pl->height=NodeHeight(pl);	
	p->height=NodeHeight(p);
	plr->height=NodeHeight(plr);
	
	if(root==p)
		root=plr;
	
	return plr;
}

Node *RRRotation(Node *p){
	return NULL;
}

Node *RLRotation(Node *p){
	return NULL;
}

Node *RInsert(Node *p,int key){
	Node *t=NULL;
	if(p==NULL){
		t=new Node;
		t->data=key;
		t->height=1;//we are starting height from 1 though height starts from 0 in notes
		t->lchild=t->rchild=NULL;
		return t;
	}
	if(key<p->data){
		p->lchild=RInsert(p->lchild,key);
	}else if(key>p->data){
		p->rchild=RInsert(p->rchild,key);
	}
	p->height=NodeHeight(p);
	
	//NOW ROTATION
	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
		return LLRotation(p);
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
		return LRRotation(p);
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
		return RRRotation(p);
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
		return RLRotation(p);
	
	return p;
}

int main(){
	root=RInsert(root,50);
	RInsert(root,10);
	RInsert(root,20);
	
	// LL ROTATION
	
//		10 imbalance  =====>>>>>>       5 
//	 5				  LL rotation   2       10
//2
//height = 3						height = 2    (Note:height starting from 1 here and not 0);


// ------------------------------------------------------------------------------------------------

	// LR ROTATION
	
//		50 imbalance  =====>>>>>>        20 
//	10				  LR rotation   10        50
//		20
//height = 3						height = 2    (Note:height starting from 1 here and not 0);
	
}
