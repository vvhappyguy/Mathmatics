#include <iostream>

using namespace std;

int main(){
    cout << " << Program for finding reversible (obratimie) elements >>" << endl;
    cout << "Write module of Circle: ";
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
    cout << endl << "Count of reversible elements: " << count << endl;
    if(count + 1 == z){
        cout << "Module of Circle is simple number." << endl;
    }
}