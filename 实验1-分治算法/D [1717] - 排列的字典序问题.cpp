#include <bits/stdc++.h>
using namespace std;
int a[22],n,ans,x[22],num;
int main() {
    x[0]=1;
    for(int i=1; i<=20; i++)
        x[i]=x[i-1]*i;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++)
            if(a[j]<a[i])
                num++;
        ans+=x[n-1-i]*num,num=0;
    }
    next_permutation(a,a+n);
    cout<<ans<<endl;
    for(int i=0; i<n; i++)
        printf("%d%c",a[i],i<n-1?' ':'\n');
    return 0;
}


Sample Input

8
2 6 4 5 8 1 7 3

Sample Output

8227
2 6 4 5 8 3 1 7

