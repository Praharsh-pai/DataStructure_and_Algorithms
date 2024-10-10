#include <iostream>
#include <algorithm>
using namespace std;

int cutRod(int price[],int n){
    int dp[n+1];
    int pieces[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int max_val=-1;
        for(int j=0;j<i;j++){
            if (max_val<price[j]+dp[i-j-1]){
                max_val=price[j]+dp[i-j-1];
                pieces[i]=j+1;
            }
        }
        dp[i]=max_val;
    }
    cout<<"Maximum Obtainable Value is: "<<dp[n]<<endl;
    cout<<"Rod pieces used to achieve this value: ";
    int length=n;
    while(length>0){
        cout<<pieces[length] << " ";
        length-=pieces[length];
    }
    cout << endl;
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the length of the rod: ";
    cin>>n;
    int price[n];
    cout<<"Enter the prices for each length: ";
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cutRod(price,n);
    return 0;
}
