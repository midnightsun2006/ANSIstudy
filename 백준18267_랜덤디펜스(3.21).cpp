/*
* github 저장용
* 2025-3-24/12:57 -> 임시저장
*/

/*
* (H,G)
* 1(1,0)
* 2(2,0)		5(1,1)
* 3(2,1) 4(3,0)
* 
* LCA로 파악 후
* abs(A1 - B1) + LCA -> H,G 존재 여부 파악
* 
* LCA(O(N)) 로는 불가 -> LCA(O(logN)) 사용필요 --> 플래 이상
* 
* => 쉬운 방법 존재
*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long int lli;
const int MAXN = 1e5 + 1;
lli n, m, parent[MAXN] = {};
vector<lli> path[MAXN] = {};
string a;
int main() {
	fastio;
	cin >> n >> m >> a;
	for (lli a, b, i = 0; i < n - 1; i++) {
		cin >> a >> b;
		path[a].push_back(b);
		path[b].push_back(a);
	}

}