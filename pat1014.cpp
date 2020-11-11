#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/* 设立结构体 里面包含poptime为队首的人出队(结束)的时间，和endtime为队尾的人结束的时间
    poptime是为了方便计算那个一个队列先空出人来(poptime最小的那个先有人服务完毕) 
    endtime是为了了入队后加上⾃自⼰己本身的服务所需时间可以计算出自己多久才能被服务完
    前一个人的endtime可以得知自己是不是需要被Sorry  
    如果前一个人服务结束时间超过17:00，自己当前入队的人就是sorry*/
struct node {
    int poptime, endtime;
    queue<int> q; //所有当前该窗口的排队队列
};

/*N (≤20, number of windows)
  M (≤10, the maximum capacity of each line inside the yellow line), 
  K (≤1000, number of customers)
  Q (≤1000, number of customer queries)*/

int main() {
    int n, m, k, q, index = 1;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    vector<int> time(k+1), result(k+1);
    for(int i = 1; i <= k; i++) {
        scanf("%d",&time[i]);
    }

    vector<node> window(n + 1);
    vector<bool> sorry(k + 1, false);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++) {
            if(index <= k) {
                window[j].q.push(time[index]);//排队
                if(window[j].endtime >= 540)
                    sorry[index] = true;
                window[j].endtime += time[index];
                if(i == 1)
                    window[j].poptime = window[j].endtime;
                result[index] = window[j].endtime;
                index++;
            }
        }
    }
    while(index <= k) { //等候线外
        int tempmin = window[1].poptime, tempwindow = 1;
        for (int i = 2; i <= n; i++) {
            if(window[i].poptime < tempmin) {
                tempwindow = i;
                tempmin = window[i].poptime;
            }
        }
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]); //等候线进入排队
        window[tempwindow].poptime += window[tempwindow].q.front(); //等待时间加上队头处理时间
        if(window[tempwindow].endtime >= 540) {
            sorry[index] = true;
        }
        window[tempwindow].endtime += time[index];
        result[index] = window[tempwindow].endtime;
        index++;
    }

    for(int i = 1; i <= q; i++) {
        int query, minute;
        scanf("%d", &query);
        minute = result[query];
        if(sorry[query] == true) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", (minute + 480) / 60, (minute + 480) %60);
        }
    }
    return 0;
}
