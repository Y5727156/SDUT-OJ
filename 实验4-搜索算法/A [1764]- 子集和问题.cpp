#include  <bits/stdc++.h>
using namespace std;
int n,c,a[20000],b[20000],x[20000],flag;
void dfs(int s,int sum)
{
	if(sum>c)
        return;
	if(sum==c){
		for(int i=0;i<n;i++)
		if(b[i]){
			if(!flag){
				printf("%d",a[i]);
				flag=1;
			}
			else
			printf(" %d",a[i]);
		}
		return;
	}
	for(int i=s;i<n&&!flag;i++)
	if(sum+x[i]>=c){
		b[i]=1;
		dfs(i+1,sum+a[i]);
		b[i]=0;
	}
}
int main()
{
	cin>>n>>c;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=n-1;i>=0;i--)
		x[i]=a[i]+x[i+1];
	dfs(0,0);
	if(!flag)
		printf("No Solution!");
	return 0;
}


Sample Input

15 4

Sample Output

4
gfgg