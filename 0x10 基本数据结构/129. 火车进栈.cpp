#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
const int N = 10010;

int n, cnt = 20;

vector<int> s1;
stack<int> s2;
int s3 = 1;

void dfs() {
	if (cnt == 0) return ;
	if (s1.size() == n) {
		for (int i = 0; i < n; i++) {
			cout << s1[i];
		}
		cout << endl;
		return ;
	}
	
	if (s2.size()) {
		s1.push_back(s2.top());
		s2.pop();
		dfs();
		s2.push(s1.back());
		s1.pop_back();
	}
	
	if (s3.size() <= n) {
		s2.push(s3);
		s3++;
		dfs();
		s3--;
		s2.pop();
	}
}

int main() {
	cin >> n;
	dfs();
	return 0;
} 
