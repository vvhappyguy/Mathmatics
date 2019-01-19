#include <iostream>
#include <vector>

using namespace std;


int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<char> used;
 

bool vengr (int v) {
    if (used[v])  return false;
    used[v] = true;
    
    for (int i=0; i<k; ++i) {
        if (g[v][i] && (mt[i] == -1 || vengr (mt[i]))) {
            mt[i] = v;
            return true;
        }
    }
    return false;
}
 
int main() {
    string word;
    int res=0;
    
    cin>>k;
    cin>>word;
    n=word.size();
    
    for(int i=0;i<n;i++){
        vector<int>row;
        row.assign(k,0);
        g.push_back(row);
    }
    
    
    for(int i=0;i<k;i++){
        string kubik;
        cin>>kubik;
        for(int j=0;j<n;j++){
            int val=0;
            for(int l=0;l<6;l++){
                if(val!=1 && word[j]==kubik[l]) val=1;
            }
            g[j][i]=val;
        }
    }   
    for(int i=0;i<g.size();i++){
    for(int j=0;j<g[i].size();j++)
    cout<<g[i][j]<<' ';
    cout<<endl;
    }    
 
    mt.assign (k, -1);
    for (int v=0; v<n; ++v) {
        used.assign(n, false);
        vengr(v);
    }
    
    for(int i=0; i<k; ++i)
        if(mt[i] != -1)
          res++;  
          
    if(res==n) cout<<"YES"<<endl;
    else       cout<<"NO"<<endl;
}