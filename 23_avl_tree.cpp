//********DESCENDING??*******



#include <iostream>
using namespace std;

class Node {
	string key;
	string meaning;
	Node *left;
	Node *right;
	int height;
public:
	Node() {
		key = "";
		meaning = "";
		left = NULL;
		right = NULL;
		height = 0;
	}

	Node(string key, string meaning) {
		this->key = key;
		this->meaning = meaning;
		left = right = NULL;
		height = 1;
	}

	friend class AVL;
};

class AVL {
	Node *root;
public:
	AVL() {
		root = NULL;
	}

	void insert(string key, string meaning) {
		this->root = insert(root, key, meaning);
	}

	void printInorder() {
		inorder(root);
	}

    void search(string x)
    {
        cout<<"The number of comparisions are: "<<compare(x);
    }

private:

    int compare(string x)
    {
        Node *p=root;
        if(p->key > x)
        {
            p=p->left;
        }
        else if(p->key < x)
        {
            p=p->right;
        }
        else if(p->key == x)
        {
            int a=max(height(root->left), height(root->right));
            int b=max(height(p->left), height(p->right));
            int comp=a-b;
            return comp;
        }
    }
	int height(Node *node) {
		if (node == NULL) {
			return 0;
		}
		return node->height;
	}

	int getBF(Node *node) {
		if (node == NULL) {
			return 0;
		}
		return height(node->left) - height(node->right);
	}

	int max(int a, int b) {
		return (a > b ? a : b);
	}

	Node* rotateRight(Node *p) {
		Node *pl = p->left;
		Node *plrc = pl->right;

		//rotate
		pl->right = p;
		p->left = plrc;

		//update height
		p->height = max(height(p->left), height(p->right));
		pl->height = max(height(pl->left), height(pl->right));

		return pl;
	}

	Node* rotateLeft(Node *p) {
		Node *pr = p->right;
		Node *prlc = pr->left;

		//rotate
		pr->left = p;
		p->right = prlc;

		//update height

		p->height = max(height(p->left), height(p->right));
		pr->height = max(height(pr->left), height(pr->right));

		return pr;
	}


	//Insert a Node
	Node* insert(Node *node, string key, string meaning) {
		Node *new_node = new Node(key, meaning);

		if (node == NULL) {
			return new_node;
		}

		if (key < node->key) {
			node->left = insert(node->left, key, meaning);
		} else if (key > node->key) {
			node->right = insert(node->right, key, meaning);
		} else {
			return node;
		}

		//update height
		node->height = 1 + max(height(node->left), height(node->right));

		int balance = getBF(node);

		//LL
		if (balance == 2 && getBF(node->left)==1) {
			cout << "LL" << endl;
			return rotateRight(node);
		}

		//LR
		if (balance == 2 && getBF(node->left)==-1) {
			cout << "LR" << endl;
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		//RR
		if (balance == -2 && getBF(node->right)==-1) {
			cout << "RR" << endl;
			return rotateLeft(node);
		}

		//RL
		if (balance == -2 && getBF(node->right)==1) {
			cout << "RL" << endl;
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;

	}

	// Get min value from node
	Node* minValueNode(Node *node) {
		Node *current = node;
		while (current->left != NULL) {
			current = current->left;
		}

		return current;
	}

	//Inorder Traversal
	void inorder(Node *node) {

		if (node != NULL) 
        {

			inorder(node->left);
			cout << node->key << " \t "<<node->meaning <<" - "<< getBF(node)<<endl;
			inorder(node->right);
		}
	}
};

int main() 
{
	AVL avl;

	bool flag = true;
	int ch;
	string key, meaning;
    string x;

	while(flag){
		cout<<"\n======== AVL Dictionary ========="<<endl;
		cout<<"1. Add Words to Dictionary "<<endl;
		cout<<"2. Display Words(Ascending order) "<<endl;
		cout<<"3. Number of comparisions required to search"<<endl;
		cout<<"4. Exit..."<<endl;
		cout<<"\n Enter Your Choice: ";
		cin>>ch;


		switch(ch){
		case 1:
			cout<<"Enter word: ";
			cin>>key;
			cout<<"Enter Meaning: ";
			cin>>meaning;

			avl.insert(key, meaning);
			break;
		case 2:
			cout<<"Words in Ascending Order: "<<endl;
			cout<<"Word\tMeaning\tBF"<<endl;
			avl.printInorder();
			cout<<endl;
			break;
		case 3:
            cout<<"Enter the key to search: ";
            cin>>x;

            avl.search(x);
			break;
		case 4:
			cout<<"ThankYou:)"<<endl;
			flag =false;
			break;
		default:
			cout<<"Invalid Input!!"<<endl;
			break;
		}
	}
}
