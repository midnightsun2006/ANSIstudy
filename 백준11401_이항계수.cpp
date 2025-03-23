#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long int lli;
const lli MOD = 1e9 + 7;
const lli MAXN = 4 * 1e6 + 2;
lli n, k, f[MAXN] = {}, g[MAXN] = {};
lli cal(lli n, lli k) {
	return f[n] * g[n - k] % MOD * g[k] % MOD;
}
lli pw(lli a, lli b) {
	lli res = 1;
	while (b) {
		if (b & 1) res *= a, res %= MOD;
		a *= a, a %= MOD;
		b >>= 1;
	}
	return res;
}
void fct() {
	f[0] = 1;//base case
	for (int i = 1; i < MAXN; i++) f[i] = f[i - 1] * i % MOD;
	g[MAXN - 1] = pw(f[MAXN - 1], MOD - 2);//base case -> Fermat’s Little Theorem
	/*
	* g[i]=1/f[i]=f[i]^-1=f[i]^(MOD-2)
	*/
	for (int i = MAXN - 2; i >= 0; i--) g[i] = g[i + 1] * (i + 1) % MOD;
}
int main() {
	fastio;
	cin >> n >> k;
	fct();
	cout << cal(n, k);
}