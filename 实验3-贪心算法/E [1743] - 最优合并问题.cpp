#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int> >q;
priority_queue<int,vector<int>,greater<int> >qx;
int k,ans,t,x,ansx;
int main() {
    scanf("%d",&k);
    while(k--){
        scanf("%d",&x);
        q.push(x);
        qx.push(x);
    }
    while(q.size()>1){
        t=q.top();
        q.pop();
        t+=q.top();
        q.pop();
        ans+=t-1;
        q.push(t);
    }
    while(qx.size()>1){
        t=qx.top();
        qx.pop();
        t+=qx.top();
        qx.pop();
        ansx+=t-1;
        qx.push(t);
    }
    printf("%d %d\n",ans,ansx);
    return 0;
}
