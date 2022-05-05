#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1000010;

int n, k;
int a[N];
int q[N];
int l, r = -1;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	for (int i = 1; i <= n; i++) {
		if (l <= r && i - q[l] >= k) l++;
		while (l <= r && a[i] <= a[q[r]]) r--;
		q[++r] = i;
		if (i >= k) {
			cout << a[q[l]] << ' ';
		}
	}
	cout << endl;
	
	l = 0, r = -1;
	for (int i = 1; i <= n; i++) {
		if (l <= r && i - q[l] >= k) l++;
		while (l <= r && a[i] >= a[q[r]]) r--;
		q[++r] = i;
		if (i >= k) {
			cout << a[q[l]] << ' ';
		}
	}
	cout << endl;
	return 0;
} 
