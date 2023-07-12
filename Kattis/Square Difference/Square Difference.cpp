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

int t;

bool check(ll n) {
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

void solve() {
	ll a, b;
	cin >> a >> b;
	if(a == (b + 1)) {
		if(check(a + b) == true) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	} else cout << "NO" << '\n';
}

int32_t main() {
#define TASKNAME "Square Difference"
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
4
6 5
16 13
61690850361 24777622630
34 33
OUTPUT
YES
NO
NO
YES
*/
