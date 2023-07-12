#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const ll INF = 1e9;

struct DA {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

int n, a[N];
gp_hash_table<int, int, DA> cnt2, cnt1;
gp_hash_table<int, pii> pos;

int32_t main() {
#define TASKNAME "colorbox"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin>>n;
	for(ll i=1; i<=n; ++i) {
		cin>>a[i];
	}
	ll r=n+1, cur2=0;
	while(r>1) {
		if(cnt2[a[r-1]]==0) {
			--r;
			++cnt2[a[r]];
			++cur2;
		} else {
			break;
		}
	}
	ll res=min(INF,n-cur2);
	for(ll i=1; i<=n; ++i) {
		if(cnt1[a[i]])break;
		++cnt1[a[i]];
		while(r<=n&&cnt2[a[i]]) {
			--cnt2[a[r]];
			--cur2;
			++r;
		}
		res=min(res,n-i-cur2);
	}
	cout<<res;
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