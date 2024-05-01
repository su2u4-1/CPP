#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    unordered_map<int, pair<int, int>> dict1;
    unordered_map<int, int> dict2;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int t;
            cin >> t;
            if (dict1.find(t) == dict1.end()){
                dict1[t] = make_pair(i, j);
            }else{
                dict2[t] = abs(dict1[t].first-i) + abs(dict1[t].second-j);
            }
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        int a;
        cin >> a;
        cout << dict2[a] << " ";
    }
    cout << endl;

    return 0;
}
