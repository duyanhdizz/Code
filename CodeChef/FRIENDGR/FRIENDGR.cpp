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
vector<int> v;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	v.erase(all(v));
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '1')
			v.pb(i);
	int kthuc = -INF;
	int res = 0;
	for(int i = 0; i < v.size(); i++) {
		if(v[i] - kthuc <= k) {
			if(v[i] - kthuc == k) kthuc = v[i];
			else kthuc = v[i] + 1;
		} else if(v[i] - kthuc - 1 <= k) {
			kthuc = v[i] - 1;
		} else res++, kthuc = v[i] + 1;
	}
	cout << res << '\n';
}

int32_t main() {
#define TASKNAME "FRIENDGR"
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
6 2
010010
4 0
1001
7 2
1101001
OUTPUT
1
2
1
*/
