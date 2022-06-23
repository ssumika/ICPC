#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_set>

using namespace std;

int main(){
    vector<int> ans;
    while(1){
        int n,m,a;
        cin>>n>>m>>a;
        if(n==0 && m==0 && a==0){ 
            break;
        }else{
            vector<tuple<int,int,int>> amida;
            for(int i=0; i<m; i++){
                int h,p,q;
                cin>>h>>p>>q;
                amida.push_back(make_tuple(h,p,q));
            }
            sort(amida.rbegin(),amida.rend());
            int p=a;
            for(int i=0; i<m; i++){
                if(get<1>(amida[i])==p){
                    p=get<2>(amida[i]);
                }else if(get<2>(amida[i])==p){
                    p=get<1>(amida[i]);
                }
            }
            ans.push_back(p);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}

