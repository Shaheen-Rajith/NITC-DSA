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

    void BFS(int start)
    {
        bool visited[numVertices];
        for(int i=0; i<numVertices; i++)
            visited[i]=false;
        list<int> queue;
        list<int>::iterator i;
        visited[start]=true;
        queue.push_back(start);
        cout<<"\nBFS starting from Node "<<start<<": ";
        while(!queue.empty())
        {
            int curr = queue.front();
            cout<<curr <<",";
            queue.pop_front();
            for(i = AdjList[curr].begin() ; i != AdjList[curr].end() ; i++)
            {
                int vertex = *i;
                if(!visited[vertex])
                {
                    visited[vertex]=true;
                    queue.push_back(vertex);
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
    G.BFS(nod);
    return 0;

}