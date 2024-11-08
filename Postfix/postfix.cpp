#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void calculate(vector<string> input) {
    int a, b;
    string now;
    stack<int> Stack;
    for (int i = 0; i < input.size(); i++) {
        now = input[i];
        if (now == "+") {
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a + b);
        } else if (now == "-") {
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a - b);
        } else if (now == "*") {
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a * b);
        } else if (now == "/") {
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a / b);
        } else if (now == "^") {
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(pow(a, b));
        } else if (now == "%") {
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            Stack.push(a % b);
        } else if (now == "=") {
            break;
        } else {
            Stack.push(stoi(now));
        }
    }
    cout << Stack.top() << endl;
}

vector<string> infixToPostfix() {
    stack<string> symbol;
    vector<string> output;
    map<string, int> priority{{"^", 3}, {"*", 2}, {"/", 2}, {"%", 2}, {"+", 1}, {"-", 1}, {"(", -1}, {")", -1}, {"=", -1}};
    string n;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> n) {
        bool f = false;
        if ((n[0] >= '0' && n[0] <= '9') || (n[0] == '-' && n.size() > 1)) {
            f = true;
        }
        for (int i = 1; i < n.size(); i++) {
            if (n[i] < '0' || n[i] > '9') {
                f = false;
            }
        }
        if (f) {
            output.push_back(n);
        } else if (n == "(") {
            symbol.push(n);
        } else if (n == ")") {
            while (true) {
                if (symbol.top() == "(") {
                    symbol.pop();
                    break;
                } else {
                    output.push_back(symbol.top());
                    symbol.pop();
                }
            }
        } else if (n == "+" || n == "-" || n == "*" || n == "/" || n == "%") {
            while (symbol.size() > 0 && priority[n] <= priority[symbol.top()]) {
                output.push_back(symbol.top());
                symbol.pop();
            }
            symbol.push(n);
        } else if (n == "^") {
            while (symbol.size() > 0 && priority[n] < priority[symbol.top()]) {
                output.push_back(symbol.top());
                symbol.pop();
            }
            symbol.push(n);
        } else if (n == "=") {
            break;
        } else {
            cout << "error: Unknown " << n << endl;
        }
    }
    while (!symbol.empty()) {
        output.push_back(symbol.top());
        symbol.pop();
    }
    return output;
}

int main() {
    vector<string> output;
    output = infixToPostfix();
    calculate(output);

    return 0;
}
