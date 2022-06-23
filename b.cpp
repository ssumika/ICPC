#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
using ll = long long;

int w,h;
vector<int> x(1000), y(1000), n(1000);

void solve() {
    vector<vector<bool>> g(w, vector<bool>(h, false));
    rep(i, w+h-1) {
        g[x[i]][y[i]] = true;
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(!g[i][j]){
                break;
            }
            for(int j1=j+1; j<w; j++){
                
            }
        }
    }
    
}

int main() {
    while(true) {
        cin >> w >> h;
        if(w==0 && h==0) return 0;
        rep(i, w+h-1) {
            cin >> x[i] >> y[i] >> n[i];
            x[i]--; y[i]--;
        }

        solve();
    }
}