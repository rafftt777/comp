#include <bits/stdc++.h>
using namespace std;

const int N = 200100;

int a,b;
vector<int> adj[N];
vector<bool> vis;
vector<int> pai;

void dfs(int u) {
    vis[u] = true;
    for(int v:adj[u]){
        if(!vis[v]){
            pai[v] = u;
            dfs(v);
        }
    }
}

void solve() {
    int n;cin>>n>>a>>b;

    for(int i= 0;i <=n;i++){
        adj[i].clear();
    }
    vis.assign(n + 1, false);
    pai.assign(n + 1, -1);

    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(a);

    vector<int> path;
    while(b != -1){
        path.push_back(b);
        b = pai[b];
    }
    reverse(path.begin(), path.end());

    for(size_t i = 0;i < path.size();i++){
        cout<<path[i]<<" ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
