#include<iostream>
using namespace std;

long long gcd(long long a, long long b) {
	return b==0? abs(a): gcd(b, a%b);  //计算最大公约数 
}

int main() {
	long long n, a, b, suma = 0, sumb = 1, gcdvalue;
	scanf("%lld",&n);
	for(int i = 0; i < n; i++) {
		scanf("%lld/%lld",&a,&b);
		gcdvalue = gcd(a, b);
		a = a / gcdvalue; //约分 
		b = b / gcdvalue;
		suma = a * sumb + suma * b;
		sumb = sumb * b;
		gcdvalue = gcd(suma, sumb);
		suma = suma / gcdvalue;
		sumb = sumb / gcdvalue; 
	} 
	long long integer = suma / sumb;
	suma = suma - (sumb * integer);
	if(integer != 0) {
		printf("%lld",integer);
		if(suma != 0) {
			printf(" ");
		}
	}
	if(suma != 0) {
		printf("%lld/%lld", suma, sumb);
	}
	if(integer == 0 && suma == 0) {
		printf("0");
	}
	return 0;
} 
