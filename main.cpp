#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

string a;
string b;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> a;
	cin >> b;

	const auto& bn = static_cast<int>(b.length());

	auto v = vector<char>{};
	auto vn = int{ 0 };
	for (const auto& x : a) {
		v.push_back(x);
		++vn;

		if (vn < bn) {
			continue;
		}

		auto check = bool{ true };
		for (auto i = 0; i < bn; ++i) {
			if (v[vn - bn + i] != b[i]) {
				check = false;
				break;
			}
		}

		if (check) {
			for (auto i = 0; i < bn; ++i) {
				v.pop_back();
				--vn;
			}
		}
	}

	if (0 == vn) {
		cout << "FRULA";
		return 0;
	}

	for (const auto& x : v) {
		cout << x;
	}

	return 0;
}