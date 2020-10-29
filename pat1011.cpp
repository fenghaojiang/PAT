#include<iostream>
using namespace std;

int main() {
	char bet[3] = {'W', 'T', 'L'};
	float result = 1.0;
	for(int i = 0; i < 3; i++) {
		float max = 0.0, temp;
		int maxIndex;
		for(int j = 0; j < 3; j++) {
			scanf("%f",&temp);
			if(temp > max) {
				max = temp;
				maxIndex = j;
			}
		}
		printf("%c ",bet[maxIndex]);
		result *= max;
	}
	printf("%.2f",result*1.3 - 2);
	return 0;
} 
