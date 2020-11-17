#include<iostream>
using namespace std;

/*
    N the number of test locations
    K the number of testee
*/

struct student {
	char id[15];
	int local_rank;
	int score;
	int finalrank;
	int location;
}stu[100000];

bool cmp1(student a,student b) {
	if(a.score!=b.score)
	    return a.score>b.score;
	else return strcmp(a.id,b.id)<0;
}

int main() {
	int n,k,num=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&k);
		for(int j=0;j<k;j++) {
			stu[num].location=i+1;
			scanf("%s %d",stu[num].id,&stu[num].score);
			num++;
		}
	    sort(stu+num-k,stu+num,cmp1);
	    stu[num-k].local_rank=1;
	    for(int j=1;j<num;j++) {
	    	if(stu[num-k+j].score==stu[num-k+j-1].score)
	    	    stu[num-k+j].local_rank=stu[num-k+j-1].local_rank;
	    	else
	    	    stu[num-k+j].local_rank=j+1;
		}
	}
	sort(stu,stu+num,cmp1);
	stu[0].finalrank=1;
	for(int i=1;i<num;i++) {
	    if(stu[i].score==stu[i-1].score)
	        stu[i].finalrank=stu[i-1].finalrank;
	    else
	        stu[i].finalrank=i+1;
	}
	printf("%d\n",num);
	for(int i=0;i<num;i++) {
		if(i!=num-1)
		 printf("%s %d %d %d\n",stu[i].id,stu[i].finalrank,stu[i].location,stu[i].local_rank);
		else
		 printf("%s %d %d %d",stu[i].id,stu[i].finalrank,stu[i].location,stu[i].local_rank);
	}
	return 0;
}