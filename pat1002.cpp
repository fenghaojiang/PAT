#include<iostream>
#include<vector>
using namespace std;
const int maxn=1005;
int main(){
	float a[maxn];
    int num;
    fill(a,a+maxn,0);
	for(int i=0;i<2;i++){
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			int index;
			float n;
			cin>>index>>n;
			a[index]+=n;
		}
	}
	int count=0;
    for(int i=maxn;i>=0;i--){
    	if(a[i]!=0){
    		count++;
		}
	}
	printf("%d",count);
	for(int i=maxn;i>=0;i--){
    	if(a[i]!=0) printf(" %d %.1f",i,a[i]);
	}
}
