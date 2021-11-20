#include <iostream>

class Stack{
protected:
	struct ListElement
	{
		float data;
		ListElement *next;
	};
	ListElement* _head;
	int _size;
public:
	Stack()
	{
		_head = NULL;
		_size = 0;
	}

	void push(float element)
	{
		_size++;
		if(_head == NULL)
		{
			_head = new ListElement();
			_head->next = NULL;
			_head->data = element;
		}
		else
		{
			ListElement* buff = new ListElement();
			buff->next = _head;
			buff->data = element;
			_head = buff;
		}
	}
	
	float pop()
	{
		if(_size == 0)
		{
			return -10;
		}
		else
		{
			_size--;
			float num = _head->data;
			_head = _head->next;
			return num;
		}
		
	}
	
	int get_size(){return _size;}
	
	

	friend std::ostream& operator<<(std::ostream& os, const Stack& stack)
	{
		ListElement* buff = stack._head;
		while(buff != NULL)
		{
			os << buff->data << ' ';
			buff = buff->next;
		}
		return os;
	}
};

Stack* StackCombine(Stack first, Stack second)
{
	Stack* result = new Stack();
	while(first.get_size() != 0 && second.get_size() != 0)
	{
		float buf1 = first.pop();
		float buf2 = second.pop();
		
		(*result).push(buf1 * buf1);
		(*result).push(buf2 * buf2);
	}
	while(first.get_size() != 0)
		(*result).push(first.pop() * first.pop());
	while(second.get_size() != 0)
		(*result).push(second.pop() * second.pop());
	return result;
}

int main()
{
	Stack stack1 = Stack();
	stack1.push(3);
	stack1.push(5);
	stack1.push(4);
	
	Stack stack2 = Stack();
	stack2.push(10);
	stack2.push(20);
	stack2.push(30);
	
	Stack* merged = StackCombine(stack1, stack2);
	
	std::cout << stack1 << stack2 << *merged << std::endl;
}
