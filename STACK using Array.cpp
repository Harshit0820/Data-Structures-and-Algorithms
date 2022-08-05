#include<iostream>
using namespace std;

class Stack{
	public:
		int size;
		int top;
		int *S;
};

void create(Stack *st){
	cout<<"Enter size of stack: ";
	cin>>st->size;
	st->top=-1;
	st->S=new int[st->size];
}

void Display(Stack st){
	int i;
	for(i=st.top;i>=0;i--){
		cout<<st.S[i]<<" ";
	}	
	cout<<endl;
}

void push(Stack *st, int x){
	if(st->top==st->size-1){
		cout<<"Stack is full"<<endl;
	}
	else{
		st->top++;
		st->S[st->top]=x;
	}
}

int pop(Stack *st){
	int x=-1;
	if(st->top==-1){
		cout<<"Stack is empty"<<endl;
	}
	else{
		x=st->S[st->top--];
	}
	return x;
}

int peek(Stack st, int index){
	int x=-1;
	if(st.top-index+1<0){
		cout<<"Invalid index";
	}
	else{
		x=st.S[st.top-index+1];
	}
	return x;
}

int isEmpty(struct Stack st){
	if(st.top==-1)
		return 1;
	return 0;
}

int isFull(struct Stack st){
	if(st.top==st.size-1)
		return 1;
	return 0;
}

int stackTop(struct Stack st){
	if(!isEmpty(st))
		return st.S[st.top];
	return -1;
}

int main(){
	Stack st;
	create(&st);
	push(&st,10);
	push(&st,20);
	push(&st,30);
	push(&st,40);
	push(&st,50);

	Display(st);
	
	cout<<"Peeked: "<<peek(st,1)<<endl;
	cout<<"Peeked: "<<peek(st,2)<<endl;
	
	cout<<"Empty: "<<isEmpty(st)<<endl;
	
	cout<<"Full: "<<isFull(st)<<endl;
	
	cout<<"Top of stack: "<<stackTop(st)<<endl;
	
	cout<<"Deleted: "<<pop(&st)<<endl;
	cout<<"Deleted: "<<pop(&st)<<endl;

	Display(st);

}
