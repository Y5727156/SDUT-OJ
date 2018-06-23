#include <bits/stdc++.h>
using namespace std;
int dp[101][101],n,m;
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= i; ++j)
            scanf("%d",&dp[i][j]);
    for(int i = n-2; i >= 0; --i){
        for(int j = i; j >= 0; --j){
            dp[i][j] = max(dp[i][j] + dp[i+1][j],dp[i][j] + dp[i+1][j+1]);
        }
    }
    printf("%d\n",dp[0][0]);
    return 0;
}


Sample Input

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

Sample Output

30

