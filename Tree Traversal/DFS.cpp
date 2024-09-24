#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1000;
int adj[MAX][MAX];
int adjSize[MAX];
bool visited[MAX];

void DFS(int start,int vertices){
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!visited[node]){
            cout<<node<<" ";
            visited[node]=true;
        }
        for(int i=adjSize[node]-1;i>=0;--i){
            int adjacentNode=adj[node][i];
            if(!visited[adjacentNode]){
                s.push(adjacentNode);
            }
        }
    }
}

int main(){
    int vertices,edges;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertices>>edges;
    for(int i=1;i<=vertices;++i){
        adjSize[i]=0;
        visited[i]=false;
    }
    cout<<"Enter edges (u v): "<<endl;
    for(int i=0;i<edges;++i){
        int u,v;
        cin>>u>>v;
        adj[u][adjSize[u]++]=v;
        adj[v][adjSize[v]++]=u;
    }
    int start;
    cout<<"Enter starting vertex: ";
    cin>>start;
    cout<<"DFS starting from vertex "<<start<<": ";
    DFS(start,vertices);
    return 0;
}
