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
        double x,y,s;
        cin>>x>>y>>s;
        if(x==0 && y==0 && s==0){ 
            break;
        }else{
            double max_cost=0;
            for(double v1=1; v1<=s; v1++){
                for(double v2=1; v2<=s; v2++){
                    if(v1==13 && v2==88){
                        //cout<<(floor(v1*(100+x)/100)+floor(v2*(100+x)/100))<<endl;
                    }
                        if(floor(v1*(100+x)/100)+floor(v2*(100+x)/100)==int(s)){
                            double new_cost=floor(v1*(100+y)/100)+floor(v2*(100+y)/100);
                            if(new_cost>max_cost){
                                max_cost=new_cost;
                            }
                        }
                    }
                }
                ans.push_back(max_cost);
            }
        }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}

