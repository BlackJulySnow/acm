#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> PII;
#define pb(s) push_back(s);
#define SZ(s) ((int)s.size());
#define ms(s,x) memset(s, x, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;

int n;
std::vector<LL> e[N];
void solve()
{
    cin >> n;
    std::vector<LL> a(n);
    for (auto& x : a) cin >> x;
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        LL v = a[i];
        while (v > 1) {
            e[i].push_back(v);
            v = sqrtl(v / 2 + 1);
            ans++;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (LL x : e[i - 1]) {
            for (LL v : e[i]) {
                if (x == v) ans--;
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
