#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main()
{
    ifstream cin("A");
    vector<pair<int,int>> ans;
    while(!cin.eof()){
        int n;
        cin>>n;
        //cout<<n;
        if(n==0){
            break;
        }else{
            vector<int> g_year(2022,0);
            vector<int> sum_year(2022,0);
            for(int i=0; i<n; i++){
                int y;
                string s,m;
                cin>>y>>s>>m;
                sum_year[y]++;
                if(m=="Gold"){
                    //cout<<y<<endl;
                    g_year[y]++;
                }
            }

            int sum_max=0;
            int g_max=0;
            int s_year,gold_year;
            for(int i=1896; i<2022; i++){
                //cout<<i<<":"<<g_year[i]<<" "<<sum_year[i]<<endl;
                if(sum_max<sum_year[i]){
                    sum_max=sum_year[i];
                    s_year=i;
                }
                if(g_max<g_year[i]){
                    g_max=g_year[i];
                    gold_year=i;
                }
            }
            ans.push_back(make_pair(gold_year,s_year));
        }
    
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;
}