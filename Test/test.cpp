#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int cp(string a){
    int ap = 0;
    if(a == "^" || a == "%"){
        ap = 3;
    }
    else if(a == "*" || a == "/"){
        ap = 2;
    }
    else if(a == "+" || a == "1"){
        ap = 1;
    }
    return ap;
}

bool pc(string a, string b){
    int ap = cp(a);
    int bp = cp(b);
    return bp < ap;
}

stack<int> s;
void co(string r){
    int a, b;
    if(r == "+"){
        // cout << "push +" << endl;
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a+b);
    }
    else if(r == "-"){
        // cout << "push -" << endl;
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a-b);
    }
    else if(r == "*"){
        // cout << "push *" << endl;
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a*b);
    }
    else if(r == "/"){
        // cout << "push /" << endl;
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a/b);
    }
    else if(r == "^"){
        // cout << "push ^" << endl;
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(pow(a, b));
    }
    else if(r == "%"){
        // cout << "push %" << endl;
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a%b);
    }
    else if(r == "="){
        cout << s.top() << endl;
        exit(0);
    }
    else{
        // cout << "push " << n << endl;
        s.push(stoi(r));
    }
    // cout << "top= " <<s.top() << endl;
}

int main(){
    string n, r;
    stack<string> v;
    int a, b;
    while(cin >> n){
        if(cp(n) == 0){
            co(n);
        }
        else if(n == "("){
            v.push(n);
        }
    }

    return 0;
}
