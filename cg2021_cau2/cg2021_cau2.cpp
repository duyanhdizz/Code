#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

ll x, k, m;

ll power(ll x, ll n, ll mod) {
	if(n == 0) return 1;
	if(n == 1) return x;
	ll mid = power(x, n / 2, mod);
	mid *= mid;
	mid %= mod;
	if(n % 2 == 1) mid *= x, mid %= mod;
	return mid;
}

int32_t main() {
#define TASKNAME "cg2021_cau2"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> k >> m >> x;
    cout << power(x, k, m);
    return 0;
}
/*
INPUT
5 7 4
OUTPUT
2
*/
