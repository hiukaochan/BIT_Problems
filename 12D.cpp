#include <iostream>
#include <algorithm>
#include <map>
#define maxn 500001
 
using namespace std;
 
map <int, int> m;
int n,bit_max[maxn];
 
struct lady {
    int b, i, r;
}ld[maxn];
 
bool compi(lady a, lady b)
{
    return (a.i > b.i);
}
 
bool compb(lady a, lady b)
{
    return (a.b > b.b || (a.b == b.b && a.i > b.i));
}
 
int low_bit(int i)
{
    return i&(-i);
}
 
void add(int id, int val)
{
    while (id <= n)
    {
        bit_max[id] = max(bit_max[id],val);
        id += low_bit(id);
    }
}
 
int sum(int id)
{
    int sum = 0;
    while (id > 0){
        sum = max(sum,bit_max[id]);
        id -= low_bit(id);
    }
    return sum;
}
 
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) scanf("%d",&ld[i].b);
    for (int i = 1; i <= n; ++i) scanf("%d",&ld[i].i);
    for (int i = 1; i <= n; ++i) scanf("%d",&ld[i].r);
    sort(ld+1,ld+1+n,compi);
    int k = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (m[ld[i].i] == 0) m[ld[i].i] = k++;
        ld[i].i = m[ld[i].i];
    }
    sort(ld+1,ld+1+n,compb);
    int ans = 0;
    for (int i = 1; i <= n ; ++i)
    {
        if (sum(ld[i].i-1) > ld[i].r) ans++;
        add(ld[i].i,ld[i].r);
    }
     printf("%d\n",ans);
}
