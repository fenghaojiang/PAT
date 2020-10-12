#include<iostream>
#include<climits>
using namespace std;

int main() {
	int n, minn = 999999999, maxn = -1;
	scanf("%d", &n);
	string unlocked, locked;
	for(int i = 0; i < n; i++) {
		string t;
		cin >> t;
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int tempIn = h*3600 + m*60 + s;
		if(tempIn < minn) {
			minn = tempIn;
			unlocked = t;
		}
		scanf("%d:%d:%d", &h, &m, &s);
		int tempOut = h*3600 + m*60 + s;
		if(tempOut > maxn) {
			maxn = tempOut;
			locked = t;
		}
	}
	cout << unlocked << " " << locked << endl;
	return 0;
}