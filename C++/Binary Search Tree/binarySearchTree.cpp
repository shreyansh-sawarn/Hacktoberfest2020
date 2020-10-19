#include<iostream>
#include "queueLinkedList.hpp"
#include "stackLinkedList.hpp"

using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root, *newNode, *temp;
struct node *insert(node *, int);

class binarySearchTree
{
	queueLinkedList<node *> q;
	stackLinkedList<node *> s;
    public:
	    int ch, ch1;

		binarySearchTree();

        void options();
		int choice();
		void choiceCalling(int);

		void sub_options_1();
		void sub_choiceCalling(int, int);
		void sub_options_2();
		void sub_options_3();

        void search(int);
		void rec_pre_order(node *);
		void rec_post_order(node *);
		void rec_in_order(node *);
		void itr_pre_order(node *);
		void itr_post_order(node *);
		void itr_in_order(node *);
		void breadth_first_search();
		void mirror_image();
		void nodes_counter();
		void height_counter();
		bool delete_node(node *, int);
		void delete_no_child(node *, node *);
		void delete_one_child(node *, node *);
		void merge_deletion(node *, node *, int);
		void copy_deletion(node *, int);
		void replace_node(node *);
		bool isEmpty();
};

binarySearchTree::binarySearchTree()
{
	root = nullptr;
}

void binarySearchTree::options()
{
	cout << "\n------- MENU -------";
    cout << "\n1. INSERT A NODE"
		<< "\n2. SEARCH A NODE"
		<< "\n3. PREORDER TRAVERSAL"
		<< "\n4. POST ORDER TRAVERSAL"
		<< "\n5. INORDER TRAVERSAL"
		<< "\n6. BREADTH FIRST SEARCH"
		<< "\n7. MIRROR IMAGE"
		<< "\n8. COUNT NODES"
		<< "\n9. COUNT HEIGHT"
		<< "\n10. DELETE NODE"
		<< "\n11. REPLACE NODE"
		<<	"\n0. EXIT";
}

int binarySearchTree::choice()
{
    cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void binarySearchTree::choiceCalling(int ch)
{
	int key;
    switch(ch)
	{
		case 1:
			cout << "\nEnter the data: ";
		    cin >> key;
			root = insert(root, key);
			break;
		case 2:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				cout << "\nEnter the node to be searched: ";
				cin >> key;
				search(key);
			}
			break;
		case 3:
		case 4:
		case 5:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				sub_options_1();
				ch1 = choice();
				sub_choiceCalling(ch1, ch);
			}
			break;
		case 6:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				cout << "\nBreadth First Search Traversal(BFS): ";
				breadth_first_search();
				cout << endl;
			}
			break;
		case 7:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				cout << "\nMirror Image: ";
				mirror_image();
				cout << endl;
			}
			break;
		case 8:
			nodes_counter();
			break;
		case 9:
			height_counter();
			break;
		case 10:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				cout << "\nEnter the node to be deleted: ";
		    	cin >> key;
				temp = root;
				delete_node(temp, key);
			}
			break;
		case 11:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				temp = root;
				replace_node(temp);
			}
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void binarySearchTree::sub_options_1()
{
	cout << "\n------- SUB MENU -------";
    cout << "\n1. RECURSIVE METHOD"
		<< "\n2. ITERATIVE METHOD";
}

void binarySearchTree::sub_choiceCalling(int ch1, int ch)
{
	temp = root;
	if(ch1 == 1 && ch == 3)
	{
		cout << "\nPre Order Recursive: ";
		rec_pre_order(temp);
	}
	else if(ch1 == 1 && ch == 4)
	{
		cout << "\nPost Order Recursive: ";
		rec_post_order(temp);
	}
	else if(ch1 == 1 && ch == 5)
	{
		cout << "\nIn Order Recursive: ";
		rec_in_order(temp);
	}
	else if(ch1 == 2 && ch == 3)
	{
		cout << "\nPre Order Iterative: ";
		itr_pre_order(temp);
	}
	else if(ch1 == 2 && ch == 4)
	{
		cout << "\nPost Order Iterative: ";
		itr_post_order(temp);
	}
	else if(ch1 == 2 && ch == 5)
	{
		cout << "\nIn Order Iterative: ";
		itr_in_order(temp);
	}
	else
	{
		cout << "\n########### WRONG CHOICE... ###########\n";
	}
	cout << endl;
}

