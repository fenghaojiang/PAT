#include<iostream>
using namespace std;
/*
	一开始用滑动窗口发现超时了 结果看liuchuo师姐的发现是数学问题。
	将数列中的每个数字读取到temp中，假设我们选取的片段包括temp，且这个片段的首尾指针分别是p、q
	对于p，有i种选择，即1、2、3......i，而对于q，有n-i-1种选择，所以组合形成的首尾片段有i*(n-i-1)种  
	因为每个里面都会出现temp，所以temp引起的总和为temp*i*(n-i+1)
*/
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    double temp;
    for (int i = 1; i <= n; i++) { 
        cin >> temp;//n比较大时多次累加会导致精度误差，建议不要使用double类型进行多次累加的精确计算，而是转为能够精确存储的整型
        sum += (long long)(temp * 1000) * i * (n - i + 1); //把输入的double类型的值扩大1000倍后转为long long整型累
    }
    printf("%.2f", sum / 1000.0);
    return 0;
}
