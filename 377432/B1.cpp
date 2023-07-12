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
const int INF = 1e9;

int32_t main() {
#define TASKNAME "B1"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);

	for (ll &a : A)
		cin >> a;

	sort(A.begin(), A.end());
	int mid = N / 2;
	ll current = A[mid];

	for (int i = mid + 1; i <= N; i++) {
		ll gap = i == N ? INF : A[i] - current;
		ll add = min(K / (i - mid), gap);
		current += add;
		K -= add * (i - mid);
	}

	cout << current;
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
