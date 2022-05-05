#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 100010;

int n;
vector<int> path;


void dfs(int p, int vis) {
	if (p == n) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << ' ';
		}
		cout << endl;
		return ;
	}
	for (int i = 0; i < n; i++) {
		if (!((vis >> i) & 1)) {
			path.push_back(i + 1);
			dfs(p + 1, vis | (1 << i));
			path.pop_back();
		}
	} 
}

int main() {
	cin >> n;
	dfs(0, 0);
	return 0;
}
