#include<iostream>
using namespace std;

int main(){
	float a[1005]={0.0};
	float b[2005]={0.0};
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int index;
		float value;
		scanf("%d %f",&index, &value);
		a[index] = value;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		int index;
		float value;
		scanf("%d %f",&index, &value);
		for(int j = 0; j < 1005; j++) {
			if(a[j] != 0.0) {
				b[index+j] += a[j]*value;
			}
		}
	}
	int cnt=0;
	for(int i = 2004; i >= 0; i--) {
		if(b[i] != 0) {
			cnt++;
		}
	}
	printf("%d",cnt);
	for(int i = 2004; i >= 0; i--) {
		if(b[i] != 0) {
			printf(" %d %.1f",i, b[i]);
		}
	}
	return 0;
}
