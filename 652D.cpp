#include <bits/stdc++.h>
#define maxn 200001
 
using namespace std;
 
int bit_sum[maxn], ans[maxn];
 
struct pii {
    int x, y, id;
} a[maxn];
 
bool cmp_y(pii a, pii b) {
    return (a.y < b.y);
}
 
bool cmp_x(pii a, pii b) {
    return (a.x > b.x || (a.x == b.x && a.y < b.y));
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
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp_y);
    for (int i = 1; i <= n; ++i)
    {
        a[i].y = i;
    }
    sort(a+1,a+1+n,cmp_x);
    for (int i = 1; i <= n; ++i)
    {
        ans[a[i].id] = sum(a[i].y);
        add(a[i].y,n);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";
    return 0;
}
