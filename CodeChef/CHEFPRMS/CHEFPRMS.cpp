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

bool check(int n) {
    if(n < 2) return false;
    int res = 0;
	for(int i = 2; i <= n; i++)
		if(n % i == 0) {
			n /= i;
			if(n % i == 0) return false;
			res++;
		}
	if(res != 2) return false;
	else return true;
}

void solve() {
	int n;
	cin >> n;
	for(int i = 6; i <= n; i++) {
		if(check(i) && check(n - i)) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int32_t main() {
#define TASKNAME "CHEFPRMS"
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
30
45
62
OUTPUT
YES
YES
NO
*/
