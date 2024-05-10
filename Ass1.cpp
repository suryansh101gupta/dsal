#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    friend class BinaryTree;
};
class BinaryTree
{
public:
    Node *root = NULL;
    Node *temp = root;
    void buildTree()
    {
        cout << "Enter the data to be inserted" << endl;
        int d;
        cin >> d;
        Node *new_node = new Node(d);
        Node *temp = root;
        if (root == NULL)
        {
            root = new_node;
            return;
        }
        while (temp->left != NULL || temp->right != NULL)
        {
            cout << "Enter 1 for left of " << temp->data << endl;
            cout << "Enter 2 for right of " << temp->data << endl;
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                if (temp->left == NULL)
                {
                    temp->left = new_node;
                    return;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new_node;
                    return;
                }
                temp = temp->right;
            }
        }
        cout << "Enter 1 to left of " << temp->data << endl;
        cout << "Enter 2 to right of " << temp->data << endl;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            temp->left = new_node;
        }
        else
        {
            temp->right = new_node;
        }
    }
    void levelOrderTraversal()
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
    int maxheightItr()
    {
        int cnt = 0;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cnt++;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return cnt;
    }
    int maxheight(Node *root)
    {
        int lheight = 0;
        int rheight = 0;
        if (root == NULL)
        {
            return 0;
        }
        lheight = maxheight(root->left);
        rheight = maxheight(root->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return rheight + 1;
        }
    }
    void inorderItr()
    {
        stack<Node *> st;
        Node *temp = root;
        while (temp != NULL or !st.empty())
        {
            while (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    void preorderItr()
    {
        if (root == NULL)
            return;
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *temp = s.top();
            cout << temp->data << " ";
            s.pop();
            if (temp->right != NULL)
                s.push(temp->right);
            if (temp->left != NULL)
                s.push(temp->left);
        }
    }
    void postorderItr()
    {
        if (root == NULL)
            return;
        stack<Node *> s1, s2;
        Node *temp = root;
        s1.push(root);
        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left != NULL)
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
        }
        while (!s2.empty())
        {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }
    int leafcount(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return leafcount(root->left) + leafcount(root->right);
        }
    }
    int leafcountItr()
    {
        int cnt = 0;
        stack<Node *> st;
        Node *temp = root;
        while (temp != NULL or !st.empty())
        {
            while (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            if (temp->left == NULL and temp->right == NULL)
            {
                cnt++;
            }
            temp = temp->right;
        }
        return cnt;
    }
    int internalNode(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return 0;
        }
        return 1 + internalNode(root->left) + internalNode(root->right);
    }
    int internalNodeItr()
    {
        queue<Node *> q;
        queue<Node *> res;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            bool isInternal = 0;
            if (temp->left)
            {
                isInternal = 1;
                q.push(temp->left);
            }
            if (temp->right)
            {
                isInternal = 1;
                q.push(temp->right);
            }
            if (isInternal)
            {
                res.push(temp);
            }
        }
        return res.size();
    }
    void swapLeftRight(Node *root)
    {

        if (!root)
        {
            return;
        }
        Node *x = root->left;
        root->left = root->right;
        root->right = x;
        swapLeftRight(root->left);
        swapLeftRight(root->right);
    }
    void swapLeftRightItr(Node *root)
    {
        stack<Node *> s;
        Node *temp = root;
        while (temp != NULL || !s.empty())
        {
            while (temp != NULL)
            {
                s.push(temp);
                Node *x = root->left;
                root->left = root->right;
                root->right = x;
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
    }
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    Node *copyTree(Node *root)
    {
        if (!root)
            return NULL;
        Node *newnode = new Node(root->data);
        newnode->left = copyTree(root->left);
        newnode->right = copyTree(root->right);
        return newnode;
    }
    Node *copyTreeIter(Node *root)
    {
        if (root == NULL)
            return NULL;
        stack<Node *> s;
        s.push(root);
        Node *newnode = NULL;
        while (!s.empty())
        {
            Node *curr = s.top();
            s.pop();

            newnode = new Node(root->data);
            newnode->left = root->left;
            newnode->right = root->right;

            if (curr->right)
                s.push(curr->right);
            if (curr->left)
                s.push(curr->left);
        }
        return newnode;
    }
    void deleteNodes(Node *root)
    {
        if (!root)
            return;
        deleteNodes(root->left);
        deleteNodes(root->right);
        delete root;
    }
    void deleteNodesIter(Node *root)
    {
        stack<Node *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            Node *curr = s1.top();
            s1.pop();
            s2.push(curr);
            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
        while (!s2.empty())
        {
            Node *x = s2.top();
            s2.pop();
            delete x;
        }
    }
};
int main()
{
    BinaryTree B;
    while (true)
    {
        cout << "Enter 1 for insertion " << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            B.buildTree();
        }
        else
        {
            cout << "Leaf count Itr is: " << endl;
            cout << "Level order Traversal is: " << endl;
            B.levelOrderTraversal();
            cout << "Inorder Traversal is: " << endl;
            B.inorder(B.root);
            cout << endl;
            cout << "Inorder Traversal Itrative is: " << endl;
            B.inorderItr();
            cout << endl;
            cout << "Preorder Traversal is: " << endl;
            B.preorder(B.root);
            cout << endl;
            cout << "Preorder Traversal Itrative is: " << endl;
            B.preorderItr();
            cout << endl;
            cout << "Postorder is: " << endl;
            B.postorder(B.root);
            cout << "Postorder Traversal Itrative is: " << endl;
            B.postorderItr();
            cout << endl;
            cout << "Maximum height of the tree is : " << endl;
            cout << B.maxheight(B.root) << endl;
            cout << endl;
            cout << "Maximum height by Iteration is : " << endl;
            cout << B.maxheightItr() << endl;
            cout << endl;
            cout << "Leaf count is : " << endl;
            cout << B.leafcount(B.root) << endl;
            cout << endl;
            cout << "Leaf count Itr is: " << endl;
            cout << B.leafcountItr() << endl;
            cout << endl;
            cout << "Internal Roots recursive : " << endl;
            cout << B.internalNode(B.root);
            cout << endl;
            cout << "Internal Roots Iterative : " << endl;
            cout << B.internalNodeItr();
            cout << endl;
            cout << "Swapping recusriverly : " << endl;
            B.swapLeftRight(B.root);
            B.levelOrderTraversal();
            cout << endl;
            cout << "Swapping Iterative : " << endl;
            B.swapLeftRightItr(B.root);
            B.levelOrderTraversal();
            cout << endl;
            cout << "Delete all nodes Iterative: " << endl;
            B.deleteNodesIter(B.root);
            cout << endl;
        }
    }
    return 0;
}
