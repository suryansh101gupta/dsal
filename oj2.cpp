#include <iostream>
#include <stack>

using namespace std;

// Node structure for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

    // Private helper functions
    void insertUtil(Node*& root, int val);
    void postorderRecursive(Node* root);
    void inorderNonRecursive(Node* root);
    void preorderNonRecursive(Node* root);
    int heightUtil(Node* root);

public:
    BinaryTree() : root(nullptr) {}
    void insert(int val);
    void postorderTraversal();
    void inorderTraversal();
    void preorderTraversal();
    int height();
};

// Function to insert a value into the binary tree
void BinaryTree::insert(int val) {
    insertUtil(root, val);
}

// Utility function to recursively insert a value into the binary tree
void BinaryTree::insertUtil(Node*& root, int val) {
    if (root == nullptr) {
        root = new Node(val);
        return;
    }

    // This part is different from BST insertion, it just inserts at first available position
    if (root->left == nullptr)
        insertUtil(root->left, val);
    else if (root->right == nullptr)
        insertUtil(root->right, val);
    else {
        // If both left and right children exist, insert to left child
        insertUtil(root->left, val);
    }
}

// Function to perform postorder traversal (recursive)
void BinaryTree::postorderTraversal() {
    cout << "Postorder Traversal (recursive): ";
    postorderRecursive(root);
    cout << endl;
}

// Recursive function to perform postorder traversal
void BinaryTree::postorderRecursive(Node* root) {
    if (root == nullptr) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}

// Function to perform inorder traversal (non-recursive)
void BinaryTree::inorderTraversal() {
    cout << "Inorder Traversal (non-recursive): ";
    inorderNonRecursive(root);
    cout << endl;
}

// Function to perform inorder traversal without recursion
void BinaryTree::inorderNonRecursive(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Function to perform preorder traversal (non-recursive)
void BinaryTree::preorderTraversal() {
    cout << "Preorder Traversal (non-recursive): ";
    preorderNonRecursive(root);
    cout << endl;
}

// Function to perform preorder traversal without recursion
void BinaryTree::preorderNonRecursive(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s;
    s.push(root);       //pushes the root node onto the stack

    while (!s.empty()) { 
        Node* curr = s.top();  //retrieves the top element (node) of the stack s and assigns it to a pointer called curr
        s.pop();                 //removes the top element (node) from the stack s
        cout << curr->data << " "; //prints the data stored in the current node (curr) 

        if (curr->right) s.push(curr->right);  //checks if the current node has a right child, if yes, right child pushed onto stack.
        if (curr->left) s.push(curr->left);
    }
}

// Function to calculate the height of the binary tree
int BinaryTree::height() {
    return heightUtil(root);
}

// Utility function to calculate the height of the binary tree
int BinaryTree::heightUtil(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = heightUtil(root->left);
    int rightHeight = heightUtil(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    BinaryTree tree;

    int choice, val;
    do {
        cout << "\nBinary Tree Operations:" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Postorder Traversal (recursive)" << endl;
        cout << "3. Inorder Traversal (non-recursive)" << endl;
        cout << "4. Preorder Traversal (non-recursive)" << endl;
        cout << "5. Find Height of Tree" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                tree.postorderTraversal();
                break;
            case 3:
                tree.inorderTraversal();
                break;
            case 4:
                tree.preorderTraversal();
                break;
            case 5:
                cout << "Height of the Tree: " << tree.height() << endl;
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
