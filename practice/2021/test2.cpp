#include <bits/stdc++.h>
#include<unordered_set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
using ll = long long;

int ans = 0;
int h,w;

unordered_set<string> s;

void place(vector<string> a, int x0, int y0) {
    for(int i=0; i<h-1; i++) {
        for(int j=0; j<w-1; j++) {
            if(a[i][j]=='.' && a[i][j+1]=='.' && a[i+1][j]=='.') {
                vector<string> a1(h);
                rep(i,h) {
                    a1[i] = a[i];
                }
                a1[i][j]='1'; a1[i][j+1]='1'; a1[i+1][j]='1';
                place(a1, i, j);
            }
            if(a[i][j]=='.' && a[i+1][j]=='.' && a[i+1][j+1]=='.') {
                vector<string> a1(h);
                rep(i,h) {
                    a1[i] = a[i];
                }
                a1[i][j]='2'; a1[i+1][j]='2'; a1[i+1][j+1]='2';
                place(a1, i, j);
            }
            if(a[i][j]=='.' && a[i][j+1]=='.' && a[i+1][j+1]=='.') {
                vector<string> a1(h);
                rep(i,h) {
                    a1[i] = a[i];
                }
                a1[i][j]='3'; a1[i][j+1]='3'; a1[i+1][j+1]='3';
                place(a1, i, j);
            }
            if(a[i+1][j]=='.' && a[i][j+1]=='.' && a[i+1][j+1]=='.') {
                vector<string> a1(h);
                rep(i,h) {
                    a1[i] = a[i];
                }
                a1[i+1][j]='4'; a1[i][j+1]='4'; a1[i+1][j+1]='4';
                place(a1, i, j);
            }
            if(a[i][j]=='.') return;
        }
    }
    rep(i,h) {
        rep(j, w) {
            if(a[i][j]=='.') return;
        }
    }
    string res = "";
    rep(i,h) {
        // cout << a[i] << endl;
        res += a[i];
    }
    // cout << endl;
    s.insert(res);
    ans += 1;
    return;
}

int main() {
    while(true) {
        ans = 0;
        cin >> h >> w;
        if(h==0 && w==0) return 0;
        vector<string> a(h);
        rep(i,h) cin >> a[i];
        place(a, 0, 0);
        cout << s.size() << endl;
    }
}

















