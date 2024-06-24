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
