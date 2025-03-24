/*
* github 임시저장
*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long int lli;
const int MAXN = 1e4 * 5 + 1;
lli n, k, arr[MAXN] = {};
int main() {
	fastio;
	cin >> n >> k;
	for (lli a, i = 0; i < n; i++) cin >> arr[i];

	std::sort(arr, arr + n);
	lli idx = 1, ans = 1, tem = 1;
	while (idx!=n) {
		if(arr[idx]-arr[idx-1]<=k) {
			tem++;
		}
		else {
			ans = max(ans, tem);
			tem = 1;
		}
		idx++;
	}
	ans = max(ans, tem);
	cout << ans << "\n";
}