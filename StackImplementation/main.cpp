#include <iostream>
#include <thread>
#include "stack.h"
using namespace std;

int main()
{
	Stack s;
		
	auto i = 0, j = 1;
	cout << "Element " << j << ": ";
	while (cin >> i)
	{
		try
		{
			s.Push(i);
		}
		catch (Stack::Exceptions e)
		{
			if (e == Stack::FULLSTACK)
				cout << "A verem megtelt.";
		}
		j++;
		cout << "Element " << j << ": ";
	}
	cout << "\n";

	auto r = s;

	i = 0;
	while (i < 100)
	{
		try
		{
			r.Push(i);
		}
		catch (Stack::Exceptions e)
		{
			if (e == Stack::FULLSTACK)
				cout << "A verem megtelt.";
		}
		++i;
	}
	
	auto functor =
		[](Stack& result, Stack& s) ->void {result = s; };

	Stack q;
	std::thread t(functor, std::ref(q), std::ref(r));

	try
	{
		cout << "First: " << s.Top() << endl;
	}
	catch (Stack::Exceptions e)
	{
		if (e == Stack::EMPTYSTACK)
			cout << "A verem ures!\n";
	}

	while (!s.Empty())
	{
		cout << s.Pop() << endl;
	}
	cout << "\n";

	t.join();

	while (!r.Empty())
	{
		cout << r.Pop() << " ";
	}
	cout << "\n";

	while (!q.Empty())
	{
		cout << q.Pop() << " ";
	}
	cout << "\n";

	return 0;
}