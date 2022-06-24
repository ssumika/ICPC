#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    ifstream fin("J");
    vector<int> s(2);
    while(!fin.eof()){
        fin>>s[0]>>s[1];
        if(s[0]==0 && s[1]==0){
            return 0;
        }else{
            cout<<s[0]*s[1]<<endl;
        }
    }

    return 0;
}