#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main()
{
    ifstream cin("J");
    vector<int> ans;
    while(!cin.eof()){
        int a,b;
        cin>>a>>b;
        if(a==0 && b==0){
            break;
        }else{
            ans.push_back(a*b);
    
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}