/*
使用链表实现创建进程和释放进程的内存状态管理。
输入格式：
第一行为初始内存大小，例如： 100 (M)
其它行为具体操作 (0 1 10: 操作0 创建1进程 10M空间 ; 1 1: 删除 1进程 内存释放）申请的进程若找不到空闲可用内存块，则输出out of memory.

输出格式：
每一个操作后打印当前内存块链表。

输入样例：
100
0 1 10
0 2 15
1 1
输出样例：

初始内存大小 = 100
(rem_mem: 90)
-> (mem_size:10, is_use:1, node idx:1)
(rem_mem: 75)
-> (mem_size:15, is_use:1, node_idx:2)
->(mem_size:10, is_use:1, node_idx:1)
(rem_mem: 75)
->(mem_size:15, is_use:1, node_idx:2)
->(mem_size:10, is_use:0, node_idx:1)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int mem_size;
    int is_use;
    int node_idx;
    struct Node* next;
} Node;

Node* head = NULL;
int rem_mem;

Node* createNode(int mem_size, int is_use, int node_idx) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->mem_size = mem_size;
    newNode->is_use = is_use;
    newNode->node_idx = node_idx;
    newNode->next = NULL;
    return newNode;
}

void insertNode(int mem_size, int is_use, int node_idx) {
    Node* newNode = createNode(mem_size, is_use, node_idx);
    newNode->next = head;
    head = newNode;
}

void deleteNode(int node_idx) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->node_idx == node_idx) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->node_idx != node_idx) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList() {
    Node* node = head;
    printf("(rem_mem: %d)\n", rem_mem);
    while (node != NULL) {
        printf("-> (mem_size:%d, is_use:%d, node_idx:%d)\n", node->mem_size, node->is_use, node->node_idx);
        node = node->next;
    }
}

int main() {
    int operation, process, size;
    scanf("%d", &rem_mem);
    while (scanf("%d %d", &operation, &process) == 2) {
        if (operation == 0) {
            scanf("%d", &size);
            if (size > rem_mem) {
                printf("out of memory.\n");
                continue;
            }
            rem_mem -= size;
            insertNode(size, 1, process);
        } else if (operation == 1) {
            deleteNode(process);
            rem_mem += size;
        }
        printList();
    }
    return 0;
}