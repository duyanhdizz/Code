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
const int N = 9 + 2e5;
const int INF = 1e9;

int n;
bool d[N];
priority_queue<int, vector<int>, greater<int>> pq;

bool check(priority_queue<int, vector<int>, greater<int>> qq) {
	while(!qq.empty()) {
		if(d[qq.top()] == false) return false;
		qq.pop();
	}
	return true;
}

int32_t main() {
#define TASKNAME "2162"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++) pq.push(i);
	fill(d, d + n, false);
	while(check(pq) == true) {
		if(d[pq.top()] == false) d[pq.top() + 1] = true;
		else {
			cout << pq.top() << ' ';
			pq.pop();
		}
	}
	return 0;
}
/*
INPUT
7
OUTPUT
2 4 6 1 5 3 7
*/
