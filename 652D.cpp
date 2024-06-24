/*//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define maxn 200001

using namespace std;

int bit_sum[maxn], ans[maxn];

struct pii {
    int l, r, id;
} a[maxn];

bool cmp_r(pii a, pii b) {
    return (a.r < b.r);
}

bool cmp_x(pii a, pii b) {
    return (a.l > b.l || (a.l == b.l && a.r < b.r));
}

int low_bit(int t) {
    return t&(-t);
}

int sum(int t) {
    int sum = 0;
    while (t > 0){
        sum += bit_sum[t];
        t -= low_bit(t);
    }
    return sum;
}

void add(int t, int n){
    while (t <= n)
    {
        bit_sum[t]++;
        t += low_bit(t);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp_r);
    for (int i = 1; i <= n; ++i)
        a[i].r = i;
    for (int i = 1; i <= n; ++i)
    {
        ans[a[i].id] = sum(a[i].l);
        add(a[i].l,n);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";
    return 0;
}*/

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define maxn 200001
#define maxxy 32001

using namespace std;

int bit_sum[maxn], ans[maxn];

int low_bit(int t) {
    return t&(-t);
}

int sum(int t) {
    int sum = 0;
    while (t > 0){
        sum += bit_sum[t];
        t -= low_bit(t);
    }
    return sum;
}

void add(int t){
    while (t <= maxxy)
    {
        bit_sum[t]++;
        t += low_bit(t);
    }
}

int main()
{
    int n,x,y;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        x++;
        ans[sum(x)]++;
        add(x);
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
    return 0;
}