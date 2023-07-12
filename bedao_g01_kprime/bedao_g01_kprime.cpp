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
const int N = 9 + 1e7;
const int INF = 1e9;

int n, k;
bool prime[N];

void sang() {
	fill(prime, prime + N, true);
	prime[0] = prime[1] = false;
	for(int i = 2; i <= N; i++)
		if(prime[i])
			for(int j = 2 * i; j <= N; j += i) prime[j] = false;
}

int32_t main() {
#define TASKNAME "bedao_g01_kprime"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sang();
	cin >> n >> k;
	ll res = 0;
	int lo = 1, hi = 0, ans = 0;
	while(lo <= n) {
		while(hi <= n && ans < k) {
			hi++;
			if(prime[hi] == true) ans++;
		}
		if(hi > n) break;
		res += (n - hi + 1);
		ans -= prime[lo];
		lo++;
	}
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
8 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
20
------------------------------    |
==================================+
*/
