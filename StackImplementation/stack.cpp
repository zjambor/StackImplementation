#include "stack.h"


Stack::Stack() : head(NULL) {}
Stack::~Stack()
{
	Node* p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

void Stack::Push(int e)
{
	try
	{
		head = new Node(e, head);
	}
	catch (const std::bad_alloc o)
	{
		throw FULLSTACK;
	}
}

int Stack::Pop()
{
	if (NULL == head) throw EMPTYSTACK;

	int e = head->val;
	Node* n = head;
	head = head->next;
	delete n;
	return e;
}

int Stack::Top()const
{
	if (NULL == head) throw EMPTYSTACK;
	return head->val;
}

bool Stack::Empty()const
{
	return NULL == head;
}

Stack::Stack(const Stack& s)
{
	if (NULL == s.head) head = NULL;
	else
	{
		try
		{
			head = new Node(s.head->val, NULL);
		}
		catch (const std::bad_alloc& o)
		{
			throw FULLSTACK;
		}

		Node* q = head;
		Node* p = s.head->next;

		while (p != NULL)
		{
			try
			{
				q->next = new Node(p->val, NULL);
			}
			catch (const std::bad_alloc& o)
			{
				throw FULLSTACK;
			}			
			q = q->next;
			p = p->next;
		}
	}
}

Stack& Stack::operator=(const Stack& s)
{
	if (&s == this) return *this;

	Node* p;
	while (head != NULL)
	{
		p = head;
		head = p->next;
		delete p;
	}

	if (NULL == s.head) head = NULL;
	else
	{
		try
		{
			head = new Node(s.head->val, NULL);
		}
		catch (const std::bad_alloc& o)
		{
			throw FULLSTACK;
		}

		Node* p = head;
		Node* q = s.head->next;

		while (q != NULL)
		{
			try
			{
				p->next = new Node(q->val, NULL);
			}
			catch (const std::bad_alloc& o)
			{
				throw FULLSTACK;
			}			
			q = q->next;
			p = p->next;
		}
	}
	return *this;
}