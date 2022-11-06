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
bool prime[N];

//AC 10 / 10

void sang() {
	fill(prime, prime + N, true);
	prime[0] = prime[1] = false;
	for(int i = 2; i * i < N; i++)
		if(prime[i] == true)
			for(int j = 2 * i; j < N; j += i)
				prime[j] = false;
}

void solve() {
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		if(prime[i] == true) {
			int res = 0;
			if (n % i == 0) {
				while (n % i == 0) {
					n /= i;
					res++;
				}
				ans = ans * (2 * res + 1);
			}
		}
	}
	cout << ans << '\n';
}

int32_t main() {
#define TASKNAME "xyn"
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
2
2
3
OUTPUT
3
3
*/
