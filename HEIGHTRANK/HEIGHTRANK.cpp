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
const int N = 2106 + 1e6;
const int INF = 2106 + 1e9;

int n;

/// tree type 1

struct FenwickTree {
	vector<int> BIT;
	int size;
	FenwickTree(int n) {
		BIT.resize(n + 1, 0);
		size = n;
	}
	void update(int index) {
		while (index > 0) {
			BIT[index]++;
			index -= index & -index;
		}
	}
	int getSum(int index) {
		int sum = 0;
		while (index <= size) {
			sum += BIT[index];
			index += index & -index;
		}
		return sum;
	}
};

map<int, int> m;

void SaKaTa() {
	int n;
	cin >> n;
	vector<int> heights(n), _(n);
	each(x, heights) cin >> x;
	_ = heights;
	sort(all(heights));
	REP(i, 0, n) m[heights[i]] = i;
	REP(i, 0, n) _[i] = m[_[i]];
//	REP(i, 0, n) cout << _[i] << '\n';
	FenwickTree BIT(n);
	REP(i, 0, n) {
		cout << BIT.getSum(_[i] + 1) + 1 << '\n';
		BIT.update(_[i]);
	}
}

int32_t main() {
#define TASKNAME "HEIGHTRANK"
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
