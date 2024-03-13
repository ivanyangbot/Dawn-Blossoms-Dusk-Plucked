#include <stdio.h>
#include <stdlib.h>
 
struct NUM{
    int data;
    struct NUM *next;
};
 
struct NUM* create_list(struct NUM* current, int* num_count) {
    int num;
    while (scanf("%d", &num) == 1 && num != -1) {
        struct NUM *newnode = (struct NUM *)malloc(sizeof(struct NUM));
        newnode->data = num;
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
        (*num_count)++;
    }
    struct NUM *last = (struct NUM *)malloc(sizeof(struct NUM));
    last->next = NULL;
    last->data = -1;
    current->next = last;
    return current;
}

int main() 
{
    int num, num_B = 0, num_A = 0;
    struct NUM *headA, *headB, *currentA, *currentB;

    headA = (struct NUM *)malloc(sizeof(struct NUM));
    headA->next = NULL;
    headA->data = 0;
    currentA = headA;

    headB = (struct NUM *)malloc(sizeof(struct NUM));
    headB->next = NULL;
    headB->data = 0;
    currentB = headB;

    currentA = create_list(currentA, &num_A);
    currentB = create_list(currentB, &num_B);
 
    struct NUM *previousB = headB;
    struct NUM *previousA = headA;
    currentA = previousA->next;
    currentB = previousB->next;

    int searchingB = currentB->data,storageNUMB = num_B;
    
    for (int i = 0; i < storageNUMB; ++i) {
        while ((currentA->data) < searchingB && currentA->data != -1){
            currentA = currentA->next;
            previousA = previousA->next;
        }
        if (currentA->data == searchingB && currentA->data != -1){
            previousB = previousB->next;
            currentB = currentB->next;
            currentA = currentA->next;
            previousA = previousA->next;
            searchingB = currentB->data;
        } else {
            previousB->next = currentB->next;
            previousA->next = currentB;
            currentB->next = currentA;
            previousA = currentB;
            currentB = previousB->next;
            searchingB = currentB->data;
            num_B--;
            num_A++;
        }
    }
 
    struct NUM *printA = headA->next;
    struct NUM *printB = headB->next;
    if (printA->data == -1){
        printf("There is no item in A list.\n");
    } else {
        printf("The new list A:");
        for (int i = 1; i < num_A; i++) {
            printf("%d ",printA->data);
            printA = printA->next;
        }
        printf("%d\n",printA->data);
    }
    if (printB->data == -1){
        printf("There is no item in B list.\n");
    } else {
        printf("The new list B:");
        for (int i = 1; i < num_B; i++) {
            printf("%d ",printB->data);
            printB = printB->next;
        }
        printf("%d\n",printB->data);
    }
    system("pause");
    return 0;
}