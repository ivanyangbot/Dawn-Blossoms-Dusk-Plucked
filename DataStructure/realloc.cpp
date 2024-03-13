#include <stdio.h>
#include <stdlib.h>
int main(){
    int *list = (int*)malloc(3 * sizeof(int));
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = (int*)realloc(list, 4 * sizeof(int));
    if (tmp == NULL){
        free(list);
        return 1;
    }
    list = tmp;
    list[3] = 4;

    for (int i = 0; i < 4; i++)
        printf("%d\n", list[i]);

}