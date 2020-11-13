#include<iostream>
#include<vector>
using namespace std;

int main() {
	int num, radix;
	scanf("%d%d", &num, &radix);
	vector<int> v;
	int temp = num;
	while(num != 0) {
		v.push_back(num%radix);
		num /= radix;
	}
	bool flag = true;
	for(int i = 0; i < v.size() / 2; i++) {
		if(v[i] != v[v.size()-i-1]) {
			flag = false;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	for(int i = v.size() - 1; i >= 0; i--) {
		printf("%d",v[i]);
		if(i != 0) printf(" ");
	}
	if(temp == 0) printf("0\n");
	return 0;
}
