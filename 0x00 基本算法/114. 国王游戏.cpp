#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1010;

int n; 
pair<int,int> p[N];

vector<int> mul(vector<int> a,int b) {
	int t=0;
	vector<int> ans;
	for(int i=0;i<a.size();i++) 	{
		t=a[i]*b+t;
		ans.push_back(t%10);
		t/=10;
	}
	while(t) {
		ans.push_back(t%10);
		t/=10;
	}
	return ans;
}

vector<int> div(vector<int> a,int b) {
	int t=0;
	vector<int> ans;
	for(int i=a.size()-1;i>=0;i--) {
		t=t*10+a[i];
		ans.push_back(t/b);
		t%=b;
	}
	reverse(ans.begin(),ans.end());
	while(!ans.empty()&&ans[ans.size()-1]==0) //»•µÙ«∞µº0 
		ans.pop_back();
	return ans;
}

vector<int> max_vec(vector<int> a,vector<int> b) {
	if(a.size()>b.size()) return a;
	if(a.size()<b.size()) return b;
	for(int i=a.size()-1;i>=0;i--) {
		if(a[i]>b[i]) return a;
		if(a[i]<b[i]) return b;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		p[i].first = a * b;
		p[i].second = b;
	}
	sort(p + 1, p + n + 1); 
	
	vector<int> pro(1, 1), res(1, 0);
	for (int i = 0; i <= n; i++) {
		if (i) {
			res = max_vec(res, div(pro, p[i].second));
		}
		pro = mul(pro, p[i].first / p[i].second);
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i];
	}
	cout << endl;
	return 0;
} 
