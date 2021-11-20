#include <iostream>

class LinkedList{
protected:
	struct ListElement
	{
		int data;
		ListElement *next;
	};
	ListElement* _head;
	int _size;
public:
	LinkedList()
	{
		_head = NULL;
		_size = 0;
	}

	void AddElement(int element)
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
	void InsertElement(int element, int position)
	{
		if(position > _size)
			return;

		ListElement* buff = _head, *nbuff;

		for(int i = 0; i < position - 1; i++)
			buff = buff->next;
		nbuff = buff->next;
		buff->next = new ListElement();
		buff->next->data = element;
		buff->next->next = nbuff;
	}
	void InsertSort()
	{
		ListElement* a, *b, *p, *h = NULL;

    		for(ListElement* i = _head; i != NULL; ) 
		{
        		a = i;
        		i = i->next;
        		b = h;
        		for(p = NULL; (b != NULL) && (a->data < b->data); ) 
			{
            			p = b;
            			b = b->next;
        		}

        		if(p == NULL)
			{
            			a->next = h;
				h = a;
			}
		       	else 
			{
				a->next = b;
				p->next = a;
			}
		}
		if(h != NULL)
			_head = h;
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList& list)
	{
		ListElement* buff = list._head;
		while(buff != NULL)
		{
			os << buff->data << ' ';
			buff = buff->next;
		}
		return os;
	}
};

int main()
{
	LinkedList list = LinkedList();
	list.AddElement(3);
	list.AddElement(5);
	list.AddElement(4);
	std::cout << list << std::endl;
	list.InsertSort();
	std::cout << list << std::endl;
}
