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
    int m;
    cin>>m;
    vector<string> train(m);
    for(int i=0; i<m; i++){
        cin>>train[i];
    }
    for(int i=0; i<m; i++){
        set<string> line;
        for(int j=1; j<train[i].size(); j++){
            string s1=train[i].substr(0,j);
            string s2=train[i].substr(j,train[i].size());
            string s3="";
            string s4="";
            for(int k=s1.size()-1; k>=0; k--){
                s3+=s1[k];
            }
            //cout<<s3<<endl;;
            for(int k=s2.size()-1; k>=0; k--){
                s4+=s2[k];
            }
            //cout<<s4<<endl;
            line.insert(s1+s2);
            line.insert(s2+s1);
            line.insert(s3+s4);
            line.insert(s4+s3);
            line.insert(s1+s4);
            line.insert(s2+s3);
            line.insert(s4+s1);
            line.insert(s3+s2);
            
            //cout<<train[i].substr(0,j)+"+"+train[i].substr(j,train[i].size())<<endl;
        }
        ans.push_back(line.size());
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}

