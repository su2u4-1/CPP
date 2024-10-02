#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int ij = 0; ij < n; ij++){
        string s;
        cin >> s;
        for (int i = 0; i < (s.length() / 6); i++){
            string k = "";
            for (int j = 0; j < 6; j++){
                k += s[i*6 + j];
            }
            char o = '#';
            if(k == "000000"){
                o = 'A';
            }else if(k == "000011"){
                o = 'B';
            }else if(k == "000101"){
                o = 'C';
            }else if(k == "000110"){
                o = 'D';
            }else if(k == "001001"){
                o = 'E';
            }else if(k == "001010"){
                o = 'F';
            }else if(k == "001100"){
                o = 'G';
            }else if(k == "001111"){
                o = 'H';
            }else if(k == "010001"){
                o = 'I';
            }else if(k == "010010"){
                o = 'J';
            }else if(k == "010100"){
                o = 'K';
            }else if(k == "010111"){
                o = 'L';
            }else if(k == "011000"){
                o = 'M';
            }else if(k == "011011"){
                o = 'N';
            }else if(k == "011101"){
                o = 'O';
            }else if(k == "011110"){
                o = 'P';
            }else if(k == "100001"){
                o = 'Q';
            }else if(k == "100010"){
                o = 'R';
            }else if(k == "100100"){
                o = 'S';
            }else if(k == "100111"){
                o = 'T';
            }else if(k == "101000"){
                o = 'U';
            }else if(k == "101011"){
                o = 'V';
            }else if(k == "101101"){
                o = 'W';
            }else if(k == "101110"){
                o = 'X';
            }else if(k == "110000"){
                o = 'Y';
            }else if(k == "110011"){
                o = 'Z';
            }else if(k == "110101"){
                o = ' ';
            }else if(k == "110110"){
                o = ',';
            }else if(k == "111001"){
                o = '.';
            }else if(k == "111010"){
                o = '-';
            }else if(k == "111100"){
                o = '"';
            }else if(k == "111111"){
                o = '\'';
            }
            cout << o;
        }
        cout << endl;
    }
    return 0;
}