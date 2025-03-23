#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long int lli;
const int MOD = 1e9 + 7;
/*
* 토막상식
* 대부분의 문제에서 MOD가 1e9+7인 이유는 무엇일까?
* -> 1. 예쁘다, 외우기 쉽다.
* -> 2. MOD + MOD가 int를 넘지 않는다.
* -> 3. MOD*MOD가 long long int를 넘지 않는다.
*/
lli gcd(lli a, lli b) {
	if (a > b) gcd(b, a);
	if (a == 0) return b;
	return gcd(b % a, a);
}
lli pw(lli a, lli b) {// 분할정복을 이용한 거듭제곱
	lli res = 1;
	while (b) {
		if (b & 1) res *= a, res %= MOD;
		a *= a, a %= MOD;
		b >>= 1;
	}
	return res;
}
int main() {
	fastio;
	lli ans = 0;
	int m;
	cin >> m;
	while (m--) {
		lli a, b;
		cin >> a >> b;
		lli g = gcd(a, b);
		a /= g, b /= g;
		ans += b * pw(a, MOD - 2) % MOD;
		ans %= MOD;
	}
	cout << ans << "\n";
}