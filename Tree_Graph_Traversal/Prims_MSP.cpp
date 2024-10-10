#include <iostream>
#include <climits>
using namespace std;
#define MAX 100

int minKey(int key[],bool mstSet[],int n){
    int min = INT_MAX,min_index;

    for(int v = 0; v < n; v++){
        if(!mstSet[v] && key[v]<min){
            min=key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[MAX][MAX], int n){
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0; 
    parent[0]=-1; 

    for(int count=0;count<n-1;count++){
        int u=minKey(key,mstSet,n);
        mstSet[u]=true;
        for(int v=0;v<n;v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    cout<<"Edge \tWeight\n";
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<" \n";
    }
}

int main(){
    int n,e;
    int graph[MAX][MAX]={0};
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Enter the edges (u v weight):\n";
    for(int i=0;i<e;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        graph[u][v]=weight;
        graph[v][u]=weight;  // For undirected graph
    }
    primMST(graph,n);
    return 0;
}
