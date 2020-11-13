#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
	二分
	首先将数列从小到达排序，设当前结果为result = 0 当前最长长度temp = 0；
	从i = 0~n	j从i+result到n(因为是找最大的result，下一次j只要从i的result个后面开始找)
	不断更新result最大值
	题目没说要连续，我佛了，想了半天
*/

int main() {
	int num;
	long long p;
	scanf("%d%lld", &num, &p);
	vector<int> v(num);
	for(int i = 0; i < num; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int result = 0, temp = 0;
	for(int i = 0; i < num; i++) {
		for(int j = i + result; j < num; j++) {
			if(v[j] <= v[i]*p) {
				temp = j - i + 1;
				if(temp > result) 
					result = temp;
			} else {
				break;
			}
		}
	}
	printf("%d", result);
	return 0;
} 
