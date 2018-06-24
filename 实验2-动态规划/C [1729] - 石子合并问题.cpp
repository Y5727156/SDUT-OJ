#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m,max_dp[105][105], min_dp[105][105],sum[105];
int get_sum(int i, int j){
    if(i + j > n)
        return get_sum(i, n - i) + get_sum(1, j - n + i - 1);
    else return sum[i + j] - sum[i - 1];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    for(int j = 1; j < n; ++j)
        for(int i = 1; i <= n; ++i){
            min_dp[i][j] = inf;
            max_dp[i][j] = 0;
            for(int k = 0; k < j; ++k){
                max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] + max_dp[(i + k) % n + 1][j - k - 1] + get_sum(i, j));
                min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] + min_dp[(i + k) % n + 1][j - k - 1] + get_sum(i, j));
            }
        }
    int Max = 0, Min = inf;
    for(int i = 1; i <= n; ++i){
        Max = max(Max, max_dp[i][n - 1]);
        Min = min(Min, min_dp[i][n - 1]);
    }
    printf("%d\n%d\n", Min, Max);
    return 0;
}