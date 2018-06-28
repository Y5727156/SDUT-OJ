#include <bits/stdc++.h>

using namespace std;
int n,k,a[10005],ans,x;
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    ans=1;
    x=a[0]+k;
    for(int i=1;i<n;i++)
        if(x<a[i])
            x=a[i]+k,ans++;
    printf("%d\n",ans);
    return 0;
}
