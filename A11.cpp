#include <bits/stdc++.h>
using namespace std;

using brut = long long;

#define dbg(x)cout<<#x<<" = "<<x<<endl;

vector<pair<int, int>> moves = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(vector<vector<int>> &vt){
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    
    int n = vt.size(), m = vt[0].size();
    n--;
    m--;

    //dbg(n);
    //dbg(m);
    int gordura = 50;

    vector<vector<int>> tam(n + gordura, vector<int> (m + gordura, -1));
    tam[1][1] = 0;
    
    vector<vector<int>> vis(n + gordura, vector<int> (m + gordura, 0));
    vis[1][1] = 1;
    
    while(!q.empty()){
        auto[x,y] = q.front();
        q.pop();
        //cout<<"!! "<<x<<" "<<y<<endl;
        
        for(auto[dx, dy]: moves){
            //assert(x<=n);
            //assert(y<=m);
            //assert(x>=1);
            //assert(y>=1);
            
            int nx = x+(dx * vt[x][y]);
            int ny = y+(dy * vt[x][y]);
            
            if((nx <= n && ny <= m ) && (nx >= 1 && ny >= 1) /*&& vis[nx][ny] != 1*/){
                if(vis[nx][ny]==1)continue;
                //cout<<nx<<" "<<ny<<endl;

                q.push(make_pair(nx, ny));
                tam[nx][ny] = tam[x][y] + 1;
                vis[nx][ny]= 1;
            }
        }
        // exit(0);
    }
    cout<<tam[n][m]<<"\n";
}

void brutal(){
    int n, m; cin>>n>>m;
    vector<vector<int>> vt(n + 1, vector<int> (m + 1));

    for(int i = 1; i <= n; i++){
        string at; cin>>at;
        int j = 1;
        int t = 0;
        while(t < m){
            vt[i][j] = at[t] - '0';
        //cout<<vt[i][j];
            t++;
            j++;    
        }//cout<<"\n";
    }
    
    bfs(vt);//buscar caminho

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    brutal();

    return 0;
}