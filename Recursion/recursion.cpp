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

//Basics
void printNameNTimes(LL idx,LL n, string s){
	if(idx==n)return;
	cout<<s<<'\n';
	printNameNTimes(idx+1,n,s);
}

void numbers1toN(LL idx,LL n){
	if(idx > n) return;
	cout<<idx<<'\n';
	numbers1toN(idx+1,n);
}

void numbersNto1(LL n){
	if(n < 1)return;
	cout<<n<<'\n';
	numbersNto1(n-1);
}

//Backtracking basics
void BTnumbers1toN(LL idx,LL n){
	if(idx < 1) return;
	BTnumbers1toN(idx-1,n);
	cout<<idx<<'\n';
}
void BTnumbersNto1(LL idx, LL n){
	if(idx > n) return;
	BTnumbersNto1(idx+1,n);
	cout<<idx<<'\n';
}


void solve(){
	LL n;
	cin>>n;
	string s;
	cin>>s;
	// printNameNTimes(0,n,s);
	// numbers1toN(1,n);
	// numbersNto1(n);
	// BTnumbers1toN(n,n);
	// BTnumbersNto1(1,n);
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();

	return 0;
}