#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 2510;

int c, l;
vector<pair<int, int>> ox;
map<int, int> spfa;

int main() {
	cin >> c >> l;
	for (int i = 0; i < c; i++) {
		int x, y;
		cin >> x >> y;
		ox.push_back({x, y});
	}
	for (int i = 0; i < l; i++) {
		int x, y;
		cin >> x >> y;
		spfa[x] += y;
	}
	sort(ox.begin(), ox.end());
	
	spfa[0] = spfa[1010] = c;
	int res = 0;
	for (int i = c - 1; i >= 0; i--) {
		auto spf = spfa.upper_bound(ox[i].second);
		spf--;
		if (ox[i].first <= spf->first) {
			res++;
			if (--spf->second == 0) {
				spfa.erase(spf);
			}
		}
	} 
	cout << res << endl;
	return 0;
} 
