#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string code;
    int n = 0;
    while(getline(cin, code)){
        int t = 0;
        for(int i = 0; i < code.size(); i++){
            if(code[i] != ' '){
                t = i;
                break;
            }
        }
        for(int i = t; i < code.size(); i++){
            if(code[i] == '{'){
                cout << '{' << endl;
                n++;
                for(int j = 0; j < n; j++){
                    cout << "    ";
                }
            }
            else if(code[i] == '}'){
                cout << endl;
                n--;
                for(int j = 0; j < n; j++){
                    cout << "    ";
                }
                cout << '}' << endl;
            }
            else{
                cout << code[i];
            }
        }
    }
    return 0;
}