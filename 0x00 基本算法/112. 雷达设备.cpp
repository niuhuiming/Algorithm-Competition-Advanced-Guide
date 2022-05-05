#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 2510;

int n, d; 
vector<pair<double, double>> island;

int main() {
	cin >> n >> d;
	bool succ = false;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		if (y > d) {
			cout << -1 << endl;
			return 0;
		}
		double r = sqrt(1.0 * d * d - y * y);
		island.push_back({x - r, x + r});
	}
	sort(island.begin(), island.end());
	
	int res = 1;
	double last = island[0].second;
	for (int i = 1; i < n; i++) {
		if (island[i].first > last) {
			res++;
			last = island[i].second;
		} else {
			last = min(last, island[i].second);
		}
	}
	cout << res << endl;
	return 0;
} 
