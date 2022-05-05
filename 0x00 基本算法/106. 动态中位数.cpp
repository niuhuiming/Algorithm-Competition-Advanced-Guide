#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 100010;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int id, n;
		scanf("%d%d", &id, &n);
		printf("%d %d\n", id, n / 2 + 1);
		priority_queue<int> big;
        priority_queue<int, vector<int>, greater<int>> small;
        int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (big.empty() || x <= big.top()) big.push(x);
			else small.push(x);
			
			if (big.size() > small.size() + 1) small.push(big.top()), big.pop();
			if (small.size() > big.size()) big.push(small.top()), small.pop();
			
			if (i % 2 == 0) {
				printf("%d ", big.top());
				if (++cnt % 10 == 0) printf("\n");
			}
		}
		if (cnt % 10) printf("\n");
	}
	return 0;
}
