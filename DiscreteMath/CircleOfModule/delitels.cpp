#include <iostream>

using namespace std;

int main(){
    cout << " << Program for finding nillpotents >>" << endl;
    cout << "Write module of Circle: ";
    int counter = 0;
    int z = 44;
    cin >> z;
    for(int i = 1; i < z; i++){
        for(int j = 2; j < z; j++){
            if((i * j) % z == 0){
                cout << i << " "<< j<<endl;
                counter++;
            } 
        }
    }
    cout << "Count of zeros in Circle: "<< endl << counter << endl;
}