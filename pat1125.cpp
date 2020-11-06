#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


/*思路：越早加入绳子，对折次数越多，贪心算法，长的尽量放在后面*/

int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int result = v[0];
	for(int i = 1; i < n; i++) {
		result = (result + v[i]) / 2;
	}
	printf("%d\n",result);
	return 0;
}

