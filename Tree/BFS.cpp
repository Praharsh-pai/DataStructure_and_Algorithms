#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;
int adj[MAX][MAX];
int adjSize[MAX];
bool visited[MAX];

void BFS(int start,int vertices){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<< " ";
        for(int i=0;i<adjSize[node];++i){
            int adjacentNode=adj[node][i];
            if (!visited[adjacentNode]){
                q.push(adjacentNode);
                visited[adjacentNode]=true;
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
    for(int  i=0;i<edges;++i){
        int u,v;
        cin>>u>>v;
        adj[u][adjSize[u]++]=v;
        adj[v][adjSize[v]++]=u;
    }
    int start;
    cout<<"Enter starting vertex: ";
    cin>>start;
    cout<<"BFS starting from vertex "<<start<< ": ";
    BFS(start,vertices);
    return 0;
}
