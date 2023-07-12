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
const int N = 9 + 5e6;
const int INF = 1e9;

int t, pre[N];
bool prime[N];

void sang() {
	fill(prime, prime + N, true);
	for(int i = 2; i <= N; i++) {
		if(prime[i] == true) {
			pre[i] += i;
			for(int j = 2 * i; j <= N; j += i) prime[j] = false;
		}
		pre[i] += pre[i - 1];
	}
}

void solve() {
	int a, b;
	cin >> a >> b;
	cout << pre[b] - pre[a - 1] << '\n';
}

int32_t main() {
#define TASKNAME "CDQU1"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sang();
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
INPUT
OUTPUT
*/
