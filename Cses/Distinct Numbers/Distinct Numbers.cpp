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
const int N = 9 + 2e5;
const int INF = 1e9;

int n;
map<int, int> d;

int32_t main() {
#define TASKNAME "1621"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int res = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(d[x] == 1) res++;
		d[x] = 
	}
	cout << res;
	return 0;
}
/*
INPUT
5
2 3 2 2 3
OUTPUT
2
*/
