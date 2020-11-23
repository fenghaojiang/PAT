#include<cstdio>
#include<string.h>

/*
    n2 >= n1
    n1 == n3
    n1在上述条件下取最大值
*/
int main() {
    char u[40][40],c[81];
    memset(u, ' ', sizeof(u)); 
    scanf("%s",c);
    int n = strlen(c) + 2; // 算上重复的部分
    int n1 = n/3;
    int n2 = n/3 + n%3;
    int index = 0;
    for(int i = 0; i < n1; i++) u[i][0] = c[index++]; //第一列
    for(int i = 1; i < n2 - 1; i++) u[n1-1][i] = c[index++]; //最后一行
    for(int i = n1-1; i >= 0; i--) u[i][n2-1]=c[index++];//最后一列
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) printf("%c",u[i][j]);
        printf("\n");
    }
    return 0;
}
