#include <bits/stdc++.h>

using namespace std;
int n;
map<int,int>mm;
int dfs(int x) {
    if(x<4)
        return 1;
    if(mm.count(x)) //使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。
                      //注意，map中不存在相同元素，所以返回值只能是1或0。
        return mm[x];
    int ans=1;
    for(int i=2; i*i<=x; i++)
        if(!(x%i)) {
            ans+=dfs(i);
            if(i!=x/i)
                ans+=dfs(x/i);
        }
    return mm[x]=ans;
}
int main()
{
    cin>>n;
    cout<<dfs(n)<<endl;
    return 0;
}