#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<cmath>

using namespace std;
using ll = long long;

int main()
{
    ifstream cin("test.txt");
    vector<ll> ans;
    vector<string> a;
    while(!cin.eof()){
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0){
            break;
        }else{
            int r=-100000000;
            string ans_day;
            for(int i=0; i<(1<<(n+m)); i++){
                vector<int> day(n+m);
                int count=0;
                for(int j=0; j<(n+m); j++){
                    if(i & (1<<j)){
                        day[j]=1;
                        count++;
                    }else{
                        day[j]=-1;
                    }
                }
                if(count==n){
                    int sum=0;
                    int k=1;
                    for(int j=0; j<(n+m); j++){
                        if(j==0){
                            sum+=day[j]*(2*k-1);
                        }else{
                            if(day[j-1]==day[j]){
                                k+=1;
                            }else{
                                k=1;
                            }
                            sum+=day[j]*(2*k-1);
                        }
                        //cout<<sum<<endl;
                    }
                    //r=max(r,sum);
                    if(r<=sum){
                        r=sum;
                        ans_day="";
                        for(int j=0; j<(n+m); j++){
                            if(i & (1<<j)){
                                ans_day+="o";
                            }else{
                                ans_day+="x";
                            }
                        }
                    }
                }
            }
            ans.push_back(r);
            a.push_back(ans_day);
        }
    
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
        cout<<a[i]<<endl;
    }

    return 0;
}