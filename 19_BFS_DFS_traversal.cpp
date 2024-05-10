#include<iostream>
using namespace std;
#include <queue>

class node
{
    int data;
    node *next;
    node(int x)
    {
        this->data=x;
        next=NULL;
    }
    friend class graph;
};

class graph
{
    public:
    int n;
    node **head;

    int set_value()
    {
        cout<< "Enter number of vertices: ";
        cin>>n;
        head=new node*[n];
        return n;
    }

    void create()
    {
        for(int i=1;i<=n;i++)
        {
            head[i]=new node(i);
            node *p=head[i];

            cout<<"Enter number of nodes adjacent to vertex "<<i<<": ";
            int x;
            cin>>x;

            if(x==0)
            {
                head[i]->next=NULL;
            }
            else
            {
                int vertex;
                for(int j=0;j<x;j++)
                {
                    cout<<"Enter vertex "<<(j+1)<<": "<<endl;
                    cin>>vertex;
                    if(vertex>n || vertex<1)
                    {
                        cout<<"Invalid vertex"<<endl;
                        j--;
                    }
                    else
                    {
                        node *temp=new node(vertex);
                        p->next=temp;
                        temp->next=NULL;
                        p=temp;
                    }
                }
            }
        }
    }

    void BFS(int i)
    {
        queue<int> q;
        node *p;

        int visited[n+1];
        for(int j=0;j<=n;j++)
        {
            visited[j]=0;
        }

        q.push(i);
        int x;

        while(!q.empty())
        {
            x=q.front();
            q.pop();

            if(visited[x]==0)
            {
                cout<<x<<" ";
                visited[x]=1;
            }
            p=head[x];
            while(p!=NULL)
            {
                if(visited[p->data]==0)
                {
                    q.push(p->data);
                }
                p=p->next;
            }
        }
    }

    void DFS(int i, int visited[])
    {
        visited[i] = 1;
        cout << i << " ";
        node *temp = head[i]->next;
        while (temp != NULL)
        {
            int t = temp->data;
            if (visited[t] == 0)
            {
                DFS(t, visited);
            }
            temp = temp->next;
        }
    }

};

int main()
{
    graph obj;
    int n=obj.set_value();
    obj.create();

    cout<<"Enter the vertex you want to start the traversals with: ";
    int i;
    cin>>i;
    cout<<"BFS traversal: "<<endl;
    obj.BFS(i);

    cout<<endl;

    cout<<"DFS traversal: "<<endl;
    int visited[n+1];
    for(int j=0;j<=n;j++)
    {
        visited[j]=0;
    }
    obj.DFS(i,visited);
}