#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 10010;

int n;

// 归并排序模板 && 求解逆序对个数
// a是待排序数组 b是临时数组 cnt是逆序对个数
// a[l ~ r] a下标从0或1开始都可以
ll merge(int l, int r, vector<int>& nums) {
	if (l >= r) return 0;
	int mid = (l + r) >> 1;
	ll cnt = merge(l, mid, nums) + merge(mid + 1, r, nums);
	vector<int> b;
	int i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (nums[i] <= nums[j])
			b.push_back(nums[i++]);
		else {
			b.push_back(nums[j++]);
			cnt += (mid - i + 1);
		}
	}
	while (i <= mid) b.push_back(nums[i++]);
	while (j <= r) b.push_back(nums[j++]);
	i = l;
	for (int x : b) nums[i++] = x;
	return cnt;
}

int main() {
	while (cin >> n, n) {
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		cout << merge(0, n - 1, a) << endl;
	}
	return 0;
} 
