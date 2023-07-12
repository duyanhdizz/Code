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

int a[N];
map<int, int> m;

void YeuHuong() {
	m.clear();
	int n;
	cin >> n;
	bool work = false;
	FOR(i, 1, n) {
		cin >> a[i];
		m[a[i]]++;
		if(m[a[i]] == 2) work = true;
	}
	if(work == true) {
		cout << "NO" << '\n';
		return;
	}
	FOR(i, 2, n / 2) {
		int m_m[i + 1];
		REP(j, 0, i) m_m[j] = 0;
		FOR(j, 1, n) m_m[(a[j]) % i]++;
		work = true;
		REP(j, 0, i) if(m_m[j] < 2) work = false;
		if(work == true) break;
	}
	cout << (work == false ? "YES" : "NO") << '\n';
}

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase;
	cin >> testcase;
	while(testcase--)
		YeuHuong();
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
