#include<bits/stdc++.h>

using namespace std;
int p[25][25],q[25][25],n,c[25],ans,vis[25];
void dfs(int x,int tot)
{
    if(x>n){
        ans=max(ans,tot);
        return;
    }
    int op=0;
    for(int i=x;i<=n;i++)
        op+=c[i];
    if(ans>op+tot)
        return;
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=1;
            dfs(x+1,tot+p[x][i]*q[i][x]);
            vis[i]=0;
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>p[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>q[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i]=max(c[i],p[i][j]*q[j][i]);
    dfs(1,0);
    cout<<ans;
    return 0;
}
