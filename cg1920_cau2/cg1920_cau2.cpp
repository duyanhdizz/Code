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

int n;

int32_t main() {
#define TASKNAME "cg1920_cau2"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n;
    int res = 0;
    while(n > 0) {
    	res += (n % 10);
    	n /= 10;
	}
	string s;
	while(res > 9) s += "9", res -= 9;
	s += to_string(res);
	reverse(all(s));
	cout << s;
    return 0;
}
/*
INPUT
2019
OUTPUT
39
*/
