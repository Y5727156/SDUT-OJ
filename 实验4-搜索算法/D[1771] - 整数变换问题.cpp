#include <bits/stdc++.h>
using namespace std;
struct node{
    int cnt, n, flag, p;
};
int n, m;
map<int, node> mp;
queue<node> q;
int main() {
    cin >> n >> m;
    node a = {0, n, 0, -1};
    mp[n] = a;
    q.push(a);
    while (q.size()) {
        a = q.front();
        q.pop();
        if (a.n == m) {
            cout << a.cnt << endl;
            while (~a.p) {
                cout << (a.flag ? 'f' : 'g');
                a = mp[a.p];
            }
            cout << endl;
            break;
        }
        node b = a;
        b.cnt++;
        b.n = a.n * 3;
        b.flag = 1;
        b.p = a.n;
        if (!mp.count(b.n)) {
            mp[b.n] = b;
            q.push(b);
        }
        b = a;
        b.cnt++;
        b.n = a.n / 2;
        b.flag = 0;
        b.p = a.n;
        if (!mp.count(b.n)) {
            mp[b.n] = b;
            q.push(b);
        }
    }
    return 0;
}
