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

int n, x;

int32_t main() {
#define TASKNAME "1163"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> x;
	set<int> li{0, n};
	multiset<int> di{n};
	for (int l = 0; l < x; l++) {
		int pos;
		cin >> pos;
		auto it1 = li.upper_bound(pos);
		auto it2 = it1;
		it2--;
		di.erase(di.find(*it1 - *it2)); // k/cach cu
		di.insert(pos - *it2); // them k/cach ms
		di.insert(*it1 - pos); // then k/cach ms
		li.insert(pos);
		auto ans = di.end();
		ans--;
		cout << *ans << ' ';
	}
	return 0;
}
/*
INPUT
8 3
3 6 2
OUTPUT
5 3 3
*/
