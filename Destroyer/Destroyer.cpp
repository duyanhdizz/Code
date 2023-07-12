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

void SaKaTa() {
	int n;
	cin >> n;
	vector<int> a(n);
	int _0 = 0;
	each(x, a) {
		cin >> x;
		if(x == 0) _0++;
	}
	sort(all(a));
	int val = 0;
	while(a.size() != 0) {
		bool check = false;
		FOR(i, 0, a.size() - 1) {
			if(a[i] == val) {
				if(val == 0) _0--;
				a.erase(a.begin() + i, a.begin() + i + 1);
				val++;
				check = true;
				break;
			}
		}
		if(check == false) {
			if(_0 == 0 && a.size() > 0) {
				cout << "NO" << '\n';
				return;
			}
			val = 0;
		}
	}
	cout << "YES" << '\n';
}

int32_t main() {
#define TASKNAME "Destroyer"
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
