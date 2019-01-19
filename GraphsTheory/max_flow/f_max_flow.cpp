#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

bool in(int a,vector<int> vec){
    for(int i=0;i<vec.size();i++)
        if(vec[i]==a) return true;
    return false;
}

int min_path(vector<int>vect,vector<vector<int>>matrix){
    int max=1000000;
    for(int i=0;i<vect.size()-1;i++){
        int num = matrix[vect[i]][vect[i+1]];
        if(num<max) max=num;
    }
    return max;
}

int path(int start,vector<int> &back,vector<vector<int>> matrix){
    int stop,go=clock();
    for(int i=1;i<matrix.size();i++){
        if(matrix[start][i]!=0 && !in(i,back)){
            if(i==1){
                back.push_back(i);
                return min_path(back,matrix);
                }
            back.push_back(i);
            int val=path(i,back,matrix);
            if(val==-1) back.pop_back();
            else return val;
            stop=clock();
            if((stop-go)>10000) break;
        }
    }
    return -1;
}


int max_flow(){
    size_t n;
    int res=0;
    cin>>n;
    
    vector<vector<int>> matrix;
    for(int i=0;i<n;i++){
        vector<int>row;
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }
    
    int val;
    while(val!=-1){
        vector<int>back;back.push_back(0);        
        val=path(0,back,matrix);
        if(val!=-1){
            for(int i=0;i<back.size()-1;i++)
                matrix[back[i]][back[i+1]]-=val;
            res+=val;
        }
        cout<<"result"<<res<<endl;//печать
    }
    return res;
}

int main(){
    cout<<max_flow()<<endl;
}