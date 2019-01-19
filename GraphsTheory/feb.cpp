#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mult(vector<vector<int>> m1,vector<vector<int>> m2, int p);
vector<vector<int>> exp(int k,vector<vector<int>> m1, int p);


int main(){
 int a,b,A,B,p,k;
 
 cout<<"Введите коэффициенты X(n+1) = aX(n) + bX(n-1)"<<endl<<"a: ";
 cin>>a;
 cout<<"b: ";
 cin>>b;
 cout<<"Введите первые значения"<<endl<<"A: ";
 cin>>A;
 cout<<"B: ";
 cin>>B;
 cout<<"Кольцо: ";
 cin>>p;
 cout<<"Номер элемента: ";
 cin>>k;
 
 vector<vector<int>> fr;
 for(int i=0;i<2;i++){
     vector<int> row(2);
     fr.push_back(row);
 }
 fr[0][0]=0;
 fr[1][0]=1;
 fr[0][1]=b;
 fr[1][1]=a;
 
 if(k>2){
     vector<vector<int>> new_fr=exp(k-1,fr,p);
     cout<<(new_fr[0][0]*A+new_fr[0][1]*B)%p<<endl;
 }
 else 
     k==1?cout<<A<<endl:cout<<B<<endl;
}



vector<vector<int>> mult(vector<vector<int>> m1,vector<vector<int>> m2,int p){
    vector<vector<int>> m3;
    
    for(int i=0;i<2;i++){
     vector<int> row(2);
     m3.push_back(row);}
    
    m3[0][0]=(m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0])%p;
    m3[0][1]=(m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1])%p;
    m3[1][0]=(m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0])%p;
    m3[1][1]=(m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1])%p;
    return m3;
}

vector<vector<int>> exp(int k,vector<vector<int>> m1, int p){
    if(k==1) return m1;
    vector<vector<int>> m2;
    if(k%2==1) m2=mult(exp(1,m1,p),exp(k-1,m1,p),p);
    else       m2=mult(exp(k/2,m1,p),exp(k/2,m1,p),p);
    return m2;
}