void binarySearchTree::sub_options_2()
{
	cout << "\n------- SUB MENU -------";
    cout << "\n1. MERGING METHOD"
		<< "\n2. COPYING METHOD";
}

void binarySearchTree::sub_options_3()
{
	cout << "\n------- SUB MENU -------";
    cout << "\n1. INORDER PREDECESSOR METHOD"
		<< "\n2. INORDER SUCCESSOR METHOD";
}

struct node *insert(node *root, int key)
{
	if(root == nullptr)
	{
		newNode = (struct node *)malloc(sizeof(newNode));
		newNode -> left = newNode -> right = nullptr;
		newNode -> data = key;
		return newNode;
	}
	if(key == root -> data)
		cout << "\n" << key << " is already present in tree!\n";
	if(key < root -> data)
	{
		root -> left = insert(root -> left, key);
	}
	if(key > root -> data)
	{
		root -> right = insert(root -> right, key);
	}
	return root;
}

void binarySearchTree::search(int key)
{
	int i = 1;
	temp = root;
	while(temp != nullptr)
	{
		if(key == temp -> data)
		{
			cout << "\nNode is present in Tree at level " << i << "\n";
			return;
		}
		else if(key < temp -> data)
		{
			temp = temp -> left;
			i++;
		}
		else if(key > temp -> data)
		{
			temp = temp -> right;
			i++;
		}
	}
	cout << "\nNode is absent in Tree.\n";
}

void binarySearchTree::rec_pre_order(node *temp)
{
	if(temp != nullptr)
	{
		cout << temp -> data << " ";
		rec_pre_order(temp -> left);
		rec_pre_order(temp -> right);
	}
}

void binarySearchTree::rec_post_order(node *temp)
{
	if(temp != nullptr)
	{
		rec_post_order(temp -> left);
		rec_post_order(temp -> right);
		cout << temp -> data << " ";
	}
}

void binarySearchTree::rec_in_order(node *temp)
{
	if(temp != nullptr)
	{
		rec_in_order(temp -> left);
		cout << temp -> data << " ";
		rec_in_order(temp -> right);
	}
}

void binarySearchTree::itr_pre_order(node *temp)
{
	while(!s.isEmpty() || temp != nullptr)
	{
		while(temp != nullptr)
		{
			cout << temp -> data << " ";
			if(temp -> right)
				s.push(temp -> right);
			temp = temp -> left;
		}
		if(!s.isEmpty())
		{
			temp = s.peek();
			s.pop();
		}
	}
}

void binarySearchTree::itr_post_order(node *temp)
{
	do
	{
		while(temp)
		{
			if(temp -> right)
				s.push(temp -> right);
			s.push(temp);
			temp = temp -> left;
		}
		temp = s.pop();
		if(!s.isEmpty() && temp -> right == s.peek())
		{
			s.pop();
			s.push(temp);
			temp = temp -> right;
		}
		else
		{
			cout << temp -> data << " ";
			temp = nullptr;
		}
	}while(!s.isEmpty());
}

void binarySearchTree::itr_in_order(node *temp)
{
	while(temp != nullptr || !s.isEmpty())
	{
		while(temp != nullptr)
		{
			s.push(temp);
			temp = temp -> left;
		}
		temp = s.peek();
		s.pop();
		cout << temp -> data << " ";
		temp = temp -> right;
	}
}

void binarySearchTree::breadth_first_search()
{
	q.enqueue(root);
	while(!q.isEmpty())
	{
		temp = q.frontEle();
		cout << temp -> data << " ";
		if(temp -> left != nullptr)
			q.enqueue(temp -> left);
		if(temp -> right != nullptr)
			q.enqueue(temp -> right);
		q.dequeue();
	}
}

