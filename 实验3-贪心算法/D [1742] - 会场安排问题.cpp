#include <bits/stdc++.h>

using namespace std;
struct node {
    int a, b;
} p[10005];
int n;
priority_queue<int, vector<int>, greater<int> > q;
//第二个参数( vector )，是来承载底层数据结构堆的容器
//第三个参数则是一个比较类，less 表示数字大的优先级高，而 greater 表示数字小的优先级高。


//自定义比较函数  -重载
bool cmp(node a, node b) {
    return a.a < b.a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].a >> p[i].b;
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++) {
        if (q.size() && q.top() <= p[i].a)
            q.pop();
        q.push(p[i].b);
    }
    cout << q.size() << endl;
    return 0;
}
