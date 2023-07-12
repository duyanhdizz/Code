#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e18;

void buildSegmentTree(vector<int>& arr, vector<int>& segmentTree, int start, int end, int index) {
	if (start == end) {
		// Tru?ng h?p d?t d?n lá (ph?n t? duy nh?t)
		segmentTree[index] = arr[start];
		return;
	}

	int mid = (start + end) / 2;

	// Xây d?ng cây con bên trái
	buildSegmentTree(arr, segmentTree, start, mid, 2 * index + 1);

	// Xây d?ng cây con bên ph?i
	buildSegmentTree(arr, segmentTree, mid + 1, end, 2 * index + 2);

	// Tính t?ng c?a hai cây con d? luu vào nút hi?n t?i
	segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
}

// Tính t?ng c?a m?t do?n con
int getSum(vector<int>& segmentTree, int start, int end, int queryStart, int queryEnd, int index) {
	// Tru?ng h?p do?n con hoàn toàn n?m trong do?n dang xét
	if (queryStart <= start && queryEnd >= end)
		return segmentTree[index];

	// Tru?ng h?p do?n con hoàn toàn n?m ngoài do?n dang xét
	if (queryStart > end || queryEnd < start)
		return 0;

	// Tru?ng h?p do?n con giao v?i do?n dang xét
	int mid = (start + end) / 2;
	return getSum(segmentTree, start, mid, queryStart, queryEnd, 2 * index + 1)
	       + getSum(segmentTree, mid + 1, end, queryStart, queryEnd, 2 * index + 2);
}

// C?p nh?t giá tr? c?a m?t ph?n t?
void updateValue(vector<int>& arr, vector<int>& segmentTree, int start, int end, int updateIndex, int diff, int index) {
	// Tru?ng h?p ph?n t? c?n c?p nh?t là lá (ph?n t? duy nh?t)
	if (updateIndex < start || updateIndex > end)
		return;

	// C?p nh?t giá tr? c?a ph?n t? trong m?ng
	arr[updateIndex] += diff;

	// C?p nh?t giá tr? trong cây
	if (start != end) {
		int mid = (start + end) / 2;
		updateValue(arr, segmentTree, start, mid, updateIndex, diff, 2 * index + 1);
		updateValue(arr, segmentTree, mid + 1, end, updateIndex, diff, 2 * index + 2);
		segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
	} else {
		segmentTree[index] += diff;
	}
}

void SaKaTa() {
	int n;
	cin >> n;
	vector<int> arr(n);
	each(x, arr) cin >> x;
	int segmentTreeSize = 2 * pow(2, ceil(log2(n))) - 1;
	vector<int> segmentTree(segmentTreeSize);
	buildSegmentTree(arr, segmentTree, 0, n - 1, 0);
	int queryStart = 1, queryEnd = 7;
	int sum = getSum(segmentTree, 0, n - 1, queryStart, queryEnd, 0);
	cout << "Tong cua doan con tu " << queryStart << " den " << queryEnd << ": " << sum << endl;
//	updateValue(arr, segmentTree, 0, n - 1, updateIndex, diff, 0);
}

int32_t main() {
#define TASKNAME "bedao_g13_c"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
	while(testcase--)
		SaKaTa();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
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
