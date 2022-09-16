#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef unsigned long long ull;
typedef long double lld;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define ALLA(arr, sz) arr, arr + sz
#define sz(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define MOD 1e9+7
#define INF 1e18


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//------------------------------------------ 0-1 Knapsack Problem--------------------------------------------------------------
//
// RECURSIVE WAY
ll zeroOneKnapsackRecursive(ll wt[],ll vl[],ll W, ll n){
	if(W==0 or n==0) return 0;

	if(wt[n-1]<=W) 
		return max(vl[n-1]+zeroOneKnapsackRecursive(wt,vl,W-wt[n-1],n-1),
			zeroOneKnapsackRecursive(wt,vl,W,n-1));
	else if(wt[n-1]>W)
		return zeroOneKnapsackRecursive(wt,vl,W,n-1);
	return -1;
}
//
// DP WAY (Memoized)
ll zeroOneKnapsackMemoized(ll wt[],ll vl[],ll W, ll n,vvl &dp){
	if(W==0 or n==0) return 0;
	if(dp[n][W]!=-1) return dp[n][W];

	if(wt[n-1]<=W) 
		return dp[n][W] = max(vl[n-1]+zeroOneKnapsackMemoized(wt,vl,W-wt[n-1],n-1,dp),
			zeroOneKnapsackMemoized(wt,vl,W,n-1,dp));
	else if(wt[n-1]>W)
		return dp[n][W] = zeroOneKnapsackMemoized(wt,vl,W,n-1,dp);
	return dp[n][W];
}
//
// DP WAY ()
ll zeroOneKnapsackTopDown(ll wt[],ll vl[],ll W, ll n){
	vvl dp(n+1,vector<ll> (W+1));

	REP(i,n+1)
		REP(j,W+1)
			if(i==0 or j==0) dp[i][j] = 0;

	for(ll i=1;i<n+1;i++)
		for(ll j=1;j<W+1;j++)
			if(wt[i-1]<=j)
				dp[i][j] = max(vl[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];

	return dp[n][W];
}

void solve(){
	ll n=0,t=0,x=0,k=0,y=0,z=0,a=0,b=0,c=0;
	cin>>n;
	
	//0-1 Knapsack Input
	ll wt[n] = {0}, vl[n] = {0};
	REP(i,n){cin>>wt[i];} // weight array
	REP(i,n){cin>>vl[i];} // value array
	ll W;
	cin>>W; // capacity

	// cout << zeroOneKnapsackRecursive(wt,vl,W,n);
	// vvl dp(n+1, vector<ll> (W+1,-1)); // 2d vector declared with 'n+1' rows and 'W+1' columns with default value 1.
	// cout<< zeroOneKnapsackMemoized(wt,vl,W,n,dp);
	cout << zeroOneKnapsackTopDown(wt,vl,W,n);

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("Error.in","w",stderr);
	#endif
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    //int t;
    //cin>>t;
    //TC(t)
    solve();

	return 0;
}