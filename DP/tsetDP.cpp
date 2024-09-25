#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int p[m];
    int c[m];
    for(int i = 0; i < m; i++){
        cin >> p[i];
    }
    for(int i = 1; i < n; i++){
        if(i <= m){
            c[i] = p[i];
        }
        for(int j = 1; j <= i; j++){
            c[i] = max(c[i], p[j] + c[i-j]);
        }
    }
    return 0;
}
