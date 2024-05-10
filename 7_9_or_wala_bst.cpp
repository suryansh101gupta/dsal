#include <iostream>
#include <string>
#include<queue>
using namespace std;

class Node {
public:
    Node *lchild;
    Node *rchild;
    int data;

    Node(int data) {
        this->data = data;
        lchild = NULL;
        rchild = NULL;
    }
};

class BST 
{
public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node* insert(Node *node, int key) 
    {
        if (node == NULL) 
        {
            Node *temp=new Node(key);
            return temp;
        }

        if (key < node->data)
        {
            node->lchild = insert(node->lchild, key);
        } 
        else if (key > node->data)
        {
            node->rchild = insert(node->rchild, key);
        }

        return node;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    // level_order Traversal
    void level_order(Node *root)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node *temp=q.front();
                q.pop();

                if(temp->lchild!=NULL)
                {
                    q.push(temp->lchild);
                }
                if(temp->rchild!=NULL)
                {
                    q.push(temp->rchild);
                }
                cout<<temp->data<<" ";
            }
        }
    }

    Node* getRoot() {
        return root;
    }

    void largest(Node *root)
    {
        Node *p=root;
        while(p->rchild!=NULL)
        {
            p=p->rchild;
        }
        cout<<"Largest element is: "<<p->data<<endl;
    }

    void smallest(Node *root)
    {
        Node *p=root;
        while(p->lchild!=NULL)
        {
            p=p->lchild;
        }
        cout<<"Smallest element is: "<<p->data<<endl;
    }

    int longestPathLength(Node* node) 
    {
        if (node == NULL)
            return 0;
        int leftDepth = longestPathLength(node->lchild);
        int rightDepth = longestPathLength(node->rchild);
        return 1 + max(leftDepth, rightDepth);
    }

    void swapNodes(Node *node) 
    {
		if (!node) {
			return;
		}
		Node *temp = node->lchild;
		node->lchild = node->rchild;
		node->rchild = temp;
		swapNodes(node->lchild);
		swapNodes(node->rchild);
	}

    void inorder(Node *p) 
    {
        if (p == NULL) {
            return;
        }
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
};

int main() 
{
    BST obj;

    int c=1;
    int choice;
    char ans;
    int element;
    while(c!=6)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Insert in BST"<<endl;
        cout<<"2.Level order traversal"<<endl;
        cout<<"3.Minimum and maximum data value in the tree"<<endl;
        cout<<"4.Swap pointers at every node"<<endl;
        cout<<"5.Longest path length"<<endl;
        cout<<"6.EXIT"<<endl;
        cout<<"Enter your choice:";
        cin>>choice; 
        switch(choice)
        {
            case 1:
            do
            {
                cout<<"Enter element: ";
                cin>>element;
                obj.insert(element);
                cout<<"Want to coutniue entering?(y/n): ";
                cin>>ans;
            } while (ans=='y' || ans=='Y');
            break;

            case 2:
            obj.level_order(obj.getRoot());
            break;

            case 3:
            obj.largest(obj.getRoot());
            obj.smallest(obj.getRoot());
            break;

            case 4:
            obj.swapNodes(obj.getRoot());
            cout<<"Inorder after swapping: "<<endl;
            obj.inorder(obj.getRoot());
            cout<<endl;
            break;

            case 5:
            cout << "Number of nodes in the longest path: " << obj.longestPathLength(obj.getRoot()) << endl;
            break;

            case 6:
            c=6;
            cout<<"Thankyou!!!"<<endl;
            break;
        }
    }
    // obj.insert("C");
    // obj.insert("B");
    // obj.insert("A");
    // obj.insert("D");
    // obj.insert("Z");
    // obj.insert("M");
}
