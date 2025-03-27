#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long int lli;
const int MOD = 1e3;
lli n, m;
/*
* struct + operator 말고도 배열로도 가능
*/
struct matrix {
	int n, a[6][6] = { 0 };

	matrix operator * (const matrix &b) const {//처음으로 operator 사용
		matrix res;
		res.n = n;
		for (int i = 1; i <= n; i++) {
			for (int g = 1; g <= n; g++) {
				res.a[i][g] = 0;
				for (int z = 1; z <= n; z++) {
					res.a[i][g] += a[i][z] * b.a[z][g];
					res.a[i][g] %= MOD;
				}
			}
		}
		return res;
	}
};
matrix a,ans;
matrix pw(matrix a, lli b) {
	matrix res;
	res.n = n;
	for (int i = 1; i <= n; i++) {
		res.a[i][i] = 1;//단위행렬
	}
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
int main() {
	fastio;
	cin >> n >> m;
	a.n = n;
	for (int i = 1; i <= n; i++) {
		for (int g = 1; g <= n; g++) cin >> a.a[i][g];
		ans.a[i][i] = 1;//단위행렬
	}

	ans = pw(a, m);
	for (int i = 1; i <= n; i++) {
		for (int g = 1; g <= n; g++) cout << ans.a[i][g] << " ";
		cout << "\n";
	}
}