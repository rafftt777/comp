#include <bits/stdc++.h>
using namespace std;

using brut = long long;
#define bit 1000000LL

void brutal(){
    brut n;
    cin>>n;

    brut byte = n * bit * 8LL;
    //cout<<byte;

    byte = log2(byte);
    //cout<<byte<<endl;
    brut ans = 1;
    while(ans <= byte)ans++;
    
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int t = 1;

    while(t--)
        brutal();

    return 0;
}