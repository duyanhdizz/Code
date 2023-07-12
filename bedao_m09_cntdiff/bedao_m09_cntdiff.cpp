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

int n, k;
map<int, int> m;

int32_t main() {
#define TASKNAME "bedao_m09_cntdiff"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	vector<int> a(n);
	for(auto &x : a) cin >> x;
	for(int i = 0; i < k; i++) {
		m[a[i]]++;
	}
	int soluonghoa = 0;
	for(int i = 0; i < k; i++) {
		if(m[a[i]] >= 1) {
			soluonghoa++;
			m[a[i]] = 0;
		}
	}
	for(int i = 0; i < k; i++) {
		m[a[i]]++;
	}
	int ans = soluonghoa;
	int i = k;
	while(i < n) {
		m[a[i - k]]--;
		if(m[a[i - k]] == 0) soluonghoa--;
		//cout << soluonghoa;
		m[a[i]]++;
		if(m[a[i]] == 1) soluonghoa++;
		//cout << soluonghoa << '\n';
		ans = max(ans, soluonghoa);
		i++;
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7 3
1 2 1 2 3 3 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
------------------------------    |
==================================+
*/
