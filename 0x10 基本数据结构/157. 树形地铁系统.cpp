#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 10010;

string dfs(string& seq, int& u) {
	u++;
	vector<string> seqs;
	while (seq[u] == '0') {
		seqs.push_back(dfs(seq, u));
	}
	
	u++;
	sort(seqs.begin(), seqs.end());
	string res = "0";
	for (auto x: seqs) {
		res += x;
	}
	res += "1";
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		a = '0' + a + '1';
		b = '0' + b + '1';
		int ua = 0, ub = 0;
		if (dfs(a, ua) == dfs(b, ub)) {
			cout << "same" << endl;
		} else {
			cout << "different" << endl;
		}
	} 
	return 0;
} 
