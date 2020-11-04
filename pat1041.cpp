#include<iostream>

using namespace std;
int cnt[10005];
int a[10005];


int main() {
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	int i;
	for(i = 0; i < n; i++) {
		if(cnt[a[i]] == 1) {
			printf("%d", a[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}
