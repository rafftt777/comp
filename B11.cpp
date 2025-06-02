l#include <bits/stdc++.h>
using namespace std;

using brut = long long;
const int N = 200100;

//map<pair<int,int>,int> vis;

vector<pair<int, int>> moves = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int i, int j, vector<vector<char>> &vt){
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    //vis[i][j] = 1;
    int n = vt.size(), m = vt[0].size();

    vt[i][j] = '#';

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(auto [dx, dy]: moves){
            int nx = x + dx;
            int ny = y + dy;

            if((nx < n && ny < m) && (nx >= 0 && ny >= 0) && vt[nx][ny] != '#'){
                q.push(make_pair(nx, ny));
                vt[nx][ny] = '#';
            }
        }
    }
}

void brutal(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> vt(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
        cin>>vt[i][j];
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vt[i][j] != '#'){
                bfs(i, j, vt);//ponto inicial
                count++;
            }
        }
    }
    cout<<count<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int t = 1;

    while(t--)
        brutal();

    return 0;
}