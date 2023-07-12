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

vector<int> rev(vector<int> a, int i = -1, int j = -1) {
	if (i == -1) i = 0;
	if (j == -1) j = a.size() - 1;
	reverse(a.begin() + i, a.begin() + j + 1);
	return a;
}


vector<int> LIS(vector<int> a, int Lim = INF) {
	vector<int> f;
	vector<int> res(a.size() + 1);

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] < Lim) {
			auto it = lower_bound(f.begin(), f.end(), a[i]);
			if (it == f.end()) f.push_back(a[i]);
			else *it = a[i];
		}
		res[i + 1] = f.size();
	}
	return res;
}

void SaKaTa() {
	int n;
	cin >> n;
	vector<int> a(n);
	each(x, a) cin >> x;
	vector<int> _ = LIS(a);
	a = rev(a);
	vector<int> __ = LIS(a);
	int ans = 0;
	FOR(i, 0, n - 1) ans = max(ans, 2 * min(_[n - i - 1], __[i]) - 1);
	cout << ans;
}

int32_t main() {
#define TASKNAME "spseq"
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
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
