/*
* github 저장용
* 2025-3-23/15:10 WA --> goal값 초기화 X
* 2025-3-23/15:20 AC
*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long int lli;
const int MAXN = 1e3 + 1;
vector<int> v[MAXN] = {};
lli n, m, tem[MAXN] = {}, arr[MAXN] = {}, idx = -1, parent[MAXN] = {}, cnt[MAXN] = {}, goal = 0;
//tem[i]로 관계 생성
void cl() {
	for (int i = 0; i < n; i++) {
		goal = 0;
		arr[0] = 0;
		cnt[i] = 0;
		parent[i] = 0;
		tem[i] = 0;
		while (!v[i].empty()) v[i].pop_back();
	}
	idx = -1;
}
int main() {
	fastio;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		cl();

		cin >> arr[0];
		tem[0] = 0;
		parent[0] = -1;

		for (int i = 1; i < n; i++) {
			cin >> arr[i];
			tem[i] = i;
			if (arr[i] == m) goal = tem[i];
			if (arr[i] - arr[i - 1] != 1) idx++;
			v[tem[idx]].push_back(tem[i]);
			parent[tem[i]] = idx;
			cnt[idx]++;
		}

		/*cout << "\n------------------\n";
		for (int i = 0; i < n; i++) {
			if (!v[tem[i]].empty()) {
				cout << arr[tem[i]] << " " << cnt[tem[i]] << "\n";
				for (auto g : v[tem[i]]) cout << arr[g] << " - " << parent[g] << " * ";
				cout << "\n";
			}
		}
		cout << "\n------------------\n";
		*/

		if (goal == 0) cout << "0\n";
		else {
			lli ck = parent[parent[goal]];
			if (ck == -1) cout << "0\n";
			else {
				lli temp = 0;
				for (int i = 0; i < v[ck].size(); i++) temp += cnt[v[ck][i]];
				cout << temp - cnt[parent[goal]] << "\n";
			}
		}

	}
}