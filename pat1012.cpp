#include<cstdio>
#include<iostream> 
#include<string> 
#include<algorithm>

using namespace std;

struct student{
	int id,best;           //保存学生的id跟最好科目成绩的下表 
	int score[4],rank[4];  //保存学生的成绩跟4门科目的排名 
}stu[2005];

int flag=-1;
int exist[1000000];

bool cmp1(student a,student b){
	return a.score[flag]>b.score[flag];
}

int main()
{
	int n,m,id;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3;
	}
	
	for(flag=0;flag<4;flag++) {
		sort(stu,stu+n,cmp1);
		stu[0].rank[flag]=1;
		for(int i=1;i<n;i++) {
			stu[i].rank[flag]=i+1;
			if(stu[i].score[flag]==stu[i-1].score[flag]) stu[i].rank[flag]=stu[i-1].rank[flag];
		}
	}
	
	for(int i=0;i<n;i++) {
		exist[stu[i].id]=i+1;
		stu[i].best=0;
		int min=stu[i].rank[0];
		for(int j=1;j<4;j++) {
			if(stu[i].rank[j]<min) {
				min=stu[i].rank[j];
				stu[i].best=j;
			}
		}
	}
	
	char subject[5]="ACME";
	
	for(int i=0;i<m;i++) {
		scanf("%d",&id);
		int temp=exist[id];
		if(temp) {
			int best=stu[temp-1].best;
			printf("%d %c\n",stu[temp-1].rank[best],subject[best]);
		}
		else printf("N/A\n");
	}
	return 0;
}
