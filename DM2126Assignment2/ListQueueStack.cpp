#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    <Li Zhaoyuan>
 *  \date      2015 
 *  \note      <150592K>
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList()
{
	head = 0;
}

LinkedList::~LinkedList()
{

}

void LinkedList::push_front(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* curr = head;
		Node* temp = new Node(data);
		temp->next = curr;
		head = temp;
	}
}

void LinkedList::push_back(int data)
{
	
	Node* curr = head;
	
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = new Node(data);
	}
}

int LinkedList::pop_front()
{
	if (head == 0)
	{
		return 0;
	}
	Node* curr = head;
	int temp = 0;
	head = curr->next;
	temp = curr->data;
	delete curr;
	return temp;
}

int LinkedList::pop_back()
{
	if (head == 0)
	{
		return 0;
	}
	else if (head->next == nullptr)
	{
		return pop_front();
	}
	Node* curr = head->next;
	Node* prev = head;
	int temp = 0;
	while (curr->next != nullptr)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = nullptr;
	temp = curr->data;
	delete curr;
	return temp;
}

void LinkedList::insert_at(int pos, int data)
{
	Node* curr = head;
	Node* prev = curr;
	Node* newNode = new Node(data);
	int num = size();
	if (pos <= 0)
	{
		push_front(data);
	}
	else if (pos < num)
	{
		int i = 0;
		while (curr->next != nullptr && i < pos)
		{
			prev = curr;
			curr = curr->next;
			i += 1;
		}
		newNode->next = curr;
		prev->next = newNode;
	}
	else
	{
		/*while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newNode;*/
		push_back(data);
	}
	
	
	
}

int LinkedList::pop_at(int pos)
{
	Node* curr = head;
	Node* prev = curr;
	int i = 0;
	int temp = 0;
	if (pos >= (int)size())
	{
		return 0;
	}
	else if (pos <= 0)
	{
		return pop_front();
	}
	else if (pos == (int)size() - 1)
	{
		return pop_back();
	}
	i += 1;
	curr = curr->next;
	while (i < pos)
	{
		prev = curr;
		curr = curr->next;
		i += 1;
	}
	prev->next = curr->next;
	temp = curr->data;
	delete curr;
	return temp;
}

size_t LinkedList::size()
{
	if (head == 0)
	{
		return 0;
	}
	size_t size = 1;
	Node* curr = head;
	while (curr->next != nullptr)
	{
		size += 1;
		curr = curr->next;
	}
    return size;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue()
{
	front = 0;
	back = 0;
}

Queue::~Queue()
{

}

void Queue::enqueue(int data)
{
	if (size() == 0)
	{
		front = new Node(data);
		back = new Node(data);
	}
	else
	{
		Node* curr = front;
		Node* newNode = new Node(data);
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newNode;
		back = curr->next;
	}
}

int Queue::dequeue()
{
	if (front == 0)
	{
		back = 0;
		return 0;
	}
	else if (front->next == 0)
	{
		Node* curr = front;
		int temp = curr->data;
		delete curr;
		front = 0;
		back = 0;
		return temp;
	}
	Node* curr = front;
	Node* prev = curr;
	int temp = 0;
	front = curr->next;
	temp = prev->data;
	/*while (curr->next != 0)
	{
		curr = curr->next;
	}
	back = curr;*/
	delete prev;
	return temp;
}

size_t Queue::size()
{
	Node* curr = front;
	int size = 0;
	while (curr != nullptr)
	{
		size += 1;
		curr = curr->next;
	}
    return size;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{
	top = 0;
}

Stack::~Stack()
{

}

void Stack::push(int data)
{
	if (top == 0)
	{
		top = new Node(data);
		top->next = 0;
	}
	else
	{
		Node* newNode = new Node(data);
		newNode->next = top;
		top = newNode;
	}
}

int Stack::pop()
{
	if (top != 0)
	{
		Node* curr = top;
		int temp = 0;
		temp = curr->data;
		top = top->next;
		delete curr;
		return temp;
	}
	return 0;
	
}

size_t Stack::size()
{
	if (top == 0)
	{
		return 0;
	}
	Node* curr = top;
	size_t size = 1;
	while (curr->next != nullptr)
	{
		size += 1;
		curr = curr->next;
	}

    return size;
}
