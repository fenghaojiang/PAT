#include<iostream>
#include<map>
using namespace std;

int main() {
	int m, n, s;
	scanf("%d %d %d",&m, &n, &s);
	map<string, int> candidate;
	string str;
	bool flag = false;
	for(int i = 1; i <= m; i++) {
		cin >> str;
		if(candidate[str] == 1) s = s + 1; //抽中过，下一位
		if(i == s && candidate[str] == 0) {
			candidate[str] = 1;
			cout << str << endl;
			flag = true;
			s = s + n; //下n位
		}
	}
	if(flag == false) cout << "Keep going..." << endl;
	return 0;
}

