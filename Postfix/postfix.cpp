#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int priority(string a){
    int ap = 0;
    if(a == "^" || a == "%"){
        ap = 3;
    }
    else if(a == "*" || a == "/"){
        ap = 2;
    }
    else if(a == "+" || a == "-"){
        ap = 1;
    }
    else if(a == "(" || a == ")" || a == "="){
        ap = -1;
    }
    return ap;
}

void calculate(vector<string> input){
    int a, b;
    string now;
    stack<int> Stack;
    for(int i = 0; i < input.size(); i++){
        now = input[i];
        if(now == "+"){
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a+b);
        }
        else if(now == "-"){
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a-b);
        }
        else if(now == "*"){
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a*b);
        }
        else if(now == "/"){
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a/b);
        }
        else if(now == "^"){
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(pow(a, b));
        }
        else if(now == "%"){
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a%b);
        }
        else if(now == "="){
            break;
        }
        else{
            Stack.push(stoi(now));
        }
    }
    cout << Stack.top() << endl;
}

vector<string> infixToPostfix(){
    stack<string> symbol;
    vector<string> output;
    string n;
    while(cin >> n){
        if(priority(n) == 0){
            output.push_back(n);
        }
        else if(n == "("){
            symbol.push(n);
        }
        else if(n == ")"){
            while(true){
                if(symbol.top() == "("){
                    symbol.pop();
                    break;
                }
                else{
                    output.push_back(symbol.top());
                    symbol.pop();
                }
            }
        }
        else if(n == "+" || n == "-" || n == "*" || n == "/" || n == "%"){
            while(symbol.size() > 0 && priority(n) <= priority(symbol.top())){
                output.push_back(symbol.top());
                symbol.pop();
            }
            symbol.push(n);
        }
        else if(n == "^"){
            while(symbol.size() > 0 && priority(n) < priority(symbol.top())){
                output.push_back(symbol.top());
                symbol.pop();
            }
            symbol.push(n);
        }
        else if(n == "="){
            break;
        }
        else{
            cout << "error: Unknown " << n << endl;
        }
    }
    while(!symbol.empty()){
        output.push_back(symbol.top());
        symbol.pop();
    }
    return output;
}

int main(){
    vector<string> output;
    output = infixToPostfix();
    calculate(output);

    return 0;
}
