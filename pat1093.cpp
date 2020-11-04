#include<iostream>
#include<string>
using namespace std;

/*
要想知道构成多少个PAT，那么遍历字符串串后对于每?一A
，它前?面的P的个数和它后?面的T的个数 的乘积就是能构成的PAT的个数
*/

int main() {
	string s;
	cin >> s;
	int len = s.length(), result = 0, countp = 0, countt = 0;
	for(int i = 0; i < len; i++) {
		if(s[i] == 'T') {
			countt++;
		}
	}
	for(int i = 0; i < len; i++) {
		if(s[i] == 'P') countp++;
		if(s[i] == 'T') countt--;
		if(s[i] == 'A') result = (result + (countp * countt)%1000000007) % 1000000007;
	}
	cout << result;
	return 0;
}
