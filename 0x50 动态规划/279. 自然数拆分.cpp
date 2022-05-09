#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 4010;

int n;
unsigned f[N];

int main() {
	f[0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			f[j] += f[j - i]; 
		}
	}
	cout << (f[n] - 1) % 2147483648u << endl;
	return 0;
}
