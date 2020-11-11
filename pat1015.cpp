#include<iostream>
using namespace std;

bool isPrime(int num) {
	if(num <= 1) return false;
	for(int i = 2; i*i <= num; i++) {
		if(num % i == 0) return false;
	}
	return true;
}

int main() {
	int num, radix;
	while(1){
		scanf("%d", &num);
		if(num < 0) break;
		scanf("%d", &radix);
		if(!isPrime(num)) {
			printf("No\n");
			continue;
		}
		int len = 0, arr[100];
		while(num != 0) {
			arr[len] = num%radix;
			num = num / radix;
			len++;
		}
		num = 0;
		for(int i = 0; i < len; i++) {
			num = num*radix + arr[i];
		}
		if(!isPrime(num)) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
	return 0;
}
