#include <iostream>
#include <stack>
using namespace std;

using namespace std;
class TreeNode 
{
    public:
    char data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(char data)
{
    TreeNode* newNode = new TreeNode;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

TreeNode* constructExpressionTree(string prefix) 
{
    stack<TreeNode*> s;
    for (int i = prefix.size() - 1; i >= 0; i--) 
    {
        char c = prefix[i];
        TreeNode* newNode = createNode(c);
        if (!isOperator(c))
        {
            s.push(newNode);
        }
        else 
        {
            newNode->left = s.top();
            s.pop();
            newNode->right = s.top();
            s.pop();
            s.push(newNode);
        }
    }
    return s.top();
}

// }*+a-bc+d*ef

void postorderTraversal(TreeNode* root)
{
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;

    TreeNode* current = root;
    stk1.push(current);

    while(!stk1.empty())
    {
        current=stk1.top();
        stk1.pop();
        stk2.push(current);

        if(current->left!=NULL)
        {
            stk1.push(current->left);
        }
        if(current->right!=NULL)
        {
            stk1.push(current->right);
        }
    }

    while(!stk2.empty())
    {
        current=stk2.top();
        cout<<current->data<<" ";
        stk2.pop();
    }
    
}

void countOperandsOperators(TreeNode* root, int& operandCount, int& operatorCount)
{
    if (root)
    {
        if (isOperator(root->data)) 
        {
            operatorCount++;
        }
        else 
        {
            operandCount++;
        }
        countOperandsOperators(root->left, operandCount, operatorCount);
        countOperandsOperators(root->right, operandCount, operatorCount);
    }
}

int main() 
{
    TreeNode* root;
    string prefixExpression;
    int operandCount = 0, operatorCount = 0;

    int c=1;
    int choice;
    while(c!=4)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Enter the prefix expression"<<endl;
        cout<<"2.Postorder traversal"<<endl;
        cout<<"3.Display number of operands and operators"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cin>>prefixExpression;
            root = constructExpressionTree(prefixExpression);
            break;

            case 2:
            cout << "Non-recursive Postorder Traversal: ";
            postorderTraversal(root);
            cout << endl;
            break;

            case 3:
            countOperandsOperators(root, operandCount, operatorCount);
            cout << "Operand Count: " << operandCount << endl;
            cout << "Operator Count: " << operatorCount << endl;
            break;

            case 4:
            cout<<"Thank you!!!"<<endl;
            c=4;
            break;
        }

        
    }
    return 0;
}