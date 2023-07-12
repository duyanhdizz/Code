#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
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
const int N = 9 + 5e4;
const int INF = 1e9;

int n, q;
double a[N];

double cal_sin(double n) {
	double accuracy = 0.0001, denominator, sinx, sinval;

	// Converting degrees to radian
	n = n * (3.142 / 180.0);

	float x1 = n;

	// maps the sum along the series
	sinx = n;

	// holds the actual value of sin(n)
	sinval = sin(n);
	int i = 1;
	do {
		denominator = 2 * i * (2 * i + 1);
		x1 = -x1 * n * n / denominator;
		sinx = sinx + x1;
		i = i + 1;
	} while (accuracy <= fabs(sinval - sinx));
	return sinx;
}

double cal_cos(double n) {
	double accuracy = 0.0001, x1, denominator, cosx, cosval;

	// Converting degrees to radian
	n = n * (3.142 / 180.0);

	x1 = 1;

	// maps the sum along the series
	cosx = x1;

	// holds the actual value of sin(n)
	cosval = cos(n);
	int i = 1;
	do {
		denominator = 2 * i * (2 * i - 1);
		x1 = -x1 * n * n / denominator;
		cosx = cosx + x1;
		i = i + 1;
	} while (accuracy <= fabs(cosval - cosx));
	return cosx;
}

int32_t main() {
#define TASKNAME "vmsincos"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cout << fixed;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	cin >> q;
	while(q--) {
		string s;
		cin >> s;
		if(s == "Modify") {
			int u;
			double x;
			cin >> u >> x;
			a[u] = x;
		}
		if(s == "Mul") {
			int u, v;
			double x;
			cin >> u >> v >> x;
			FOR(i, u, v) a[i] *= x;
		}
		if(s == "Sin") {
			double sum = 0;
			int u, v;
			double x;
			cin >> u >> v >> x;
			FOR(i, u, v) sum += sin(a[i] - x);
			cout << setprecision(9) << sum << '\n';
		}
		if(s == "Cos") {
			double sum = 0;
			int u, v;
			double x;
			cin >> u >> v >> x;
			FOR(i, u, v) sum += cos(a[i] - x);
			cout << setprecision(9) << sum << '\n';
		}
		if(s == "Reverse") {
			int u, v;
			cin >> u >> v;
			FOR(i, u, (u + v) / 2) swap(a[i], a[u + v - i]);
		}
	}
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
