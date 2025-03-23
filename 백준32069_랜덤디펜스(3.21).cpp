﻿/*
* github 저장용
* 2025-3-23/19:55 AC
*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int lli;
const int MAXN = 1e5 * 3 + 1;
using namespace std;
lli l, n, k, a[MAXN] = {};
vector<lli> ans;
int main() {
	fastio;
	cin >> l >> n >> k;
	for (int i = 0; i < n; i++) {//n개
		cin >> a[i];
		ans.push_back(0);
	}
	//k-n개
	lli idx = 1;
	while (1) {
		for (int i = 0; i < n; i++) {//0 1
			if (i == 0) {//0 ... a[i]
				if (a[i] - idx >= 0) ans.push_back(idx);
			}
			if (i == n - 1) {//a[i] ... n - 1
				if (a[i] + idx <= l) ans.push_back(idx);
			}
			else {//a[i] ... a[i+1]
				if (a[i] + idx > a[i + 1] - idx) continue;
				else if (a[i] + idx == a[i + 1] - idx) ans.push_back(idx);
				else { ans.push_back(idx); ans.push_back(idx); }
			}
		}
		idx++;
		if (ans.size() >= k) break;
	}
	for (int i = 0; i < k; i++) cout << ans[i] << "\n";
}