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
    int n,W,H;
    cin>>n>>W>>H;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> w(n);
    vector<int> x_town(W);
    vector<int> y_town(H);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i]>>w[i];
        int left_x=max(0,x[i]-w[i]);
        int right_x=min(W,x[i]+w[i]);

        int left_y=max(0,y[i]-w[i]);
        int right_y=min(H,y[i]+w[i]);

        x_town[left_x]++;
        x_town[right_x]--;
        y_town[left_y]++;
        y_town[right_y]--;
    }

    for(int i=1; i<W; i++){
        x_town[i]+=x_town[i-1];
    }

    for(int i=1; i<H; i++){
        y_town[i]+=y_town[i-1];
    }

    bool flg=true;
    bool flg1=true;
    for(int i=0; i<W; i++){
        if(x_town[i]<1) flg=false;
    }

    for(int i=0; i<H; i++){
        if(y_town[i]<1) flg1=false;
    }

    if(!flg&&!flg1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

    
}