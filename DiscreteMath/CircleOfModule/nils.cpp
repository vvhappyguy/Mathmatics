#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int counter = 0;
    int z = 44;
    cin >> z;
    for(int i = 1; i < z; i++){
        for(int j = 2; j < z; j++){
            if((int)pow(i,j) % z == 0){
                cout << i << " "<< j<<endl;
                counter++;
            } 
        }
    }
    cout << endl << counter << endl;
}