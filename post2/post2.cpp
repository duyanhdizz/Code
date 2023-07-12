#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;

int n;

using cd = complex<double>;
const double PI = acos(-1);

struct Template_FFT
{
	void fft(vector<cd> &a, bool invert)
	{
	    int n = a.size();
	
	    for (int i = 1, j = 0; i < n; i++)
	    {
	        int bit = n >> 1;
	        for (; j & bit; bit >>= 1)
	            j ^= bit;
	        j ^= bit;
	
	        if (i < j)
	            swap(a[i], a[j]);
	    }
	                                                   
	    for (int len = 2; len <= n; len <<= 1)
	    {
	        double ang = 2 * PI / len * (invert ? -1 : 1);
	        cd wlen(cos(ang), sin(ang));
	        for (int i = 0; i < n; i += len)
	        {
	            cd w(1);
	            for (int j = 0; j < len / 2; j++)
	            {
	                cd u = a[i + j], v = a[i + j + len / 2] * w;
	                a[i + j] = u + v;
	                a[i + j + len / 2] = u - v;
	                w *= wlen;
	            }
	        }
	    }
	
	    if (invert)
	        for (cd &x : a)
	            x /= n;
	}
	
	vector<int> multiply(vector<int> const& a, vector<int> const& b)
	{
		vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
		int n = 1;
		while(n < a.size() + b.size())
			n <<= 1;
		fa.resize(n);
		fb.resize(n);
	
		fft(fa, false);
		fft(fb, false);
	
		for (int i = 0; i < n; i++)
			fa[i] *= fb[i];
		fft(fa, true);
	
		vector<int> result(n);
		for (int i = 0; i < n; i++)
			result[i] = long(fa[i].real() + 0.5);
		return result;
	}
}FFT;

int32_t main() {
#define TASKNAME "post2"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<int> a(100001), b(100001), c(200001);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x + 50000]++;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b[x + 50000]++;
	}
	for (int i = 0; i < n; i++)
		cin >> c[i];
	vector<int> ab = FFT.multiply(a, b);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += ab[c[i] + 100000];
	cout << ans;
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
