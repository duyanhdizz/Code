#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 9 + 1e6;
const int INF = 1e9;

ll a, b, c, cntdiv[N];

void phantich(ll n) {
    for(ll i = 2; i <= sqrt(n) && n > 1; i++) {
        while(n % i == 0) {
            cntdiv[i]++;
            n /= i ;
        }
    }
    if(n > 1) cntdiv[n]++;
}

ll power(ll x, ll n) {
    if(n == 0) return 1;
    if(n == 1) return x;
    ll tg = power(x, n / 2);
    tg *= tg;
    if(n % 2 == 1) tg *= x;
    return tg;
}

int32_t main() {
#define TASKNAME "tht21_tphcm_slc_square"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> a >> b >> c;
    phantich(a);
    phantich(b);
    phantich(c);
    ll res = 1;
    for(ll i = 2; i < N; i++)
        if(cntdiv[i] > 0)
            res *= power(i, (cntdiv[i] + 1) / 2);
    cout << res;
    return 0;
}
