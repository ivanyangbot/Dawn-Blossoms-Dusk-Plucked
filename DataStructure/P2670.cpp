#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    int arr[row+2][col+2];
    memset(arr, 0, sizeof(arr));
    getchar();
    for(int i=1; i<row+1; i++){
        for(int j=1; j<col+1; j++){
            scanf("%c", &arr[i][j]);
            if(arr[i][j] == '*')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
        getchar();
    }
    int check[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i+1][j+1] == 1)
                check[i][j] = -1;
            else
                check[i][j] = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j] + arr[i+1][j+2] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(check[i][j] == -1)
                printf("*");
            else
                printf("%d", check[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}