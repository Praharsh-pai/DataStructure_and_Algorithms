#include <iostream>
#include <climits>
using namespace std;
#define MAX 100
#define INF INT_MAX

void floydWarshall(int graph[MAX][MAX],int n){
    int dist[MAX][MAX];
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(graph[i][j]==0 && i!=j){
                dist[i][j] = INF;
            }else{
                dist[i][j]=graph[i][j];
            }
        }
    }

    for(int k=0;k<n;k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    cout<<"Shortest Distance Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==INF){
                cout<<"INF"<<"\t";
            }else{
                cout<<dist[i][j]<<"\t";
            }
        }
        cout<<endl;
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
    floydWarshall(graph,n);
    return 0;
}
