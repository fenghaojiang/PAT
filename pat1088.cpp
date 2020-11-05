#include<iostream>
using namespace std;

long gcd(long a, long b) {
	return b == 0? abs(a) : gcd(b, a%b);
}

int main() {
	long a1, b1, a2, b2;
	scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
	gcd1 = gcd(a1, b1);
	gcd2 = gcd(a2, b2);
	if(gcd1 != 1) {
		a1 /= gcd1;
		b1 /= gcd1;
	}
	if(gcd2 != 1) {
		a2 /= gcd2;
		b2 /= gcd2;
	}
	int num1 , num2;
	if(b1 == 1) {
		
	}
	return 0;
}
