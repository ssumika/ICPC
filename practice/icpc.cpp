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
        int n;
        cin>>n;
        if(n==0){ 
            break;
        }else{
            vector<int> a(n);
            for(int i=0; i<n; i++){
                cin>>a[i];
            }
            sort(a.begin(),a.end());
            int total=0;
            for(int i=1; i<n-1; i++){
                total+=a[i];
            }
            ans.push_back(total/(n-2));
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}
