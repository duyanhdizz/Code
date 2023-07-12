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

void IU() {
	int d, a, b;
	cin >> d >> a >> b;
	cout << ' ';
	for(int i = 1; i <= d - 2; i++) cout << '*';
	cout << "  ";
	for(int i = 1; i <= d - 2; i++) cout << '*';
	cout << '\n';
	for(int j = 1; j <= d - 2; j++) {
		for(int i = 1; i <= d * 2; i++) cout << '*';
		cout << '\n';
	}
	cout << ' ';
	for(int i = 1; i <= d - 2; i++) cout << '*';
	cout << "  ";
	for(int i = 1; i <= d - 2; i++) cout << '*';
	cout << '\n';
	while(b--) {
		for(int i = 1; i <= d / 2; i++) cout << ' ';
		for(int i = 1; i <= a; i++) cout << '*';
		cout << '\n';
	}
}

int32_t main() {
#define TASKNAME "hhc"
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

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
