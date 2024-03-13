#include <stdio.h>
#include <math.h>
#include <stdlib.h>
char* array(){
    char* a;
    a = (char*)malloc(sizeof(char)*25*2500);
    for(int i=0; ;i++){
        a[i] = getchar();
        if(a[i] == '\n')
            i--;
        if(a[i] == 'E')
            break;
    }
    return a;
}

int main(){
    char* a = array();
    int a11=0, b11=0, a21=0, b21=0;
    for(int i=0; ;i++){
        if(a[i] == 'W')
            a11++;
        if(a[i] == 'L')
            b11++;
        if(((a11 > 10 || b11 > 10) && abs(a11-b11)>1) || a[i] == 'E'){
            printf("%d:%d\n", a11, b11);
            a11 = 0;
            b11 = 0;
        }
        if(a[i] == 'E')
            break;
    }
    printf("\n");

    for(int i=0; ;i++){
        if(a[i] == 'W')
            a21++;
        if(a[i] == 'L')
            b21++;
        if(((a21 > 20 || b21 > 20) && abs(a21-b21)>1) || a[i] == 'E'){
            printf("%d:%d\n", a21, b21);
            a21 = 0;
            b21 = 0;
        }
        if(a[i] == 'E')
            break;
    }
    
    return 0;
}
