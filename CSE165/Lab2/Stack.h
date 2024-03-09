#pragma once

struct Stack {
	struct Link {
		void* data;
		Link* next;
		
		void initialize( void* dat, Link* nxt );
	}*head;
	
	void initialize();
	void cleanup();
	void push( void* dat );
	void* peek();
	void* pop();

	void (*deletecb)(void * pt);
	void setDeleteCallback(void(*delcb) (void *pt))
   	{
       deletecb = delcb;
   	}
	Stack();
    Stack(int N);
    ~Stack();
};
