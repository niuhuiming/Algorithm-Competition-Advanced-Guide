#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 100010;

string s;
stack<int> st;

int main() {
	cin >> s;
	int res = 0;
	for (int i = 0;  i< s.size(); i++) {
		char c = s[i];
		if (st.size() && s[st.top()] == '(' && c == ')') st.pop();
		else if (st.size() && s[st.top()] == '[' && c == ']') st.pop();
		else if (st.size() && s[st.top()] == '{' && c == '}') st.pop();
		else st.push(i);
		if (st.size()) res = max(res, i - st.top());
		else res = max(res, i + 1);
	}
	cout << res << endl;
	return 0;
}
