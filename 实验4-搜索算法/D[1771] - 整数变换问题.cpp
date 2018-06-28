#include <bits/stdc++.h>
using namespace std;
struct node 
{
int s, x, f, p;
};
int n, m;
map<int, node> mmp;
queue<node> q;
int main() {
    cin >> n >> m;
    node a = {0, n, 0, -1};
    mmp[n] = a;
    q.push(a);
    while (q.size()) {
        node a = q.front();
        q.pop();
        if (a.x == m) {
            cout << a.s << endl;
            while (~a.p) {
                cout << (a.f ? 'f' : 'g');
                a = mmp[a.p];
            }
            cout << endl;
            break;
        }
        node b = a;
        b.s++, b.x = a.x * 3, b.f = 1, b.p = a.x;
        if (!mmp.count(b.x)) {
            mmp[b.x] = b;
            q.push(b);
        }
        b = a;
        b.s++, b.x = a.x / 2, b.f = 0, b.p = a.x;
        if (!mmp.count(b.x)) {
            mmp[b.x] = b;
            q.push(b);
        }
    }
    return 0;
}