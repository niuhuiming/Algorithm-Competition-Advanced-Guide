#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 100010;

int n, m;
vector<int> path;

void dfs(int p) {
    if (p == n + 1) return ;
	if (path.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] + 1 << ' ';
		}
		cout << endl;
		return ;
	}
	path.push_back(p);
	dfs(p + 1);
	path.pop_back();
	dfs(p + 1);
} 

int main() {
	cin >> n >> m;
	dfs(0);
	return 0;
}
