#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int count = 0;
    int z = 47;
    cin >> z;
    for(int i = 1; i < z; i++){
        for(int j = 1; j < z; j++){
           if(((i * j) % z == 1)) {
               cout << i << " " << j<<endl;
               count++;
           }
        }
    }
    cout << endl << count << endl;
}