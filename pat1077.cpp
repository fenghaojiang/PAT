#include<iostream>
#include<algorithm>
using namespace std;

/*后缀处理起来麻烦，每输入一个字符串就逆序会比较容易*/
int main() {
	int n;
	scanf("%d\n", &n);
	string ans;
	for(int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);
		int lenTemp = temp.length();
		reverse(temp.begin(), temp.end());
		if(i == 0) {
			ans = temp;
			continue;
		} else {
			int lenans = ans.length();
			int minlen = min(lenTemp, lenans);
			for(int j = 0; j < minlen; j++) {
				if(ans[j] != temp[j]) {
					ans = ans.substr(0, j);
					break;
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	if(ans.length() == 0) ans = "nai";
	cout << ans << endl;
	return 0;
}
