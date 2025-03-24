/*
* github 저장용
* 2025-3-24/10:39 WA -> 접근 방식 틀림
* 2025-3-24/11:35 WA -> 접근 방식 틀림
* 2025-3-24/13:29 TLE  -> 접근 방식 틀림(LCA/O(N)을 사용함)
* 2025-3-24/14:30 AC
*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long int lli;
const int MAXN = 1e5 + 1;
lli n, m, parent[MAXN] = {};
vector<lli> path[MAXN] = {};
string a;
lli find(lli x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void merge(lli x, lli y) {
	lli x1 = find(x), y1 = find(y);
	if (x1 == y1) return;
	parent[y1] = x1;
}
int main() {
	fastio;
	cin >> n >> m >> a;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (lli x, y, i = 0; i < n - 1; i++) {
		cin >> x >> y;
		path[x].push_back(y);
		path[y].push_back(x);
		if (a[x - 1] == a[y - 1]) merge(x, y);
	}
	for (lli x, y, i = 0; i < m; i++) {
		char c;
		cin >> x >> y >> c;

		lli u = find(x), v = find(y);

		if (u == v) {//한가지 소만 존재
			a[x - 1] == c ? cout << "1" : cout << "0";
		}
		else cout << "1";//묻지도 말고 존재
	}
}