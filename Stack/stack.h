#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template<class Type>
class Stack{
    private:
        Type size;
        Type index;
        Type *s;

    public:
        Stack(Type n);
        ~Stack();

        void push(Type v);
        Type pop();
        Type top();

        bool isFull();
        bool isEmpty();

        void show();
        Type getSize();
        Type getIndex();
        Type* getS();
};

#endif

#include <iostream>

using namespace std;

template<class Type>
Stack<Type>::Stack(Type n){
    index = 0;
    size = n;
    s = new Type [size];
}

template<class Type>
Stack<Type>::~Stack(){
    delete [] s;
}

template<class Type>
void Stack<Type>::push(Type v){
    if(!isFull()){
        *(s + index) = v;
        index++;
    }
}

template<class Type>
Type Stack<Type>::pop(){
    if(!isEmpty()){
        index--;
        return *(s + index);
    }
    return -1;
}

template<class Type>
Type Stack<Type>::top(){
    if(!isEmpty()){
        return *(s + index - 1);
    }
    return -1;
}

template<class Type>
bool Stack<Type>::isFull(){
    return index >= size;
}

template<class Type>
bool Stack<Type>::isEmpty(){
    return index == 0;
}

template<class Type>
void Stack<Type>::show(){
    cout << "[Bottom] -> ";
    for(Type i = 0; i < index; i++){
        cout << *(s + i) << " -> ";
    }
    cout << "[Top]" << endl;
}

template<class Type>
Type Stack<Type>::getIndex(){
    return index;
}

template<class Type>
Type* Stack<Type>::getS(){
    return s;
}

template<class Type>
Type Stack<Type>::getSize(){
    return size;
}
