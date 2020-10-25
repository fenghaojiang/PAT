#include<iostream>
#include<vector>

using namespace std;

int main() {
	int k,leftindex,rightindex,tempindex,maxn,temp;
	scanf("%d",&k);
	vector<int> a(k);
	leftindex=0;rightindex=k-1;maxn=-1;temp=0;
	for(int i=0;i<k;i++) {
	  scanf("%d",&a[i]);
		temp+=a[i];
		if(temp<0) {
			temp=0;
			tempindex=i+1;
		} else if(temp>maxn) {
			maxn=temp;
			leftindex=tempindex;
			rightindex=i;
		}
	}
	if(maxn<0) maxn=0;
	printf("%d %d %d",maxn,a[leftindex],a[rightindex]);
	return 0;
}
