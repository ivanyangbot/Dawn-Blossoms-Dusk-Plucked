#include <iostream>

typedef struct node{
    int data;
    struct node *next;
}Node;

// 利用上面的节点创建栈，分为指向头节点的top和计数用的count
typedef struct stack{
    Node *top;
    int count;
}Link_Stack;