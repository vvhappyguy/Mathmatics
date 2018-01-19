#include <iostream>

using namespace std;

int main(){
    int count = 0;
    int z = 47;
    cin >> z;
    for(int i = 1; i < z; i++){
        if(((i * i) % z) == 1){
            cout << i << endl;
            count++;
        }
    }
    cout << endl << count << endl;
}