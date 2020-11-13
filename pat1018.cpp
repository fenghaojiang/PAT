#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 510;
const int inf = 999999999;
int G[maxn][maxn], d[maxn], weight[maxn], minneed=inf, minback=inf;
int cmax, n, index, m;
bool visit[maxn] = { false };
vector<int> temppath, path;
vector<int> pre[maxn];

void dfs(int v) {
	if (v == 0) {
		temppath.push_back(v);
		int need = 0,back = 0;
		for (int i = temppath.size() - 1; i >= 0; i--) {
			int id = temppath[i];
			if (weight[id]>0) {
				back += weight[id];
			}
			else {
				if (back > (0 - weight[id])) {
					back += weight[id];
				}
				else{
					need += (0-weight[id])-back;
					back = 0;
				}
			}
		}
		if (need < minneed) {
			minneed = need;
			minback = back;
			path = temppath;
		}
		else if (need == minneed && back < minback) {
				minback = back;
				path = temppath;
		}
		temppath.pop_back();
	    return ;
	}
	temppath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}

void dijkstra(int s) {
	d[s]=0;
	for (int i = 0; i <= n; i++) {
		int u = -1, min = inf;
		for (int j = 0; j <= n; j++) {
			if (visit[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return ;
		visit[u] = true;
		for (int v = 0; v <= n; v++) {
			if (visit[v] == false && G[u][v] != inf) {
				if (d[v] > G[u][v] + d[u]) {
					d[v] = G[u][v] + d[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[v] == G[u][v] + d[u]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

int main() {
	fill(G[0], G[0] + maxn * maxn, inf);
	fill(d, d + maxn, inf);
	scanf("%d%d%d%d%", &cmax, &n, &index, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
		weight[i] = weight[i]-cmax/2;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	dijkstra(0);
	dfs(index);
	printf("%d 0",minneed);
	for (int i = path.size() - 2; i >= 0; i--) {
		printf("->%d", path[i]);
	}
	printf(" %d", minback);
	return 0;
}
