#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//字符串操作 经典排序

bool cmp1(string a, string b) {
	return a+b < b+a;
}

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp1);
	string final = "";
	for(int i = 0; i < n; i++) {
		final += v[i];
	} 
	while(final.length() != 0 && final[0] == '0') {
		final.erase(final.begin());
	}
	if(final.length() == 0) cout << 0;
	cout << final << endl;
	return 0;
}
