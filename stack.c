
#include <stdio.h>
#include <stdlib.h>

// Stack Node
typedef struct StackNode
{
	// Define useful field of StackNode
	int data;
	struct StackNode * next;
}StackNode;

StackNode * getStackNode(int data, StackNode * top)
{
	// Create dynamic memory of StackNode
	StackNode * ref = (StackNode * ) malloc(sizeof(StackNode));
	if (ref == NULL)
	{
		// Failed to create memory 
		return NULL;
	}
	ref->data = data;
	ref->next = top;
	return ref;
}
typedef struct MyStack
{
	// Define useful field of MyStack
	struct StackNode * top;
	int count;
}MyStack;

MyStack * getMyStack()
{
	// Create dynamic memory of MyStack
	MyStack * ref = (MyStack * ) malloc(sizeof(MyStack));
	if (ref == NULL)
	{
		// Failed to create memory 
		return NULL;
	}
	ref->top = NULL;
	ref->count = 0;
	return ref;
}
// Returns the number of element in stack
int size(MyStack * ref)
{
	return ref->count;
}
int isEmpty(MyStack * ref)
{
	if (size(ref) > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
// Add a new element in stack
void push(MyStack * ref, int data)
{
	// Make a new stack node
	// And set as top
	ref->top = getStackNode(data, ref->top);
	// Increase node value
	ref->count++;
}
// Add a top element in stack
int pop(MyStack * ref)
{
	int temp = 0;
	if (isEmpty(ref) == 0)
	{
		// Get remove top value
		temp = ref->top->data;
		ref->top = ref->top->next;
		// Reduce size
		ref->count--;
	}
	return temp;
}
// Used to get top element of stack
int peek(MyStack * ref)
{
	if (!isEmpty(ref))
	{
		return ref->top->data;
	}
	else
	{
		return 0;
	}
}
int main()
{
	// Create new stack 
	MyStack * s = getMyStack();
	printf("\n Is empty : %d", isEmpty(s));
	// Add element
	push(s, 15);
	push(s, 14);
	push(s, 31);
	push(s, 21);
	push(s, 10);
	printf("\n Top  :  %d", peek(s));
	printf("\n Size :  %d", size(s));
	printf("\n Is empty :  %d", isEmpty(s));
	// Delete Stack Element
	int data = pop(s);
	printf("\n Pop element  %d", data);
	printf("\n Size :  %d", size(s));
	data = pop(s);
	printf("\n Pop element  %d", data);
	printf("\n Size :  %d", size(s));
}