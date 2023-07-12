#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int t;
vector<int> ans;

void sinh(int i, int soluongsokhac0, int num) {
	if(i == 18) {
		ans.pb(num);
		return;
	}
	sinh(i + 1, soluongsokhac0, num * 10);
	if(soluongsokhac0 < 3) {
		for(int j = 1; j <= 9; j++) sinh(i + 1, soluongsokhac0 + 1, num * 10 + j);
	}
}

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sinh(0, 0, 0);
	//for(int i = 1000; i <= 1200; i++) cout << ans[i] << '\n';
	//cout << ans[ans.size() - 1];
	ans.pb(1e18);
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		auto pos = upper_bound(all(ans), r);
		auto poss = lower_bound(all(ans), l);
		cout << pos - poss << '\n';
		//cout << pos << '\n';
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
1 1000
1024 1024
65536 65536
999999 1000001
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1000
1
0
2
------------------------------    |
==================================+
*/