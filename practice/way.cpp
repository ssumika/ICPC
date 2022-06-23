#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_set>
#include<set>

using namespace std;

int main(){
    vector<int> ans;
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> p(100002,1);
    int p_max=1;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        for(int j=a; j<=b; j++){
            p[j]++;
            //cout<<"!"<<endl;
        }
    }
    for(int i=0; i<=n+1; i++){
        //cout<<p[i]<<endl;
        if(p[i]>=i){
            p_max=i;
        }
    }
    //cout<<p_max<<endl;
    ans.push_back(p_max-1);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}

