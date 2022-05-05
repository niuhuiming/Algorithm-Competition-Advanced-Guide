#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 20;

int n;
int a[N][N];
int f[1<<N][N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	memset(f, 0x3f, sizeof f);
	f[1][0] = 0;
	for (int i = 0; i < 1 << n; i++) {
	    for (int j = 0; j < n; j++) {
	        if (i >> j & 1) {
	            for (int k = 0; k < n; k++) {
	                if ((i ^ 1 << j) >> k & 1) {
	                   // ��ǰ�� k �㣬 ����״̬Ϊ i ^ 1 << j, ��λ��Ϊ j, ����״̬Ϊ i ת��
	                    f[i][j] = min(f[i][j], f[i ^ 1 << j][k] + a[k][j]);
	                }
	            }
	        }
	    }
	}
	cout << f[(1 << n) - 1][n - 1] << endl;
	return 0;
} 
