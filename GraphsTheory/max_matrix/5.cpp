#include <iostream>

using namespace std;

int main()
{
    long long a,b,power,p,matrix[2][2], res[2][2], matrix1[2][1],newres[2][2], newmatrix[2][2];
    cin>>a>>b>>power>>p;
    matrix[0][0]=0;
    matrix[0][1]=1;
    matrix[1][0]=b;
    matrix[1][1]=a;

    res[0][0]=1;
    res[0][1]=0;
    res[1][0]=0;
    res[1][1]=1;

    while (power){
        if (power % 2 == 1)
        {
            newres[0][0]=(res[0][0]*matrix[0][0] + res[0][1]*matrix[1][0])%p;
            newres[0][1]=(res[0][0]*matrix[0][1] + res[0][1]*matrix[1][1])%p;
            newres[1][0]=(res[1][0]*matrix[0][0] + res[1][1]*matrix[1][0])%p;
            newres[1][1]=(res[1][0]*matrix[0][1] + res[1][1]*matrix[1][1])%p;
            power--;
            res[0][0]=newres[0][0];
            res[0][1]=newres[0][1];
            res[1][0]=newres[1][0];
            res[1][1]=newres[1][1];
        }
        else{
        newmatrix[0][0]=(matrix[0][0]*matrix[0][0] + matrix[0][1]*matrix[1][0])%p;
        newmatrix[0][1]=(matrix[0][0]*matrix[0][1] + matrix[0][1]*matrix[1][1])%p;
        newmatrix[1][0]=(matrix[1][0]*matrix[0][0] + matrix[1][1]*matrix[1][0])%p;
        newmatrix[1][1]=(matrix[1][0]*matrix[0][1] + matrix[1][1]*matrix[1][1])%p;
        power/=2;
        matrix[0][0]=newmatrix[0][0];
        matrix[0][1]=newmatrix[0][1];
        matrix[1][0]=newmatrix[1][0];
        matrix[1][1]=newmatrix[1][1];
        }
    }

    matrix1[0][0]=0;
    matrix1[1][0]=1;

    int result=(newres[0][1]*matrix1[1][0])%p;
    cout<<result;

    return 0;
}
