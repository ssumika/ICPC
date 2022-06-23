#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_set>

using namespace std;

void swap(int *x,int *y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

int main(){
    vector<int> ans;
    while(1){
        int n,r;
        cin>>n>>r;
        if(n==0 && r==0){ 
            break;
        }else{
            vector<int> h(n);
            int num=1;
            for(int i=n-1; i>=0; i--){
                h[i]=num;
                num++;
            }
            for(int i=0; i<r; i++){
                int p,c;
                cin>>p>>c;
                vector<int> card(p+c-1);
                for(int j=0; j<c; j++){
                    card[j]=h[j+p-1];
                }
                for(int j=c; j<p+c-1; j++){
                    card[j]=h[j-c];
                }
                for(int j=0; j<p+c-1; j++){
                    h[j]=card[j];
                }
            }
            ans.push_back(h[0]);
            
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}
