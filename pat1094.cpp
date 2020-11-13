#include<iostream>
#include<vector>
using namespace std;


/*
    N-- Total number of family members
    M the members who have children
    ID K ID[1] ID[2] ... ID[K]
    ID is a two-digit number representing a family member
    K is the number of his children
    Root is 01

    Output:  
    the largest population number and the level of the corresponding generation
*/

vector<int> v[100];
int book[100];
void dfs(int index, int level) { //真的牛皮，bfs与dfs结合了
    book[level]++;
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], level+1);
}

int main() {
    int n, m, a, k, c;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);
        }
    }
    dfs(1,1);
    int maxnum = 0, maxlevel = 1;
    for(int i = 1; i < 100; i++) {
        if(book[i] > maxnum) {
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d\n",maxnum, maxlevel);
    return 0;
}