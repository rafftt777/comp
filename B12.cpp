#include <bits/stdc++.h>
using namespace std;

int dfs(int i, vector<vector<int>> &adj, vector<int> &ans){
    if(adj[i].empty()){
        ans[i - 1] = 0;
        return 1;
    }

    int sub = 0;
    for(int v:adj[i])sub+=dfs(v, adj, ans);

    ans[i - 1] = sub;
    return sub + 1;
}

void solve(){
    int n;cin>>n;   
    vector<vector<int>> adj(n+1);
    vector<int> ans(n);

    for(int i = 2; i <= n; i++){
        int a;cin>>a;
        adj[a].push_back(i);
    }
    dfs(1, adj, ans);

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}