#include<cstdio>
using namespace std;

/*start end 每一次变换的开始顺序和结束顺序*/

int main() {
    int cnt;
    scanf("%d", &cnt);
    int start[55], end[55], scan[55];
    for(int i = 1; i < 55; i++) {
        scanf("%d", &scan[i]);
        end[i] = i; // 1-54
    }
    for(int i = 0; i < cnt; i++) {
        for(int j = 1; j < 55; j++) 
            start[j] = end[j];
        for(int k = 1; k < 55; k++) 
            end[scan[k]] = start[k]; //输入的放原有的顺序
    }
    char c[6] = {"SHCDJ"};
    for(int i = 1; i < 55; i++) {
        end[i] = end[i] - 1;
        printf("%c%d", c[end[i]/13], end[i]%13 + 1);
        if(i != 54) printf(" ");
    }
    return 0;
}