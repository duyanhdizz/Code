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

int find(int n) {
	int res = 0, m = n;
	while(n > 0) {
		int a = n % 10;
		if(a != 0 && m % a == 0) res++;
		n /= 10;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	cout << find(n) << '\n';
}

int32_t main() {
#define TASKNAME "FINDDIG"
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
2
12
1012
OUTPUT
2
3
*/
