#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int a[N], fl[N], fr[N];

void IU() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	FOR(i, 1, n) {
		cin >> a[i];
		if(a[i] == m) v.pb(i);
	}
	stack<int> sl, sr;
	FOR(i, 1, n) {
		while(sl.size() && a[i] > a[sl.top()]) sl.pop();
		if(sl.size() == 0) fl[i] = 1;
		else fl[i] = sl.top();
	}
	FORD(i, n, 1) {
		while(sr.size() && a[i] > a[sr.top()]) sr.pop();
		if(sr.size() == 0) fr[i] = n;
		else fr[i] = sr.top();
	}
	int ans = 0;
	each(x, v) {
		ans += (x - fl[x] + 1) * (fr[x] - x + 1);
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "WGIFT"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
	while(testcase--)
		IU();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
6 5
1 2 5 3 4 5
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
9
------------------------------    |
==================================+
*/
