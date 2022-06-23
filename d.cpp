#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_set>
using namespace std;

int main(int argc, char** argv)
{
    if(argc < 2) {
        cout << "Define filename!" << endl;
        return 0;
    }
    string filename = argv[1];
    ifstream cin(filename);
    vector<int> ans;
    while(!cin.eof()){
        int n;
        cin>>n;
        if(n==0){
            break;
        }else{
            vector<int> b(n);
            for(int i=0; i<n; i++){
                cin>>b[i];
            }
            sort(b.begin(),b.end());
            int max_count=0;
            do{
                vector<int> simulate_b(n);
                for(int i=0; i<n; i++){
                    simulate_b[i]=b[i];
                    //cout<<simulate_b[i];
                }
                int count=0;
                while(true){  
                    int flg=0;  
                    for(int i=0; i<n; i++){
                        if(simulate_b[i]>0){
                            flg++;
                            //cout<<flg<<endl;
                            simulate_b[i]--;
                        }
                        if(flg==3){
                            count++;
                            break;
                        }
                    }
                    if(flg<3){
                        //cout<<" "<<count<<endl;
                       if(max_count<count){
                            max_count=count;
                            /*
                            for(int j=0; j<n; j++){
                                cout<<b[j];
                            }
                            */
                        }
                        break;
                    }
                }
            }while(next_permutation(b.begin(),b.end()));
            ans.push_back(max_count);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}