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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 2106 + 2e5;
const int INF = 2106 + 1e9;

int a[N], _[N], f[N];

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	while(m--) {
		int l, r;
		cin >> l >> r;
		_[l]++;
		_[r + 1]--;
	}
	FOR(i, 1, n) _[i] += _[i - 1];
	FORD(i, n, 1) {
		if(_[i] == 0) {
			f[i] = 0;
		} else {
			f[i] = max(f[i + 1], _[i]);
		}
	}
	bool check = false;
	int ans = 0, __;
	int i = 1;
	while(i <= n) {
		if(f[i] == 0) ans += a[i], i++;
		else {
			int p = f[i], o = -INF;
			while(i <= n && f[i] != 0) {
				if(_[i] == p) {
					o = max(o, a[i]);
				}
				i++;
			}
			ans += o;
		}
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "LIGHT"
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
		SaKaTa();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
