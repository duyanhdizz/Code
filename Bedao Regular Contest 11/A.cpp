#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int k, a[N];
priority_queue<int, vector<int>> pq;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> k;
	int x;
	while(cin >> x) pq.push(x);
	while(!pq.empty()) {
		k--;
		if(k == 0) cout << pq.top();
		pq.pop();
	}
	return 0;
}
/*
3
2 4 53 12 4
*/