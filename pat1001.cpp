#include<iostream>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	string result = to_string(a+b);
	int len=result.length();
	for(int i=0;i<len;i++){
		cout<<result[i];
		if(result[i]=='-') continue;
		if((i+1)%3==len%3&&i!=len-1) cout<<",";
	}
	return 0;
} 
