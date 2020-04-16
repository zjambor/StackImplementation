#include <iostream>
using namespace std;

class Stack
{
public:
	enum Exceptions { EMPTYSTACK, FULLSTACK };
	Stack();
	~Stack();

	Stack(const Stack&);
	Stack& operator=(const Stack&);

	void Push(int e);
	int Pop();
	int Top() const;
	bool Empty() const;

private:
	struct Node {
		int val;
		Node* next;
		Node(int e, Node* n) : val(e), next(n) {}
	};

	Node* head;
};
