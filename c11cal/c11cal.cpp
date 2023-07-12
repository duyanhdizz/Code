#include <bits/stdc++.h>

template <class T>
using V = std::vector<T>;
using ll = long long;

int ____ = std::cin.tie(nullptr)->sync_with_stdio(false);

// END OF HEADER | Author: Roger Young

const int P = 1E9 + 7;

// @description ???(i32, P)

int qpow(int a, int b = P - 2, int m = P) {
	int ret = 1 % m;
	for (; b > 0; b /= 2) {
		if (b % 2 == 1)
			ret = 1ll * ret * a % m;
		a = 1ll * a * a % m;
	}
	return ret;
}

// @description ????

// clang-format off
#define OPERATOR(U, V, op)	\
	friend inline U operator op(const U &l, const V &r) {	\
		return U(l) op##= r;	\
	}
// clang-format on

struct Z {
	int v;
	Z(ll a = 0) : v((a % P + P) % P) {}
	Z &operator=(const int &m) {
		v = m;
		return *this;
	}
	Z &operator+=(const Z &m) {
		v = (v += m.v) >= P ? v - P : v;
		return *this;
	}
	Z &operator-=(const Z &m) {
		v = (v -= m.v) < 0 ? v + P : v;
		return *this;
	}
	Z &operator*=(const Z &m) {
		v = 1ll * v * m.v % P;
		return *this;
	}
	OPERATOR(Z, Z, +);
	OPERATOR(Z, Z, -);
	OPERATOR(Z, Z, *);
	Z pow(int n) const {
		return qpow(v, n);
	}
	Z inv() const {
		return pow(P - 2);
	}
	// useless
	Z operator-() const {
		return v == 0 ? 0 : P - v;
	}
	Z &operator/=(const Z &m) {
		return *this *= m.inv();
	}
	OPERATOR(Z, Z, /);
	auto approx(int A = 1E3) {
		int x = v, y = P, a = 1, b = 0;
		while (x > A) {
			std::swap(x, y), std::swap(a, b);
			a -= x / y * b, x %= y;
		}
		return std::make_pair(x, a);
	}
};

std::istream &operator>>(std::istream &is, Z &z) {
	return is >> z.v;
}

std::ostream &operator<<(std::ostream &os, const Z &z) {
	return os << z.v;
}

Z solve(const V<Z> &y, int x) {
	int n = y.size();
	if (0 <= x && x < n)
		return y[x];
	V<Z> pl(n + 2, 1), pr(n + 2, 1), fac(n + 2, 1);
	for (int i = 0; i < n; i++)
		pl[i + 1] = pl[i] * (x - i);
	for (int i = n - 1; i >= 0; i--)
		pr[i] = pr[i + 1] * (x - i);
	for (int i = 1; i < n; i++)
		fac[i] = fac[i - 1] * i;
	Z ans = 0;
	for (int i = 0; i < n; i++) {
		Z s1 = pl[i] * pr[i + 1];
		Z t = (n - i) % 2 == 0 ? -1 : 1;
		Z s2 = fac[i] * fac[n - i - 1] * t;
		ans += s1 / s2 * y[i];
	}
	return ans;
}

auto powers(int n, int k, int mod) {
	V<bool> isp(n + 1, true);
	V<int> pw(n + 1, 1);
	for (int p = 2; p <= n; ++p)
		if (isp[p]) {
			for (ll j = ll(p) * p; j <= n; j += p)
				isp[j] = false;
			int q = qpow(p, k, mod);
			for (int i = 1; i <= n / p; ++i)
				pw[i * p] = ll(q) * pw[i] % mod;
		}
	pw[0] = qpow(0, k, mod);
	return pw;
}

int main() {
	int n, k;
	while(std::cin >> n >> k) {
		V<Z> y(k + 2, 0);
		auto pw = powers(k + 2, k, P);
		for (int i = 1; i < k + 2; i++) {
			y[i] = (y[i - 1] + pw[i]);
		}
		std::cout << solve(y, n) << '\n';
	}
	return 0;
}
