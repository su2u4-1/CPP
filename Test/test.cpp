#include <iostream>
#include <stack>
#include <string>
#include <cmath>

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
    else if(a == "(" || a == "="){
        ap = -1;
    }
    return ap;
}

void compute(stack<string> input){
    int a, b;
    string now;
    stack<int> Stack;
    for(int i = 0; i < input.size(); i++){
        now = input.top();
        if(now == "+"){
            cout << "push +" << endl;
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a+b);
        }
        else if(now == "-"){
            cout << "push -" << endl;
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a-b);
        }
        else if(now == "*"){
            cout << "push *" << endl;
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a*b);
        }
        else if(now == "/"){
            cout << "push /" << endl;
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a/b);
        }
        else if(now == "^"){
            cout << "push ^" << endl;
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(pow(a, b));
        }
        else if(now == "%"){
            cout << "push %" << endl;
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
            cout << "push " << now << endl;
            Stack.push(stoi(now));
        }
        cout << "top= " <<Stack.top() << endl;
        input.pop();
    }
    cout << Stack.top() << endl;
}

int main(){
    string n, r;
    stack<string> symbol;
    stack<string> output;
    int a, b;
    while(cin >> n){
        if(priority(n) == 0){
            output.push(n);
        }
        else if(n == "("){
            symbol.push(n);
        }
        else if(n == ")"){
            while(true){
                if(symbol.top() != "("){
                    output.push(symbol.top());
                    symbol.pop();
                }
                else{
                    symbol.pop();
                    break;
                }
            }
        }
        else if(n == "+" || n == "-" || n == "*" || n == "/" || n == "%"){
            while(symbol.size() > 0 && priority(n) <= priority(symbol.top())){
                output.push(symbol.top());
                symbol.pop();
            }
            symbol.push(n);
        }
        else if(n == "^"){
            while(symbol.size() > 0 && priority(n) < priority(symbol.top())){
                output.push(symbol.top());
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
    compute(output);

    return 0;
}
