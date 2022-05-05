#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 200010;

int n;
int a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	sort(a, a + n);
	int p = (n % 2) ? a[n / 2] : a[n / 2 - 1];
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(a[i] - p);
	}
	cout << res << endl;	
	return 0;
}
