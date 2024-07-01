#include <iostream>
#include "stack.h"

using namespace std;

template<class Type>
void show(Stack<Type> s)
{
    cout << "[Bottom] -> ";
    for(int i = 0; i < s.getIndex(); i++){
        cout << *(s.getS() + i) << " -> " << endl;
    }
    cout << "[Top]" << endl;
    return;
}


int main(){
    Stack<int> s(3);
    s.push(1);
    s.show();
    s.push(2);
    s.show();
    s.push(3);
    s.show();
    s.push(4);
    s.show();
    cout << s.top() << endl;
    s.pop();
    s.show();
    cout << s.top() << endl;
    s.pop();
    s.show();
    s.push(5);
    s.show();
    cout << s.top() << endl;
    s.pop();
    s.show();
    cout << s.top() << endl;
    s.pop();
    s.show();
    cout << s.top() << endl; // 這裡的輸出可能會怪怪的，想想看為什麼 ?
    s.pop();
    s.show();
    return 0;
}
