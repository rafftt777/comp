#include <bits/stdc++.h>
using namespace std;

using brut = long long;

void brutal(){
    int n, m; cin>>n>>m;
    int i = 1, y;

    while(m--){
        
        //cout<<i<<" "<<n<<" "<<m<<endl;
        i += __gcd(i, n);
    }
    
    cout<<i<<"\n";
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int t = 1;

    while(t--)
        brutal();

    return 0;
}