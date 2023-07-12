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

int n, c, cow[N];

bool check(int mid) {
	int cows = 1;
	int ketthuc = cow[0];
	for(int i = 1; i < n; i++) {
		if(cow[i] - ketthuc >= mid) {
			cows++;
			ketthuc = cow[i];
			if(cows == c) return true;
		}
	}
	return false;
}

int32_t main() {
#define TASKNAME "cvp_sxtk11"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> c;
	for(int i = 0; i < n; i++) cin >> cow[i];
	sort(cow, cow + n);
	int lo = 1, hi = cow[n - 1] - cow[0];
	int res;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(check(mid)) {
			res = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	cout << res;
	return 0;
}
/*
INPUT
5 3
1
2
8
4
9
OUTPUT
3
*/
