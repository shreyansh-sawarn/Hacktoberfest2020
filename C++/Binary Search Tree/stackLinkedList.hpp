#include<iostream>

using namespace std;

template<class Type>
class stackLinkedList
{
	public:
		struct node
		{
			Type data;
			struct node *next;
		};
		struct node *head=nullptr, *newNode, *temp, *top=nullptr;
		int ch;
		
		~stackLinkedList();
				
		void push(Type);
		Type pop();
        Type peek();
		
		bool isEmpty();
};

template<class Type>
stackLinkedList<Type>::~stackLinkedList()
{
	struct node *temp1;
	temp = head;
	while(temp != nullptr)
	{
		temp1 = temp -> next;
		delete(temp);
		temp = temp1;
	}
}

template<class Type>
void stackLinkedList<Type>::push(Type a)
{
	newNode = (struct node *)new struct node;
	newNode -> data = a;
	newNode -> next = nullptr;
	if(isEmpty())
	{
		head = top = temp = newNode;
	}
	else
	{
		top -> next = newNode;
		top = temp = newNode;
	}
}

template<class Type>
Type stackLinkedList<Type>::pop()
{
	Type ele = top -> data;
	if(top == head)
	{
		delete(head);
		top = head = nullptr;
	}
	else
	{
		temp = head;
		while(temp -> next -> next != nullptr)
		{
			temp = temp -> next;
		}
		delete(top);
		temp -> next = nullptr;
		top = temp;
	}
	return ele;
}

template<class Type>
Type stackLinkedList<Type>::peek()
{
    return top -> data;
}

template<class Type>
bool stackLinkedList<Type>::isEmpty()
{
	if(top == nullptr)
	{
		return true;
	}
	return false;
}