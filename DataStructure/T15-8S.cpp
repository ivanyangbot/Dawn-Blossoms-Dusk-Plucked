#include <iostream>
#include <queue>
using namespace std;

#define MAXN 1000

int que[MAXN];
int head = 0;
int tail = 0;

void push(int x){ //进队尾
    if(tail >= MAXN)
        cout << "Queue overflow." << endl;
    else {
        que[tail] = x;
        tail ++;
    }
}

void pop(){ //弹队首
    if(head == tail)
        cout << "Queue is empty." << endl;
    else
        head ++;
}

int front(){ //查询队首
    if(head == tail){
        cout << "Queue is empty" << endl;
        return -1;
    }
    else return que[head];
}

int main(){
    cout << "也可以通过STL的queue实现队列" << endl;
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << q.back() << q.size() << q.empty() << endl;
}