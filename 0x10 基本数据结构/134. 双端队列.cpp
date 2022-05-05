#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 200010;

int n;
pair<int, int> a[N];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	
	int last = INT_MAX;
	int condition = -1;	// -1 ±íÊ¾ÏÂ½µ×´Ì¬
	int res = 1; 
	for (int i = 0; i < n; ) {
		int t = a[i].first;
		int p = a[i].second;
		while (i < n & a[i].first == t) i++;
		int maxp = a[i - 1].second;
		if (condition == -1) {
			if (maxp < last) last = p;
			else {
				condition = 1;
				last = maxp;
			}
		} else {
			if (p > last) last = maxp;
			else {
				res++;
				last = p;
				condition = -1;
			}
		}
	}
	cout << res << endl;
	return 0;
} 
