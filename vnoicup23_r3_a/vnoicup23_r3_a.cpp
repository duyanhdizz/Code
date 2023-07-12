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

map<int, int> m;

void SaKaTa() {
	m.clear();
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> c(n);
	each(x, c) cin >> x;
	sort(all(c));
	int cos = c[0];
	bool check = true;
	int pos = 0;
	each(x, c) {
		if(m[x] == false && x >= cos && x <= cos + a) m[x] = true, pos++;
	}
	each(x, c) if(m[x] == false) {
		check = false;
		break;
	}
	if(check == true) {
		cout << "YES" << '\n';
		return;
	} else {
		cos = c[pos];
		check = true;
		FOR(i, pos, n - 1) {
			if(m[c[i]] == false && c[i] >= cos && c[i] <= cos + b) m[c[i]] = true;
		}
		FOR(i, pos, n - 1) if(m[c[i]] == false) {
			check = false;
			break;
		}
		if(check == true) {
			cout << "YES" << '\n';
			return;
		}
	}
	m.clear();
	cos = c[0];
	check = true;
	pos = 0;
	each(x, c) {
		if(m[x] == false && x >= cos && x <= cos + b) m[x] = true, pos++;
	}
	each(x, c) if(m[x] == false) {
		check = false;
		break;
	}
	if(check == true) {
		cout << "YES" << '\n';
		return;
	} else {
		cos = c[pos];
		check = true;
		FOR(i, pos, n - 1) {
			if(m[c[i]] == false && c[i] >= cos && c[i] <= cos + a) m[c[i]] = true;
		}
		FOR(i, pos, n - 1) if(m[c[i]] == false) {
			check = false;
			break;
		}
		if(check == true) {
			cout << "YES" << '\n';
			return;
		}

	}
	cout << "NO" << '\n';
}

int32_t main() {
#define TASKNAME "vnoicup23_r3_a"
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
