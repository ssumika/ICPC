#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<cmath>

using namespace std;
using ll=long long;

long long pow(long long x,long long n){
    long long ans=1;
    while(n>0){
        if(n%2==1){
            ans*=x;
        }
        n/=2;
        x*=x;
    }
    return ans;
}

int main()
{
    ifstream cin("test.txt");
    vector<ll> ans;
    while(!cin.eof()){
        int k;
        cin>>k;
        if(k==0){
            break;
        }else{
            string s;
            cin>>s;
            ll n=s.size();
            vector<vector<ll>> dp(n,vector<ll>(k,0));
            for(int i=0; i<n; i++){
                dp[i][0]=(s[i]-'0')*pow(10,k-1);
                //cout<<dp[i][0]<<endl;
            }
            for(int i=1; i<n; i++){
                for(int j=0; j<k; j++){
                    if(i>=j){
                        dp[i][j]=max(dp[i-1][j],dp[i-1][(j+k-1)%k]+pow(ll(10),ll(k-1-j))*(s[i]-'0'));
                        //cout<<dp[i][j]<<endl;
                    }
                }
            }
            ans.push_back(dp[n-1][k-1]);
        }
    
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}