void binarySearchTree::mirror_image()
{
	q.enqueue(root);
	while(!q.isEmpty())
	{
		temp = q.frontEle();
		cout << temp -> data << " ";
		if(temp -> right != nullptr)
			q.enqueue(temp -> right);
		if(temp -> left)
			q.enqueue(temp -> left);
		q.dequeue();
	}
}

void binarySearchTree::nodes_counter()
{
	int non_leaf=0, leaf=0;
	q.enqueue(root);
	while(!q.isEmpty())
	{
		temp = q.frontEle();
		if(temp -> left != nullptr || temp -> right != nullptr)
			non_leaf++;
		if(temp -> left == nullptr && temp -> right == nullptr)
			leaf++;
		if(temp -> left != nullptr)
			q.enqueue(temp -> left);
		if(temp -> right != nullptr)
			q.enqueue(temp -> right);
		q.dequeue();
	}
	cout << "\nNon-leaves: " << non_leaf
			 << "\nLeaves: " << leaf
			 << "\nNodes: " << non_leaf+leaf << endl;
}

void binarySearchTree::height_counter()
{
	int size, height=0;
	if(isEmpty())
		true;
	else
	{
		q.enqueue(root);
		while(true)
		{
			size = q.size();
			if(size == 0)
				break;
			while(size > 0)
			{
				temp = q.frontEle();
				if(temp -> left != nullptr)
					q.enqueue(temp -> left);
				if(temp -> right != nullptr)
					q.enqueue(temp -> right);
				q.dequeue();
				size--;
			}
			height++;
		}
	}
	cout << "\nHeight of tree is: " << height << endl;
}

bool binarySearchTree::delete_node(node *temp, int key)
{
	node *parent = temp;
	node *temp1 = temp;
	bool flag = false;
	
	while(temp != nullptr)
	{
		if(key == temp -> data)
		{
			flag = true;
			break;
		}
		parent = temp;
		if(key < temp -> data)
		{
			temp = temp ->left;
		}
		else if(key > temp -> data)
		{
			temp = temp -> right;
		}
	}
	
	if(!flag)
		cout << "\nNode not present in Tree!";
	else
	{
		//Case 1: If the node has no child, i.e., leaf node.
		if((temp -> left == nullptr) && (temp -> right == nullptr))
		{
			delete_no_child(parent, temp);
			cout << "\nSuccessfuly deleted the leaf node " << key;
		}

		//Case 2: If the node has one child.
		else if((temp -> left != nullptr && temp -> right == nullptr) || (temp -> left == nullptr && temp -> right != nullptr))
		{
			delete_one_child(parent, temp);
			cout << "\nSuccessfuly deleted the node " << key;
		}

		//Case 3: If the node has both left and right child.
		else if((temp -> left != nullptr) && (temp -> right != nullptr))
		{
			sub_options_2();
			cout << "\n\nThe node " << key << " has two children.";
			ch1 = choice();
			
			if(ch1 == 1)
				merge_deletion(parent, temp, key);
			else if(ch1 == 2)
				copy_deletion(temp, key);
			else
				cout << "\n########### WRONG CHOICE... ###########\n";
		}
	}
	cout << endl;
	return flag;
}

void binarySearchTree::delete_no_child(node *parent, node *temp)
{
	//If root is to be deleted
	if(parent == temp)
		root = nullptr;
	else if(parent -> left == temp)
		parent -> left = nullptr;
	else if(parent -> right == temp)
		parent -> right = nullptr;
	delete(temp);
}

void binarySearchTree::delete_one_child(node *parent, node *temp)
{
	//If root is to be deleted
	if(parent == temp)
	{
		if(temp -> left != nullptr)
			root = temp -> left;
		else if(temp -> right != nullptr)
			root = temp -> right;
	}
	else if(parent -> left == temp)
	{
		if(temp -> left != nullptr)
			parent -> left = temp -> left;
		else if(temp -> right != nullptr)
			parent -> left = temp -> right;
	}
	else if(parent -> right == temp)
	{
		if(temp -> left != nullptr)
			parent -> right = temp -> left;
		else if(temp -> right != nullptr)
			parent -> right = temp -> right;
	}
	delete(temp);
}

