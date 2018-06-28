#include <bits/stdc++.h>
using namespace std;
int n,c,a[10005],b[10005],x[10005],flag;
void dfs(int s,int sum){
    if(sum>c) return;
    if(sum==c){
        for(int i=0;i<n;i++)
            if(b[i]){
                if(!flag){
                    printf("%d",a[i]);
                    flag=1;
                }else{
                    printf(" %d",a[i]);
                }
            }
        return ;
    }
    for(int i=s;i<n&&!flag;i++){
        if(sum+x[i]>=c){
            b[i]=1;
            dfs(i+1,sum+a[i]);
            b[i]=0;
        }
    }

}
int main(){
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=n-1;i>=0;i--)
        x[i]=a[i]+x[i+1];
    dfs(0,0);
    if(!flag)
        printf("No Solution!\n");
    return 0;
}
