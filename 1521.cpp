#include <iostream>
#include <stdio.h>
#define maxn 100001

using namespace std;
int bit[maxn],n,k;

int low_bit(int i)
{
    return i&(-i);
}

int sum(int i)
{
    int sum = 0;
    while(i>0)
    {
        sum += bit[i];
        i -= low_bit(i);
    }
    return sum;
}

void add(int i, int val)
{
    while (i <= n)
    {
        bit[i] += val;
        i += low_bit(i);
    }
}

int BinSearch(int x, int n)
{
    int l = 1, r = n;
    while (l<=r)
    {
        int m = (l+r)/2;
        int tmp = sum(m);
        if (tmp < x) l = m + 1;
        else r = m - 1;
    }
    cout << l << " ";
    return l;
}

int main()
{
    cin >> n >> k;
    memset(bit,0,sizeof(bit));
    for (int i = 1; i <= n; ++i)
        add(i,1);
    int curr = 1, res = n;
    for (int i = 1; i <= n; ++i)
    {
        curr = (curr + k - 1) % res;
        if (curr == 0) curr = res;
        int tmp = BinSearch(curr,n);
        add(tmp,-1);
        --res;
    }
    return 0;
}
