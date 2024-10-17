#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n){
    if(n==0||W==0)
        return 0;
    if(wt[n-1]>W)
        return knapSack(W,wt,val,n-1);
    else
        return max(knapSack(W,wt,val,n-1), val[n-1]+knapSack(W-wt[n-1],wt,val,n-1));
}

int main(){
    int profit[]={10,10,12,18};
    int weight[]={2,4,6,9};
    int W=15;
    int n=sizeof(profit)/sizeof(profit[0]);
    cout<<"Max Profit: "<<knapSack(W,weight,profit,n);
    return 0;
}