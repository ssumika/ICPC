#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    vector<int> ans;
    while(1){
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0){ 
            break;
        }else{
            vector<int> h,w;
            vector<int> h_sum(n+1,0),w_sum(m+1,0);
            int answer=0;
            for(int i=1; i<=n; i++){
                int num;
                cin>>num;
                h.push_back(num);
                h_sum[i]=h_sum[i-1]+num;
            }
            for(int i=1; i<=m; i++){
                int num;
                cin>>num;
                w.push_back(num);
                w_sum[i]=w_sum[i-1]+num;
            }

            vector<int> w_length;
            for(int i=1; i<=m; i++){
                for(int j=0; j<i; j++){
                    w_length.push_back(w_sum[i]-w_sum[j]);
                }
            }
            sort(w_length.begin(),w_length.end());
            
            for(int i=1; i<=n; i++){
                for(int j=0; j<i; j++){
                    int h_len=h_sum[i]-h_sum[j];
                    auto index=lower_bound(w_length.begin(),w_length.end(),h_len);
                    auto u_index=upper_bound(w_length.begin(),w_length.end(),h_len);
                    if(*index==h_len){
                        answer+=u_index-index;
                    }
                }
            }
            ans.push_back(answer);
            
            
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}
