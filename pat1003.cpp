#include<iostream>
#include<cstdio>
using namespace std;
int dist[501], weight[501], num[501], road[501][501], way[501];/*way为到城市i途中总共的救援队  num[i]：从出发点到i结点最短路径的条数*/
bool visit[501];
const int maxint = 999999999;

int main()
{
	int citynum, roadnum, city1, city2, c1, c2, r;
	scanf("%d%d%d%d", &citynum, &roadnum, &c1, &c2);
	for (int i = 0; i < citynum; i++)
	{
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
			road[i][j] = maxint;
	}
	for (int i = 0; i < roadnum; i++)
	{
		scanf("%d%d%d", &city1, &city2, &r);
		road[city2][city1] = road[city1][city2] = r;   /*无向图*/
	}
	for (int i = 0; i < 501; i++)
	{
		dist[i] = maxint;
	}
	dist[c1] = 0; way[c1] = weight[c1];
	num[c1] = 1;
	for (int i = 0; i < citynum; i++)
	{
		int pre=-1; int min = maxint;
		for (int j = 0; j < citynum; j++)
		{
			if (!visit[j] && dist[j] < min)
			{
				pre = j;
				min = dist[j];
			}
		}
		if (pre == -1) break;
		visit[pre] = true;
		for (int v = 0; v < citynum; v++)
		{
			if (!visit[v] && road[pre][v] != maxint)
				if (road[pre][v] + dist[pre] < dist[v])
				{
					dist[v] = road[pre][v] + dist[pre];
					num[v] = num[pre];
					way[v] = way[pre] + weight[v];
				}
				else if (road[pre][v] + dist[pre] == dist[v])
				{
					num[v] = num[pre] + num[v];
					if(way[pre]+weight[v]>way[v])
						way[v] = way[pre] + weight[v];
				}
		}
	}
	printf("%d %d", num[c2], way[c2]);
	return 0;
}
