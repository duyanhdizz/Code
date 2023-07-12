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

int n, t, a[N];

int32_t main() {
#define TASKNAME "bedao_g05_tnv"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> t;
	for(int i = 1; i <= n; i++) cin >> a[i];
	while(t--) {
		int test;
		cin >> test;
		if(test == 1) {
			int k, x;
			cin >> k >> x;
			a[k] = x;
		} else {
			int x;
			cin >> x;
			for(int i = 1; i <= n; i++)
				if(a[i] < x) a[i] = x;
		}
	}
	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}
/*
INPUT
5 3
3 7 2 8 1
1 2 1
2 7
1 3 0
OUTPUT
7 7 0 8 7
*/