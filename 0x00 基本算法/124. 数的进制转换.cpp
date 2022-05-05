#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 1000010;

int a, b;
string s;

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> s;
		vector<int> num, res;
		for (int i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') num.push_back(s[i] - '0');
			else if ('A' <= s[i] && s[i] <= 'Z') num.push_back(s[i] - 'A' + 10);
			else if ('a' <= s[i] && s[i] <= 'z') num.push_back(s[i] - 'a' + 36);
		}
		reverse(num.begin(), num.end());
		
		while (num.size()) {
			int t = 0;
			for (int i = num.size() - 1; i >= 0; i--) {
				num[i] += t * a;
				t = num[i] % b;
				num[i] /= b;
			}
			res.push_back(t);
			while (num.size() && num.back() == 0) {
				num.pop_back();
			}
		}
		
		string str;
		for (int i = 0; i < res.size(); i++) {
			if (res[i] <= 9) str += (char)(res[i] + '0');
			else if (res[i] <= 35) str += (char)(res[i] - 10 + 'A') ;
			else str += (char)(res[i] - 36 + 'a');
		}
		reverse(str.begin(), str.end());
		
		cout << a << ' ' << s << endl;
		cout << b << ' ' << str << endl;
		cout << endl;
	}
	return 0;
} 
