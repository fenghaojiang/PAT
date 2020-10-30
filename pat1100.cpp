#include<iostream>
#include<map>
using namespace std;



int main() {
	int n;
	cin >> n;
	getchar();
	string temp;
	string low[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string high[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	map<string, int> lowM, highM;
	for(int i = 0; i < 13; i++) {
		lowM[low[i]] = i;
		highM[high[i]] = i;
	}
	int num;
	for(int i = 0; i < n; i++) {
		getline(cin, temp);
		if(isdigit(temp[0])) {
			num = stoi(temp);
			if(num / 13 == 0) {
				cout << low[num%13] << endl;
			} else if(num % 13 != 0){
				cout << high[num / 13] << " " << low[num % 13] << endl;
			} else {
				cout << high[num / 13] << endl;
			}
		} else {
			if(temp.length() > 4) {
				num = highM[temp.substr(0,3)]*13 + lowM[temp.substr(4,3)];
				cout << num << endl;
			} else {
				if(highM[temp] != 0) {
					cout << highM[temp]*13 << endl;
				} else cout << lowM[temp] << endl;
			}
		}
	}
	return 0;
} 
