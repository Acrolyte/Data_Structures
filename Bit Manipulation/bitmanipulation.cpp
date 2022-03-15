#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

// BIT MANIPULATIONS

// getBit() - gives the bit value at given position
LL getBit(LL n, LL pos){
	return ((n & (1 << pos)) !=0);
}

// setBit() - sets the bit value to '1' at the given position
LL setBit(LL n, LL pos){
	return (n | (1 << pos));
}

// clearBit() - clears the bit value to '0' at the given position
LL clearBit(LL n, LL pos){
	return (n & ~(1 << pos));
}

// updateBit() - updates the bit at the given position first by clearing it, then updating it to given value.
LL updateBit(LL n, LL pos, LL bit){
	clearBit(n,pos);
	return (n | (bit << pos));
}



void solve(){
	int n;
	cin>>n;
	int k;
	cin>>k;

	// cout<<getBit(n,k);
	// cout<<setBit(n,k);
	// cout<<clearBit(n,k);
	// cout<<updateBit(n,k,1);

	
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin>>t;
    //TC(t)
    solve();

	return 0;
}