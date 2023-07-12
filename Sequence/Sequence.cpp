#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 9 + 1e5;
const int NM = 9 + 2e5;
const int INF = 1e9;

int n, a[N], d[NM];

int32_t main() {
#define TASKNAME "Sequence"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], d[a[i]]++;
    for(int i = 0; i < n; i++) 
       if(d[a[i]] > 5) return cout << -1, 0;
    vector<int> v(n);
    v[0] = 1;
    for(int i = 0; i < n; i++) {
    	if(a[i] < a[i + 1]) v[i + 1] = v[i] + 1;
    	else if(a[i] > a[i + 1]) v[i + 1] = v[i] - 1;
    	else {
    		if(v[i] == 3) v[i + 1] = 2;
    		else v[i + 1] = 3;
		}
	}
	int res = INF;
	for(auto i : v) res = min(res, i);
	for(auto i : v) i += (1 - res), cout << i << ' '; 
	//for(auto i : v) cout << i << ' ';
    return 0;
}
