//栈的实现
#include <iostream>
#include <stack>
using namespace std;
#define MAXN 1000

int st[MAXN]; //一般使用数组来实现栈，栈底为stack[0]，栈顶为stack[p-1]
int p = 0;

void push(int x){ //入栈，将x放入栈顶
    if(p >= MAXN)
        cout<< "Stack overflow" << endl;
    else {
        st[p] = x;
        p++;
    }
}

void pop(){
    if(p == 0)
        cout<< "Stack is empty" << endl;
    else 
        p--;
}

int top(){
    if(p == 0){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else 
        return st[p - 1];
}

int main()
{
    cout<<"我们可以使用STL中的stack来实现栈"<< endl;
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<< s.top() << endl;
    s.pop();
    cout<< s.top() << endl;
    cout<< s.empty() << endl;
    cout<< s.size() << endl;
    s.emplace(4);   //emplace()和push()的区别是emplace()可以直接将元素放入栈中，而push()需要先创建一个元素再放入栈中
    cout<< s.top() << endl;

    return 0;
}