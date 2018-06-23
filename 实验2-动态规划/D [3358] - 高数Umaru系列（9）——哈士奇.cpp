#include <stdio.h>
#include <string.h>
int max(int a,int b){
    return a>b?a:b;
}
int dp[1010];
int p[110],m[110];
int main(){
    int n,x,i,j;
    while(~scanf("%d %d",&n,&x)){
        memset(dp,0,sizeof(dp));
        for(i=1; i<=n; i++)
            scanf("%d %d",&p[i],&m[i]);
        for(i=1; i<=n; i++)
            for(j=x; j>=p[i]; j--)
                dp[j]=max(dp[j],dp[j-p[i]]+m[i]);
        printf("%d\n",dp[x]);
    }
    return 0;
}


Sample Input

2 100
50 20
60 40
3 100
20 55
20 35
90 95
1 10
20 50

Sample Output

40
95
0

