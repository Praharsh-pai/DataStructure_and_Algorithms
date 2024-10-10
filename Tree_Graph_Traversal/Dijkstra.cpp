#include <iostream>
#include <climits>
using namespace std;
#define MAX 100

int minDistance(int dist[],bool sptSet[],int n){
    int min=INT_MAX,min_index;
    for(int v=0;v<n;v++){
        if(!sptSet[v] && dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX],int n,int src,int dist[MAX]){
    bool sptSet[MAX];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[src] = 0;
    for (int count=0;count<n-1;count++){
        int u=minDistance(dist,sptSet,n);
        sptSet[u]=true;
        for(int v=0;v<n;v++){
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
}

int main(){
    int n,e;
    int graph[MAX][MAX]={0};
    int distanceMatrix[MAX][MAX];
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
    for(int src=0;src<n;src++){
        int dist[MAX];
        dijkstra(graph,n,src,dist);
        for(int i=0;i<n;i++){
            distanceMatrix[src][i]=dist[i];
        }
    }
    cout<<"\nShortest Distance Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(distanceMatrix[i][j]==INT_MAX){
                cout<<"INF"<<"\t";
            }else{
                cout<<distanceMatrix[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    return 0;
}
