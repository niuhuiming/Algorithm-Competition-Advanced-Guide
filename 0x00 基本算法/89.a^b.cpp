#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 10010;

// 0 ¡Ü a, b, p ¡Ü 1e9
int ksm(int a, int b, int p) {
	int res = 1 % p; // Èôp = 1£¬½á¹ûÎª0
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
