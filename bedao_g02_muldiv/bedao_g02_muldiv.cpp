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
const int MOD = 998244353;

int t;

void solve() {
	int n;
	cin >> n;
	ll ans = 1;
	for(int i = 1; i * i < n; i++) {
		if(n % i == 0) {
			ans *= i;
			ans %= MOD;
			if(i * i != n) {
				ans *= (n / i);
				ans %= MOD;
			}
		}
	}
	if(int(sqrt(n)) == sqrt(n)) ans = ans * (int)(sqrt(n)) % MOD;
	cout << ans << '\n';
}

int32_t main() {
#define TASKNAME "bedao_g02_muldiv"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
INPUT
3
5
10
2986178
OUTPUT
5
100
856178939
*/
