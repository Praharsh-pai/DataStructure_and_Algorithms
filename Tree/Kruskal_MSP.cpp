#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100

struct Edge{
    int u,v,weight;
};

struct DisjointSet {
    int parent[MAX],rank[MAX];

    void initialize(int n){
        for (int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void unionSet(int x,int y){
        int xRoot=find(x);
        int yRoot=find(y);
        if(xRoot!=yRoot){
            if(rank[xRoot]<rank[yRoot]){
                parent[xRoot]=yRoot;
            }else if(rank[xRoot]>rank[yRoot]){
                parent[yRoot]=xRoot;
            }else{
                parent[yRoot]=xRoot;
                rank[xRoot]++;
            }
        }
    }
};

bool compare(Edge a, Edge b){
    return a.weight<b.weight;
}

void kruskalMST(Edge edges[], int n, int e) {
    DisjointSet ds;
    ds.initialize(n);
    sort(edges, edges+e,compare);
    Edge mst[MAX];
    int mstSize=0,mstWeight=0;
    for(int i=0;i<e && mstSize<n-1;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int weight = edges[i].weight;
        if(ds.find(u)!=ds.find(v)){
            ds.unionSet(u,v);
            mst[mstSize++]=edges[i];
            mstWeight+=weight;
        }
    }
    cout<<"Edges in MST:\n";
    for(int i=0;i<mstSize;i++){
        cout<<mst[i].u<<" -- "<<mst[i].v<<" weighted "<<mst[i].weight<<endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main(){
    int n,e;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    Edge edges[MAX];
    cout<<"Enter the edges (u, v, weight):\n";
    for (int i=0;i<e;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].weight;
    }
    kruskalMST(edges,n,e);
    return 0;
}
