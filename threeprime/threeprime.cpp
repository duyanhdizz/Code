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

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}

long long countNumbers(long long a, long long b, long long c, long long n) {
	long long count_a = n / a;
	long long count_b = n / b;
	long long count_c = n / c;

	long long count_ab = n / lcm(a, b);
	long long count_ac = n / lcm(a, c);
	long long count_bc = n / lcm(b, c);

	long long count_abc = n / lcm(a, lcm(b, c));

	long long count = count_a + count_b + count_c - count_ab - count_ac - count_bc + count_abc;
	return count;
}

void SaKaTa() {
	long long a, b, c, n;
	cin >> a >> b >> c >> n;
	cout << countNumbers(a, b, c, n);
}

int32_t main() {
#define TASKNAME "threeprime"
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
