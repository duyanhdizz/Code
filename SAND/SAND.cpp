#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		long long S, A;
		cin >> A >> S;

		long long x = 0, y = 0;
		bool valid = true;

		for (int i = 0; i < 64; i++) {
			long long bitA = (A >> i) & 1LL;
			long long bitS = (S >> i) & 1LL;

			if (bitA == 1LL) {
				// Nếu bit tương ứng trong S là 0, đặt bit này của x bằng 1
				if (bitS == 0LL && (x & (1LL << i)) == 0) {
					x |= (1LL << i);
				} else if (bitS == 0LL && (y & (1LL << i)) == 0) {
					y |= (1LL << i);
				} else {
					valid = false;
					break;
				}
			} else {
				// Nếu bit tương ứng trong S là 1, đặt bit này của y bằng 1
				if (bitS == 1LL && (x & (1LL << i)) == 0) {
					x |= (1LL << i);
				} else if (bitS == 1LL && (y & (1LL << i)) == 0)                 y |= (1LL << i);
			} else {
				valid = false;
				break;
			}
		}
	}

	if (!valid || x + y != S || (x & y) != A) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}

	return 0;
}