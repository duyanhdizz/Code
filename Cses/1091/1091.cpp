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

int n, m;
multiset<int> s;

int32_t main() {
#define TASKNAME "1091"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(-x);
	}
	while(m--) {
		int x;
		cin >> x;
		if(s.lower_bound(-x) == s.end()) cout << -1 << '\n';
		else {
			cout << -*s.lower_bound(-x) << '\n';
			s.erase(s.lower_bound(-x));
		}
	}
	return 0;
}
/*
INPUT
5 3
5 3 7 8 5
4 8 3
OUTPUT
3
8
-1
*/
