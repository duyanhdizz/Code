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

bool approximatelyEqual(double a, double b, double epsilon) {
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}

void SaKaTa() {
	double tm, sm, ty, sy;
	cin >> tm >> sm >> ty >> sy;
	double _, __;
	if((double)100 * sm <= (double)10 * (tm + sm)) _ = (double)100 / (tm + sm);
	else _ = (double)10 / sm + ((double)100 - (double)10 / sm * (tm + sm)) / tm;
	if((double)100 * sy <= (double)10 * (ty + sy)) __ = (double)100 / (ty + sy);
	else __ = (double)10 / sy + ((double)100 - (double)10 / sy * (ty + sy)) / ty;
	if(approximatelyEqual(_, __, 1e-8)) cout << "Draw" << '\n';
	else if(_ > __) cout << "Yunyun" << '\n';
	else cout << "Megumin" << '\n';
}

int32_t main() {
#define TASKNAME "vnoicup23_r1_b"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
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
