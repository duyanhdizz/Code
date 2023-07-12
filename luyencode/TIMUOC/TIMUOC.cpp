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
const int INF = 1e9;

int t;

int indian_multiplication(int a, int b, int mod)
{
    if (b == 0)
        return 0;

    int half = indian_multiplication(a, b / 2LL, mod) % mod;

    if (b & 1)
        return (half + half + a) % mod;
    else
        return (half + half) % mod;
}

// Tính (a^b) % mod. Sử dụng kết hợp với phép nhân Ấn Độ để tránh tràn số khi thực hiện phép nhân.
int modular_exponentiation(int a, int b, int mod)
{
    if (b == 0)
        return 1LL;

    int half = modular_exponentiation(a, b / 2LL, mod) % mod;
    int product = indian_multiplication(half, half, mod);

    if (b & 1)
        return indian_multiplication(product, a, mod);
    else
        return product;
}

bool check_prime_by_miller_rabin(int n, int k) {
	// Xử lý trước các trường hợp đặc biệt.
	if (n < 2)
		return false;

	if (n != 2 && n % 2 == 0)
		return false;

	// Tìm d là số lẻ sao cho n - 1 = 2^r * d và r != 0.
	// Sau khi tìm ra d, r sẽ bằng số lần nhân 2 vào d để tiến tới n - 1.
	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Bắt đầu kiểm tra .
	for (int i = 1; i <= k; ++i) {
		// Chọn a là một số ngẫu nhiên trong đoạn [2, n - 1].
		int a = rand() % (n - 1) + 1;
		int temp = d;

		// Tính a^d % n.
		int mod_val = modular_exponentiation(a, temp, n);

		// Trong khi d != n và a^(2^k * d) % n != 1 và a^(2^k * d) % n != (n - 1).
		// Bước này bản chất là thử kiểm tra mọi x(k) % n với k = 0...r.
		while (temp != n - 1 && mod_val != 1 && mod_val != n - 1) {
			mod_val = indian_multiplication(mod_val, mod_val, n);
			temp *= 2;
		}

		// Nếu không thể chạm được tới x(r) thì nghĩa là đã tồn tại giá trị k khiến cho
		// a^(2^k * d) % n != 1 hoặc a^(2^k * d) % n != -1
		if (mod_val != n - 1 && temp % 2 == 0)
			return false;
	}

	return true;
}

void solve() {
	int n;
	cin >> n;
    if() cout << 
}

int32_t main() {
#define TASKNAME "TIMUOC"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
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
