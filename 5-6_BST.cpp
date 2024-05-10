#include <iostream>
#include <string>
#include<stack>
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

    BST() 
    {
        root = NULL;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node* getRoot() {
        return root;
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

    //for descending take element in array instead of printing and then print array in reverse fashion
    void ascending_non_recursive(Node *p)
    {
        stack<Node *> stk;
        Node *curr=p;
        while(curr!=NULL || !stk.empty())
        {
            if(curr!=NULL)
            {
                stk.push(curr);
                curr=curr->lchild;
            }
            else
            {
                curr=stk.top();
                stk.pop();
                cout<<curr->data<<" ";
                curr=curr->rchild;
            }
        }
    }

    void descending_non_recursive(Node *p)
    {
        stack<Node *> stk;
        Node *curr=p;
        while(curr!=NULL || !stk.empty())
        {
            if(curr!=NULL)
            {
                stk.push(curr);
                curr=curr->rchild;
            }
            else
            {
                curr=stk.top();
                stk.pop();
                cout<<curr->data<<" ";
                curr=curr->lchild;
            }
        }
    }

    Node * delete_element(Node *root,int key)
    {
        Node *p=root;

        if(p==NULL)
        {
            return NULL;
        }

        if(p->lchild==NULL && p->rchild==NULL)
        {
            if(p==root)
            {
                root=NULL;
            }
            delete p;
            return NULL;
        }

        if(key<p->data)
        {
            p->lchild=delete_element(p->lchild,key);
        }
        else if(key>p->data)
        {
            p->rchild=delete_element(p->rchild,key);
        }
        else  //element found
        {         
            Node *q;
            //if height of lchild of p is greater than rchild then we delete from the left subtree
            if(height(p->lchild) > height(p->rchild))
            {
                q=InPre(p->lchild);
                p->data=q->data;
                p->lchild=delete_element(p->lchild,q->data);
            }
            else
            {
                q=InSucc(p->rchild);
                p->data=q->data;
                p->rchild=delete_element(p->rchild,q->data);
            }
        }
        return p;
    }

    int height(Node *p)
    {
        int x,y;
        if(p==NULL)
        {
            return 0;
        }
        x=height(p->lchild);
        y=height(p->rchild);
        return x>y?x+1:y+1;
    }

    Node *InPre(Node *p)
    {
        while(p && p->rchild!=NULL)
        {
            p=p->rchild;
        }
        return p;
    }

    Node *InSucc(Node *p)
    {
        while(p && p->lchild!=NULL)
        {
            p=p->lchild;
        }
        return p;
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
    
    void search(int key,Node *p)
    {
        int flag=0;
        int comparisions=0;
        while(p!=NULL)
        {
            if(key==p->data)
            {
                flag=1;
                break;
            }
            else if(key < p->data)
            {
                p=p->lchild;
                comparisions+=1;
            }
            else if(key > p->data)
            {
                p=p->rchild;
                comparisions+=1;
            }
        }
        if(flag==1)
        {
            cout<<"Element found."<<endl;
            cout<<"The number of comparisions are: "<<comparisions<<endl;
        }
        else
        {
            cout<<"Element not found."<<endl;
        }
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
        cout<<"2.Diplay in ascending order: "<<endl;
        cout<<"3.Delete element"<<endl;
        cout<<"4.Display largest ans smallest element"<<endl;
        cout<<"5.Comparisions required for searching an element"<<endl;
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
            obj.ascending_non_recursive(obj.getRoot());
            cout<<endl;
            break;

            case 3:
            int a;
            cout<<"Enter element to delete: ";
            cin>>a;
            obj.delete_element(obj.getRoot(),a);
            cout<<"Deleted successfully!!!"<<endl;
            break;

            case 4:
            obj.largest(obj.getRoot());
            obj.smallest(obj.getRoot());
            cout<<endl;
            break;

            case 5:
            int b;
            cout<<"Enter element to search: ";
            cin>>b;
            obj.search(b,obj.getRoot());
            break;

            case 6:
            c=6;
            cout<<"Thankyou!!!"<<endl;
            break;

            case 7:
            c=7;
            obj.descending_non_recursive(obj.getRoot());
            cout<<endl;
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
