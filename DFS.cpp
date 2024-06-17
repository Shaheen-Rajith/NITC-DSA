#include <iostream>
#include <list>
using namespace std;

class Graph
{
    private:
    int numVertices;
    list<int>* AdjList;
    public:
    Graph(int vert)
    {
        numVertices = vert;
        AdjList = new list<int>[vert];
    }

    void AddEdge(int src , int dest)
    {
        AdjList[src].push_back(dest);
        AdjList[dest].push_back(src);
    }

    void DFS(int start)
    {
        bool visited[numVertices];
        for(int i=0; i<numVertices; i++)
            visited[i]=false;
        list<int> stk;
        list<int>::iterator i;
        visited[start]=true;
        stk.push_back(start);
        cout<<"\nDFS starting from Node "<<start<<": ";
        while(!stk.empty())
        {
            int curr = stk.back();
            cout<<curr <<",";
            stk.pop_back();
            for(i = AdjList[curr].begin() ; i != AdjList[curr].end() ; i++)
            {
                int vertex = *i;
                if(!visited[vertex])
                {
                    visited[vertex]=true;
                    stk.push_back(vertex);
                }
            }
        }
        cout<<"\n\n";
    }
};


int main()
{
    Graph G(10);
    G.AddEdge(0,2);
    G.AddEdge(0,9);
    G.AddEdge(0,8);
    G.AddEdge(1,2);
    G.AddEdge(1,3);
    G.AddEdge(1,5);
    G.AddEdge(1,7);
    G.AddEdge(2,7);
    G.AddEdge(3,7);
    G.AddEdge(4,8);
    G.AddEdge(4,9);
    G.AddEdge(5,3);
    G.AddEdge(6,1);
    G.AddEdge(6,2);
    G.AddEdge(6,4);
    G.AddEdge(6,5);
    G.AddEdge(6,9);
    cout<<"Enter Starting Node: ";
    int nod;
    cin>>nod;
    G.DFS(nod);
    return 0;
}