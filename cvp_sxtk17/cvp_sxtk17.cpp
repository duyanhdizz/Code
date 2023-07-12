#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

ll n, m, a[N];

int32_t main() {
#define TASKNAME "cvp_sxtk17"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> m;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	int i = 1;
	ll ss = 0;
	for(; i <= n; i++)
	{
		ss += (a[i] - a[i - 1]) * (n + 1 - i);
		if(sum - ss < m) break;
	}
	ss -= (a[i] - a[i - 1]) * (n + 1 - i);
	ll res = (sum - ss - m) / (n + 1 - i);
	cout << a[i - 1] + res; 
    return 0;
}
/*
INPUT
4 17
10 15 25 14
OUTPUT
12
*/
