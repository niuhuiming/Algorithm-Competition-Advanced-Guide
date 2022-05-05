#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 50010;

int n;
vector<pair<int, int>> ox;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int w, s;
		cin >> w >> s;
		ox.push_back({w + s, s});
	}
	sort(ox.begin(), ox.end());
	
	int res = INT_MIN, sumw = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, sumw - ox[i].second);
		sumw += (ox[i].first - ox[i].second);
	}
	cout << res << endl;
	return 0;
} 
