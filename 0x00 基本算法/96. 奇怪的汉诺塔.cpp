#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 15;

int d[N], f[N];

int main() {
	for (int i = 1; i <= 12; i++) {
		d[i] = d[i - 1] * 2 + 1; 
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= 12; i++) {
		for (int j = 0; j < i; j++) {
			f[i] = min(f[i], f[j] * 2 + d[i - j]);
		}
	}
	for (int i = 1; i <= 12; i++) {
		cout << f[i] << endl;
	} 
	return 0;
}
