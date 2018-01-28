#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cout << " << Program for finding nillpotents >>" << endl;
    cout << "Write module of Circle: ";
    int counter = 0;
    int z;
    int max = 0;
    cin >> z;
    for(int i = 1; i < z; i++){
        for(int j = 2; j < z; j++){
            if((int)pow(i,j) % z == 0){
                cout << i << " "<< j<<endl;
                counter++;
                max = j;
            } 
        }
    }
    if(max != 0){
        cout << "Max order of element is " << max << endl;
    } else {
        cout << "There are no nils" << endl;
    }
    if(counter > 1){
        cout << "Count of nils: " << counter << endl;
    }
}