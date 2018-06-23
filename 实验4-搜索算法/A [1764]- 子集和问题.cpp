#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,c,a[10000],b[10000],d[10000],i,sum=0;
bool pd;

void print(int dep)
{
	int j;
	for (j=1;j<=dep;++j)
	  printf("%d ",d[j]);
	printf("\n");
	return;
}

void dfs(int dep)
{
	int r;
	if (pd==1) return;//因为只需输出一组解，c++又没法结束整个程序，，怕超时到处加判断。。。（我智商低别理我）
	for (r=1;r<=n;++r)
	  if (!b[r]&&c-a[r]>=0)
	  {
	  	if (pd==1) return;
	  	c-=a[r];//用c减去每个数，其实就是几个数之和等于c
	  	d[dep]=a[r];//d是记录数组
	  	b[r]=1;
	  	if (c==0) //如果找到一组解，直接输出，完成任务
	  	{
	  		if (pd==0)
	  		  print(dep);
	  		pd=1;
	  		return;
	  	}
	  	else dfs(dep+1);
	  	if (pd==1) return;
	  	c+=a[r];//回溯一步
	  	b[r]=0;
	  }
}
int main()
{
	scanf("%d%d",&n,&c);
	for (i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if (sum<c)//很重要的剪枝！！如果所有的数加起来都小于c，那么不可能有解。。之前有三组TLE，加了这一步竟然给蒙过了。。
	{
		printf("No Solution!");
		return 0;
	}
	memset(d,0,sizeof(d));
	memset(b,0,sizeof(b));
	pd=0;
	dfs(1);
	if (!pd) printf("No Solution!");
	return 0;
}


Sample Input

15 4

Sample Output

4
gfgg