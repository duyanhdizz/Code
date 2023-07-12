#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 9 + 1e6;
const int INF = 1e9;

void solve(int a, int b, int c, int n) {
	if (n == 0) return;
	solve(a, c, b, n - 1);
	cout << a << ' ' << c << '\n';
	solve(b, a, c, n - 1);
}

int32_t main() {
#define TASKNAME ""
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    int n; 
	cin >> n;
    cout<< (1 << n) - 1 << '\n';
    solve(1, 2, 3, n);
    return 0;
}
