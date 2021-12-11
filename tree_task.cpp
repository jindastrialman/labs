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

		array[index] = current->data;
		index++;

		insert_to_string_array(current->left, array);
		insert_to_string_array(current->right, array);
	}
	int get_size(){return size;}

};

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	int count = 0;
	BinaryTree *tree;

	cout << "Введите колличество слов: ";
	cin >> count;
	
	cout << "Введите слова " << endl;
	for(int i = 0; i < count; i++)
	{
		string word;
		cin >> word;

		if(i == 0)	tree = new BinaryTree(word);
		else 		tree->add_element(word);
	}

	string * array = tree->tree_to_string_array();
	cout << "Элементы получившегося массива: ";
	for(int i = 0; i < tree->get_size(); i++)
		cout << array[i] << ' ';
	cout << endl;
}
