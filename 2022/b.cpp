#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  ifstream cin("test.txt");
  while(!cin.eof()){
    int n;
    cin>>n;
    if(n==0) break;
    vector<vector<int>> p(n);
    vector<bool> finish(n,true);
    for(int i=0;i<n;i++){
      int a,b;
      cin>>a>>b;
      p[i].push_back(a);
      p[i].push_back(b);
      if(a==b) finish[i]=false;
    }
    int ans=0;
    int k=0;
    
    for(int i=0; i<n; i++){
        if(finish[i]){
            k=i;
            break;
        }
    }

    
    while(1){
    /*
    if(ans<=3){
      for(int i=0; i<n; i++){
        for(int j=0; j<p[i].size(); j++){
            if(finish[i]){
                cout<<p[i][j]<<" ";
            }
        }
        cout<<endl;
      }
    }
    */
    
      if(count(finish.begin(),finish.end(),true)==0){
        break;
      }else{
        //cout<<k<<endl;
        ans++;
        int next=(k+1)%n;
        sort(p[k].begin(),p[k].end());
        while(!finish[next]){
            next++;
            next%=n;
        }
        sort(p[next].begin(),p[next].end());
        p[next].push_back(p[k][0]);
        p[k].erase(p[k].begin());
        sort(p[k].begin(),p[k].end());
        sort(p[next].begin(),p[next].end());
        for(int i=1; i<p[next].size(); i++){
            if(p[next][i]==p[next][i-1]){
                p[next].erase(p[next].begin()+i-1,p[next].begin()+i+1);
            }
        }
        if(p[k].size()==0){
            finish[k]=false;
        }
        if(p[next].size()==0){
            finish[next]=false;
        }
        k=next;
      }
      
    }
  cout<<ans<<endl;
  }
}