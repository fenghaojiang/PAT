#include<cstdio>
#include<algorithm>

using namespace std;
bool visit[1005];
int road[1005][1005];
int n,m,k;

void dfs(int node) {
	visit[node]=true;
	for(int i=1;i<=n;i++) {
		if(visit[i]==false&&road[node][i]==1)
		dfs(i);
	}
}

int main() {
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++) {
		int city1,city2;
		scanf("%d %d",&city1,&city2);
		road[city1][city2]=road[city2][city1]=1;
	}
	for(int i=0;i<k;i++) {
		fill(visit,visit+1005,false);
		int city;
		scanf("%d",&city);
		visit[city]=true;
		int cnt=0;
		for(int j=1;j<=n;j++) {
			if(visit[j]==false) {
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}