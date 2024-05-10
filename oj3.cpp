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
    void inorderRecursive(Node* root);
    void preorderNonRecursive(Node* root);
    void postorderNonRecursive(Node* root);
    void mirrorUtil(Node* root);

public:
    BinaryTree() : root(nullptr) {}
    void insert(int val);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void mirror();
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

    // Inserting at the first available position
    if (root->left == nullptr)
        insertUtil(root->left, val);
    else if (root->right == nullptr)
        insertUtil(root->right, val);
    else {
        // If both left and right children exist, insert to left child
        insertUtil(root->left, val);
    }
}

// Function to perform inorder traversal (recursive)
void BinaryTree::inorderTraversal() {
    cout << "Inorder Traversal (recursive): ";
    inorderRecursive(root);
    cout << endl;
}

// Recursive function to perform inorder traversal
void BinaryTree::inorderRecursive(Node* root) {
    if (root == nullptr) return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
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
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

// Function to perform postorder traversal (non-recursive)
void BinaryTree::postorderTraversal() {
    cout << "Postorder Traversal (non-recursive): ";
    postorderNonRecursive(root);
    cout << endl;
}

// Function to perform postorder traversal without recursion
void BinaryTree::postorderNonRecursive(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Function to find the mirror image of the tree
void BinaryTree::mirror() {
    mirrorUtil(root);
}

// Utility function to find the mirror image of the tree
void BinaryTree::mirrorUtil(Node* root) {
    if (root == nullptr) return;
    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorUtil(root->left);
    mirrorUtil(root->right);
}

int main() {
    BinaryTree tree;

    int choice, val;
    do {
        cout << "\nBinary Tree Operations:" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Inorder Traversal (recursive)" << endl;
        cout << "3. Preorder Traversal (non-recursive)" << endl;
        cout << "4. Postorder Traversal (non-recursive)" << endl;
        cout << "5. Find Mirror Image of Tree" << endl;
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
                tree.inorderTraversal();
                break;
            case 3:
                tree.preorderTraversal();
                break;
            case 4:
                tree.postorderTraversal();
                break;
            case 5:
                tree.mirror();
                cout << "Mirror image of the tree obtained." << endl;
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
