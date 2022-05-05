#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

string s;
stack<int> nums;
stack<char> op;

void init() {
	cin >> s;
	if (s[0] == '-') s = "0" + s;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		tmp = tmp + "(";
	}
	s = tmp + s + ")";
}

int calc() {
	int a = nums.top();
	nums.pop();
	int b = nums.top();
	nums.pop();
	char operate = op.top();
	op.pop();
	int d = 0;
	if (operate == '+') d = b + a;
	else if (operate == '-') d = b - a;
	else if (operate == '*') d = b * a;
	else if (operate == '/') d = b / a;
	else if (operate == '^') {
		d = 1;
		while (a--) d *= b;
	}
	nums.push(d);
}

int main() {
	init();
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			int j = i, t = 0;
			while ('0' <= s[j] && s[j] <= '9') {
				t = t * 10 + (s[j] - '0');
				j++;
			}
			i = j - 1;
			nums.push(t);
		} else {
			if (s[i] == '+' || s[i] == '-') {
				if (s[i] == '-' && !('0' <= s[i - 1] && s[i - 1] <= '9') && s[i - 1] != ')') {
					if (s[i + 1] == '(') {
						nums.push(-1);
						op.push('*');
					} else {
						int j = i + 1, t = 0;
						while ('0' <= s[j] && s[j] <= '9') {
							t = t * 10 + (s[j] - '0');
							j++;
						}
						i = j - 1;
						nums.push(-t);
					}
				} else {
					while (op.top() != '(') {
						calc();
					}
					op.push(s[i]);
				}
			} else if (s[i] == '*' || s[i] == '/') {
				while (op.top() == '*' || op.top() == '/' || op.top() == '^') {
					calc();
				}
				op.push(s[i]);
			} else if (s[i] == '^') {
				while (op.top() == '^') {
					calc();
				}
				op.push(s[i]);
			} else if (s[i] == '(') {
				op.push(s[i]);
			} else if (s[i] == ')') {
				while (op.top() != '(') {
					calc();
				}
				op.pop();
			} else {
				cout << "error" << endl;
				break;
			}
		}
	}
	cout << nums.top() << endl;
	return 0;
}
