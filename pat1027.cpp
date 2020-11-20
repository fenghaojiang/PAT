#include<iostream>
using namespace std;

int main() {
    char c[14] = {"0123456789ABC"};
    printf("#");
    int num;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
    return 0;
}