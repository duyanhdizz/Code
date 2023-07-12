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

int n, x;

int32_t main() {
#define TASKNAME "Step1"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> x;
    vector<int> v;
    for(int i = 1; i <= sqrt(x); i++)
       if(x % i == 0) {
       	 v.pb(i);
       	 if(i * i != x) v.pb(x / i);
	   }
	sort(all(v));
	ll res = 0;
	for(auto i : v) 
	   if(i <= n && x / i <= n) res++;
	cout << res;
    return 0;
}
