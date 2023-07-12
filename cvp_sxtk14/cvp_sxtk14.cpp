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
const int N = 9 + 1e5;
const int INF = 1e9;

int n;
int sum[2][N], point[N];

bool check(int s) {
	for(int i = 1; i <= n; i++)
		if(sum[0][n] - sum[0][i] < s && sum[1][n] - sum[1][i] < s)
			return false;
	return true;
}

int solve(int s) {
	//if(check(s) == false) return -INF;
	int i = 0;
	int win[2], last = -1;
	win[0] = win[1] = 0;
	while(i < n) {
		int lo = i + 1, hi = n, res = n;
		while(lo <= hi) {
			if(sum[0][n] - sum[0][i] < s && sum[1][n] - sum[1][i] < s) return -170608;
			int mid = (lo + hi) / 2;
			if (sum[0][mid] - sum[0][i] >= s || sum[1][mid] - sum[1][i] >= s) {
				res = mid;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		if(sum[0][res] - sum[0][i] == s) win[0]++, last = 0;
		else win[1]++, last = 1;
		i = res;
	}
	if(win[0] == win[1] || win[last] != max(win[0], win[1])) return -170608;
	else return max(win[0], win[1]);
}

int32_t main() {
#define TASKNAME "cvp_sxtk14"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> point[i];
		point[i]--;
		sum[0][i] = sum[0][i - 1];
		sum[1][i] = sum[1][i - 1];
		sum[point[i]][i]++;
	}
	vector<pii> ans;
	for(int s = 1; s <= n; s++) {
		int winner_sets = solve(s);
		if(winner_sets > 0) ans.pb({winner_sets, s});
	}
	sort(all(ans));
	//cout << ans.size() << '\n';
	//for(auto i : ans) cout << i.fi << ' ' << i.se << '\n';
	return 0;
}
/*
INPUT
4
1 1 1 1
---
4
1 2 1 2
OUTPUT
3
1 4
2 2
4 1
---
0
*/