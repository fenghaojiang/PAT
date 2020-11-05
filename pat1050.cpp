#include<iostream>

using namespace std;

int main() {
	bool flag[256] = {false};
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s2.length(); i++) {
		flag[s2[i]] = true;
	}
	for(int i = 0; i < s1.length(); i++) {
		if(flag[s1[i]] == false) {
			cout << s1[i];
		}
	}
	return 0;
}
