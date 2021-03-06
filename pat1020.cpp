#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=50;
int pre[maxn],in[maxn],post[maxn];
int n;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* create(int postL,int postR,int inL,int inR){
	if(postL>postR) return NULL;
	node* root=new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR])
		 break;
	}
	int numleft=k-inL;
	root->lchild=create(postL,postL+numleft-1,inL,k-1);
	root->rchild=create(postL+numleft,postR-1,k+1,inR);
	return root; 
}

void bfs(node* root){
	node* now=root;
	queue<node*> q;
	q.push(root);
	int num=0;
	while(!q.empty()){
		now=q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n) printf(" ");
		if(now->lchild!=NULL) q.push(now->lchild); //先进先出
		if(now->rchild!=NULL) q.push(now->rchild);
    }
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]); //后序
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]); //中序
	}
	node* root=create(0,n-1,0,n-1);
	bfs(root);
	return 0;
}