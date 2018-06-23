#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL n;
map<LL,LL>mmp;
LL abc(LL x) {
    if(x<4)
        return 1;
    if(mmp.count(x)) //使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。
                      //注意，map中不存在相同元素，所以返回值只能是1或0。
        return mmp[x];
    LL ans=1;
    for(LL i=2; i*i<=x; i++)
        if(!(x%i)) {
            ans+=abc(i);
            if(i!=x/i)
                ans+=abc(x/i);
        }
    return mmp[x]=ans;
}
int main() 
{
    cin>>n;
    cout<<abc(n)<<endl;
    return 0;
}