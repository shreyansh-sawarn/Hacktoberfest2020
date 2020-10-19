#include<iostream>

using namespace std;

template<class Type>
class queueLinkedList
{
	public:
		
		struct node1
		{
			Type data;
			struct node1 *next;
		};
		struct node1 *front, *rear, *newNode1, *temp1;
		
		queueLinkedList();
		~queueLinkedList();
		
		void enqueue(Type);
		Type dequeue();
		Type frontEle();
		int size();
		bool isEmpty();
};

template<class Type>
queueLinkedList<Type>::queueLinkedList()
{
	front = NULL;
	rear = NULL;
}

template<class Type>
queueLinkedList<Type>::~queueLinkedList()
{
	while(!isEmpty())
		dequeue();
}

template<class Type>
void queueLinkedList<Type>::enqueue(Type n)
{
	newNode1 = new struct node1;
	newNode1 -> data = n;
	newNode1 -> next = NULL;
	if(front == NULL && rear == NULL)
	{
		front = rear = newNode1;
	}
	else
	{
		rear -> next = newNode1;
		rear = newNode1;
	}
}

template<class Type>
Type queueLinkedList<Type>::dequeue()
{
	Type x;
	temp1 = front;
	if(front == rear)
	{
		x = front -> data;
		front = rear = NULL;
	}
	else
	{	
		x = temp1 -> data;
		front = temp1 -> next;
	}
	delete(temp1);
	return x;
}

template<class Type>
Type queueLinkedList<Type>::frontEle()
{
	return front -> data;
}

template<class Type>
int queueLinkedList<Type>::size()
{
	int ctr=0;
	temp1 = front;
	if(isEmpty())
		return ctr;
	else
	{
		while(temp1 != nullptr)
		{
			ctr++;
			temp1 = temp1 -> next;
		}
		return ctr;
	}
}

template<class Type>
bool queueLinkedList<Type>::isEmpty()
{
	temp1 = front;
	if(temp1 == NULL)
		return true;
	return false;
}