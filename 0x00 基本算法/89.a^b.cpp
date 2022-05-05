#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 10010;

// 0 �� a, b, p �� 1e9
int ksm(int a, int b, int p) {
	int res = 1 % p; // ��p = 1�����Ϊ0
	while (b) {
		if (b & 1) res = (ll)res * a % p;
		a = (ll)a * a % p;
		b >>= 1;
	}
	return res;
}

int main() {
	int a, b, p;
	cin >> a >> b >> p;
	cout << ksm(a, b, p) << endl;
	return 0;
} 
