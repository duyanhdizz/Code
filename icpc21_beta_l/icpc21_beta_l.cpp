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
const int N = 9 + 1e6;
const int INF = 1e9;

int t;

void solve() {
	int n;
	cin >> n;
	set<int> a;
	for(int i = 1; i * i * i <= n; i++)
		if(n % i == 0) {
			if(n % (i + 1) == 0) a.insert(i);
			int res = (n / i);
			int j = sqrt(res);
			while(j * (j + 1) < res) j++;
			if(j * (j + 1) == res) a.insert(j);
		}
	if(a.size() == 0) cout << -1 << '\n';
	else {
		//sort(all(a));
		for(auto i : a) cout << i << ' ';
		cout << '\n';
	}
}

int32_t main() {
#define TASKNAME "icpc21_beta_l"
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
