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
    void insertUtil(Node*& root, int val);                 // Helps to encapsulate the implementation details.
    void preorderRecursive(Node* root);                    // These private functions encapsulate algorithms for tree operations(Abstraction)
    void inorderNonRecursive(Node* root);
    void postorderNonRecursive(Node* root);
    int countLeaves(Node* root);
    int countInternalNodes(Node* root);

public:
    BinaryTree() : root(nullptr) {}
    void insert(int val);
    void constructTree();
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();
    int countLeaves();
    int countInternalNodes();
};

// Function to insert a value into the binary tree
void BinaryTree::insert(int val) {
    insertUtil(root, val);
}

// Utility function to recursively insert a value into the binary tree
void BinaryTree::insertUtil(Node*& root, int val) {
    if (root == nullptr) {
        root = new Node(val);                               //If tree empty, inserts node
        return;
    }

    if (root->left == nullptr)                             //If left empty, inserts left
        insertUtil(root->left, val);
    else if (root->right == nullptr)                       // If right empty, inserts right
        insertUtil(root->right, val);
    else {
        // This is a simplistic approach, without any balancing
        // You may choose to implement more advanced methods for insertion
        insertUtil(root->left, val);                      // If both filled, inserts left
    }
}

// Function to construct the binary tree by taking inputs from the user
void BinaryTree::constructTree() {
    int val;
    char choice;                                            // Construction of tree
    do {
        cout << "Enter value to insert: ";
        cin >> val;
        insert(val);
        cout << "Do you want to insert another value? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

// Function to perform preorder traversal (recursive)
void BinaryTree::preorderTraversal() {
    cout << "Preorder Traversal (recursive): ";
    preorderRecursive(root);
    cout << endl;
}

// Recursive function to perform preorder traversal
void BinaryTree::preorderRecursive(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

// Function to perform inorder traversal (non-recursive)
void BinaryTree::inorderTraversal() {
    cout << "Inorder Traversal (non-recursive): ";
    inorderNonRecursive(root);
    cout << endl;
}

// Function to perform inorder traversal without recursion
void BinaryTree::inorderNonRecursive(Node* root) {
    stack<Node*> s;                                        //Creates a stack to keep track of nodes during traversal.
    Node* curr = root;                                   // Initializes a pointer curr to the root of the tree.

    while (curr != nullptr || !s.empty()) {          // Loops till  curr becomes nullptr and the stack is empty, indicating all nodes have been processed
        while (curr != nullptr) {               //Pushes all the left children of the current node onto the stack until there are no more left children
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();            //Retrieves the top node from the stack.
        s.pop();                    //Removes the top node from the stack.
        cout << curr->data << " ";    //Outputs the data of the current node.
        curr = curr->right;           //Moves curr to the right child of the current node.

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
    if (root == nullptr) return;       //Checks if the current node is nullptr, indicating an empty subtree, and returns from the function if so

    stack<Node*> s1, s2;     //Creates two stacks, s1 and s2
    s1.push(root);           //Pushes the root node onto s1.
 
    while (!s1.empty()) {        //Loops until s1 becomes empty, indicating that all nodes have been processed
        Node* curr = s1.top();    //Retrieves the top node from s1.
        s1.pop();                 //Removes the top node from s1.
        s2.push(curr);         //Pushes the current node onto s2

        if (curr->left) s1.push(curr->left);    //Pushes the left child of the current node onto s1, if it exists.
        if (curr->right) s1.push(curr->right);   //Pushes the right child of the current node onto s1, if it exists.
    }

    while (!s2.empty()) {                    //Loops until s2 becomes empty, indicating that all nodes have been processed.
        cout << s2.top()->data << " ";    //Outputs the data of the top node from s2
        s2.pop();                         //Removes the top node from s2.
    }
}

// Function to count the number of leaves in the binary tree
int BinaryTree::countLeaves() {
    return countLeaves(root);
}

// Recursive function to count the number of leaves in the binary tree
int BinaryTree::countLeaves(Node* root) {
    if (root == nullptr) return 0;                    //Checks if the current node is nullptr, indicating an empty subtree, and returns 0 if so.
    if (root->left == nullptr && root->right == nullptr) return 1; //Checks if current node is leaf node (left&right children nullptr) and returns 1 if so.
    return countLeaves(root->left) + countLeaves(root->right); //Recursively calculates the no. of leaves in the left and right subtree, and returns sum.
}

// Function to count the number of internal nodes in the binary tree
int BinaryTree::countInternalNodes() {
    return countInternalNodes(root);
}

// Recursive function to count the number of internal nodes in the binary tree
int BinaryTree::countInternalNodes(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0; //Checks if current node is nullptr or leaf node,returns 0 if so.
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);  //Recursively calculates the number of internal nodes in the left subtree // and the number of internal nodes in the right subtree, adds 1 for the current node, and returns their sum.
}

int main() {
    BinaryTree tree;

    // Construct the binary tree
    tree.constructTree();

    int choice;
    do {
        cout << "\nBinary Tree Operations:" << endl;
        cout << "1. Preorder Traversal" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Postorder Traversal" << endl;
        cout << "4. Count Number of Leaves" << endl;
        cout << "5. Count Number of Internal Nodes" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.preorderTraversal();
                break;
            case 2:
                tree.inorderTraversal();
                break;
            case 3:
                tree.postorderTraversal();
                break;
            case 4:
                cout << "Number of Leaves: " << tree.countLeaves() << endl;
                break;
            case 5:
                cout << "Number of Internal Nodes: " << tree.countInternalNodes() << endl;
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
