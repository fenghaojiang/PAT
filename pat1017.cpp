#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
    N -- total number of customers
    K -- number of windows
 */

struct node {
    int arriveTime;
    int processTime;
};

bool cmp(node a, node b) {
    return a.arriveTime < b.arriveTime;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<node> v;
    int tempHour, tempMin, tempSec, processTime;
    for(int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &tempHour, &tempMin, &tempSec, &processTime);
        int tempTime = tempHour*3600 + tempMin*60 + tempSec;
        if(tempTime > 61200) continue; //超过5点不服务
        v.push_back(node{tempTime, processTime*60});
    }
    sort(v.begin(), v.end(), cmp);
    double totalWaitTime = 0.0;
    vector<int> window(k, 28800);
    for(int i = 0; i < v.size(); i++) {
        int tempIndex = 0, minFinish = window[0];
        for(int j = 1; j < k; j++) {
            if(minFinish > window[j]) {
                minFinish = window[j]; //每次都要找出最快的窗口emmm
                tempIndex = j;
            }
        }
        if(window[tempIndex] <= v[i].arriveTime) {
            window[tempIndex] = v[i].arriveTime + v[i].processTime; //加上排队时间
        } else {
            totalWaitTime += window[tempIndex] - v[i].arriveTime; //如果到达时仍在处理，那么就要减去到达时间作为等待时间
            window[tempIndex] += v[i].processTime;
        }
    }
    if(v.size() == 0) printf("0.0\n");
    else printf("%.1f", totalWaitTime / 60.0 / v.size());
    return 0;
}
