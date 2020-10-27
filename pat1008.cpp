#include<iostream>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int cur = 0, next, time = 0;
	for(int i = 0; i < n; i++) {
		cin >> next;
		if(next > cur){
			time += (next-cur)*6;
		} else {
			time +=(cur-next)*4;
		}
		cur = next;
		time+=5;
	}
	cout << time << endl;
	return 0;
}
