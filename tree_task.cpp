#include <iostream>
#include <string>

class BinaryTree
{
private:
	struct TreeElement
	{
		std::string data;
		TreeElement* left;
		TreeElement* right;
		TreeElement(std::string element)
		{
			data = element;
			left = NULL;
			right = NULL;
		}
	};

	TreeElement *head;
	int size, index;
public:
	BinaryTree(std::string element)
	{
		head = new TreeElement(element);
		size = 1;
	}

	void add_element(std::string element)
	{
		auto cur = head;
		auto prev = head;
		while(cur != NULL)
		{
			int compare_result = cur->data.compare(element);
			prev = cur;

			if(compare_result == 0)
				return;
			if(compare_result > 0)
				cur = cur->left;
			if(compare_result < 0)
				cur = cur->right;
		}
		//std::cout << prev->data << ' ' << element << ' ' << prev->data.compare(element) << std::endl;

		if(prev->data.compare(element) > 0)
			prev->left = new TreeElement(element);
		else
			prev->right = new TreeElement(element);
		size++;
			
	}
	std::string *tree_to_string_array()
	{
		std::string *result = new std::string[size];
		index = 0;
		insert_to_string_array(head, result);
		return result;
	}

	void insert_to_string_array(TreeElement *current, std::string *array)
	{
		if(current == NULL)
			return;

		//std::cout << current->data << ' ' << index << std::endl;
		array[index] = current->data;
		index++;

		insert_to_string_array(current->left, array);
		insert_to_string_array(current->right, array);
	}

};

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	BinaryTree *tree = new BinaryTree("ab");
	tree->add_element("a");
	tree->add_element("b");
	tree->add_element("c");
	tree->add_element("aa");
	tree->add_element("ac");
	tree->add_element("ac");
	tree->add_element("ad");
	tree->add_element("af");
	tree->add_element("f");
	string * array = tree->tree_to_string_array();;
	for(int i = 0; i < 9; i++)
		cout << array[i] << ' ';
}
