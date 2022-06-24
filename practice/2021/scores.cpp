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
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0){ 
            break;
        }else{
            vector<vector<int>> p(m,vector<int>(n,0));
            for(int i=0; i<m; i++){
               for(int j=0; j<n; j++){
                   cin>>p[i][j];
               }
            }
            int max_score=0;
            for(int j=0; j<n; j++){
                int score=0;
                for(int i=0; i<m ;i++){
                    score+=p[i][j];
                }
                if(score>max_score){
                    max_score=score;
                }
            }
            ans.push_back(max_score);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
