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
const int N = 9 + 1e2;
const int INF = 1e9;

int n, k, x, a[N];
bool d[N];

int32_t main() {
#define TASKNAME "364577D"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k >> x;
	for(int i = 0; i < n; i++) cin >> a[i];
	int i = 0;
	int res = 0;
	vector<int> v;
	while(i < n) {
		while(i < n && a[i] != k) d[a[i]] = 1, i++;
		int j = i;
		while(j < n && a[j] == k) j++;
		if((j - i) % 3 == 0) res += (j - i);
		else if((j - i + 1) % 3 == 0) res += (j - i + 1);
		i = j;
	}
	//for(auto i : v) cout << i << '\n';
	for(int i = 0; i + 2 < v.size(); i++)
		if(v[i] == v[i + 1] && v[i + 1] == v[i + 2] && d[v[i]] == 0 && d[v[i + 1]] == 0 && d[v[i + 2]] == 0)
			res += 3, d[v[i]] = 1, d[v[i + 1]] = 1, d[v[i + 2]] = 1;
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
6 2 2
1 1 2 2 1 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
6
------------------------------    |
==================================+
*/
