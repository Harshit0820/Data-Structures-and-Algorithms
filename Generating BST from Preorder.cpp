#include<iostream>
#include<stack>
using namespace std;

class Node{
	public:
		Node *lchild;
		int data;
		Node *rchild;
}*root=NULL;

void createPre(int *pre,int n){
	int i=0;
    root=new Node;
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    Node* t;
    Node* p=root;
    stack<Node*> stk;
	
	while(i<n){
		if(pre[i]<p->data){
			t=new Node;
			t->data=pre[i++];
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			stk.push(p);
			p=t;
		}
		else{
			if(pre[i]>p->data && pre[i]<stk.empty()?32767:stk.top()->data){
				t=new Node;
				t->data=pre[i++];
				t->lchild=t->rchild=NULL;
				p->rchild=t;
				p=t;
			}
			else{
			p=stk.top();
			stk.pop();
			}
		}
	}
}

void RInorder(Node *p){
	if(p!=NULL){
		RInorder(p->lchild);
		cout<<p->data<<" ";
		RInorder(p->rchild);
	}
}

int main(){
	int pre[]={30,20,10,15,25,40,50,45};
	int n=sizeof(pre)/sizeof(pre[0]);
	createPre(pre,n);
	RInorder(root);

}