void binarySearchTree::merge_deletion(node *parent, node *temp, int key)
{
	int ch2;
	sub_options_3();
	ch2 = choice();

	node *temp1, *parent1;

	//Inorder Predecessor Method
	if(ch2 == 1)
	{
		temp1 = temp -> left;
		parent1 = temp1;
		while(temp1 -> right != nullptr)
		{
			parent1 = temp1;
			temp1 = temp1 -> right;
		}

		//If root is to be deleted
		if(key == root -> data)
		{
			root = root -> left;
		}
		else if(parent -> left == temp)
		{
			parent -> left = parent1;
		}
		else if(parent -> right == temp)
		{
			parent -> right = parent1;
		}
		temp1 -> right = temp -> right;
		delete(temp);
	}
	
	//Inorder Successor Method
	if(ch2 == 2)
	{
		temp1 = temp -> right;
		parent1 = temp1;
		while(temp1 -> left != nullptr)
		{
			parent1 = temp1;
			temp1 = temp1 -> left;
		}

		//If root is to be deleted
		if(key == root -> data)
		{
			root = root -> right;
		}
		else if(parent -> right == temp)
		{
			parent -> right = parent1;
		}
		else if(parent -> left == temp)
		{
			parent -> left = parent1;
		}
		temp1 -> left = temp -> left;
		delete(temp);
	}
	cout << "\nSuccessfuly deleted the node " << key;
}

void binarySearchTree::copy_deletion(node *temp, int key)
{
	int ch2;
	sub_options_3();
	ch2 = choice();

	node *temp1, *parent;

	//Inorder Predecessor Method
	if(ch2 == 1)
	{
		temp1 = temp -> left;
		parent = temp1;
		while(temp1 -> right != nullptr)
		{
			parent = temp1;
			temp1 = temp1 -> right;
		}
		
		temp -> data = temp1 -> data;
		if(temp1 == parent)
		{
			if(temp1 -> left != nullptr)
				temp -> left = temp1 -> left;
			else if(temp1 -> left == nullptr)
				temp -> left = nullptr;
			delete(temp1);
		}
		else if(temp1 -> left != nullptr && temp1 -> right == nullptr)
		{
			delete_one_child(parent, temp1);
		}
		else if(temp1 -> right == nullptr && temp1 -> left == nullptr)
		{
			delete_no_child(parent, temp1);
		}
	}

	//Inorder Successor Method
	if(ch2 == 2)
	{
		temp1 = temp -> right;
		parent = temp1;
		while(temp1 -> left != nullptr)
		{
			parent = temp1;
			temp1 = temp1 -> left;
		}
		
		temp -> data = temp1 -> data;
		if(temp1 == parent)
		{
			if(temp1 -> right != nullptr)
				temp -> right = temp1 -> right;
			else if(temp1 -> right == nullptr)
				temp -> right = nullptr;
			delete(temp1);
		}
		else if(temp1 -> right != nullptr && temp1 -> left == nullptr)
		{
			delete_one_child(parent, temp1);
		}
		else if(temp1 -> right == nullptr && temp1 -> left == nullptr)
		{
			delete_no_child(parent, temp1);
		}
	}
	cout << "\nSuccessfuly deleted the node " << key;
}

void binarySearchTree::replace_node(node *temp)
{
	int key, key1;
	cout << "\nEnter the node to be replaced: ";
	cin >> key;
	bool flag = delete_node(temp, key);
	if(flag)
	{
		cout << "\nEnter the node to be replaced with: ";
		cin >> key1;
		root = insert(root, key1);
		cout << "\nSuccessfully replaced " << key << " with " << key1 << endl;
	}
}

bool binarySearchTree::isEmpty()
{
	if(root == nullptr)
		return true;
	return false;
}

int main()
{
    int choice;
	binarySearchTree ob;
	do
	{
		cout << "\n=========== BINARY SEARCH TREE ===========\n";
		ob.options();
		choice = ob.choice();
		if(ob.ch == 0)
			break;
		system("clear");
		cout << "\n=========== BINARY SEARCH TREE ===========\n";
		ob.choiceCalling(choice);
		cout << "\nPress Enter to continue...";
		cin.ignore();
		getchar();
		system("clear");
	}while(1);
	
	return 0;
}