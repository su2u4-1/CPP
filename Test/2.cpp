#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int t = 1;
    for(int i = n; i > k; i--){
        t *= i;
    }
    for(int i = k; i > 0; i--){
        t /= i;
    }
    int a[t][k];
    for(int i = 0; i < t; i++){
        a[i][0] = n;
    }

    return 0;
}