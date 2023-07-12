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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

const int MOD = 111539786;

class FibonacciMatrix {
	public:
		ll a[2][2];

		FibonacciMatrix() {
			a[0][0] = a[0][1] = a[1][0] = 1ll;
			a[1][1] = 0ll;
		}

		FibonacciMatrix(ll p, ll q, ll r, ll s) {
			a[0][0] = p;
			a[0][1] = q;
			a[1][0] = r;
			a[1][1] = s;
		}

		inline FibonacciMatrix operator % (const ll & mod) {
			return FibonacciMatrix(a[0][0] % mod, a[0][1] % mod, a[1][0] % mod, a[1][1] % mod);
		}

		inline FibonacciMatrix operator * (const FibonacciMatrix & mat) {
			return FibonacciMatrix(a[0][0] * mat.a[0][0] + a[0][1] * mat.a[1][0],
			                       a[0][0] * mat.a[0][1] + a[0][1] * mat.a[1][1],
			                       a[1][0] * mat.a[0][0] + a[1][1] * mat.a[1][0],
			                       a[1][0] * mat.a[0][1] + a[1][1] * mat.a[1][1]) % MOD;
		}

		inline FibonacciMatrix operator ^ (const int & n) {
			if(n == 1) return FibonacciMatrix();
			FibonacciMatrix res = *this ^ (n >> 1);
			return n & 1 ? res * res * FibonacciMatrix() : res * res;
		}
};

void SaKaTa() {
	int n;
	cin >> n;
	cout << (FibonacciMatrix() ^ n).a[0][0] << '\n';
}

int32_t main() {
#define TASKNAME "latgach4"
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
