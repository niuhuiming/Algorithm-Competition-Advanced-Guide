#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
#include <set> 
using namespace std;
typedef long long ll;
const int N = 100010;

int n;
set<pair<ll, int>> s; 

int main() {
	ll x;
	cin >> n >> x;
	s.insert({x, 1});
	s.insert({-6000000000, 0});
	s.insert({6000000000, n + 1});
	for (int i = 2; i <= n; i++) {
		cin >> x;
		pair<ll, int> t = {x, i};
		
		auto big = s.upper_bound(t);
		auto small = s.lower_bound(t);
		small--;
		
		ll bg = abs((*big).first - x);
		ll sm = abs((*small).first - x);
		
		if (sm > bg) {
			cout << bg << ' ' << (*big).second << endl;
		} else {
			cout << sm << ' ' << (*small).second << endl;
		}
		s.insert(t);
	}
	return 0;
} 

