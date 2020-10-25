#include<iostream>
using namespace std;

int main() {
	const string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven","eight", "nine"};
	string n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n.length(); i++) {
		sum += n[i] - '0';
	}
	string result = to_string(sum);
	for(int i = 0; i < result.length(); i++) {
		cout << nums[(result[i]-'0')];
		if(i != result.length() - 1) cout << " ";
	}
	return 0;
}
