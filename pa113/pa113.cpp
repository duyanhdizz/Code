#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

double x;
ll n;

long double power(double x, ll n) {
	if(n == 0) return 1;
	if(n == 1) return x;
	long double mid = power(x, n / 2);
	mid *= mid;
	if(n % 2 == 1) mid *= x;
	return mid;
}

int32_t main() {
#define TASKNAME "DEQUY3"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> x >> n;
	cout << fixed;
	cout << setprecision(6) << power(x, n);
	return 0;
}
