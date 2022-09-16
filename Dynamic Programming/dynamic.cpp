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
// DP WAY (Top Down)
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
	// debug(dp)
	return dp[n][W];
}
//
// Problems related to 0-1 Knapsack :-
//
// 1. Subset Sum: Check if there exists a sum of numbers equal to the given weight W.
// 
bool subsetSum(ll val[],ll W, ll n){
	vector<vector<bool>> dp(n+1, vector<bool> (W+1));

	REP(i,n+1) REP(j,W+1) {
		if(i==0) dp[i][j] = false;
		if(j==0) dp[i][j] = true;
	}
	for(ll i=1;i<n+1;i++)
		for(ll j=1;j<W+1;j++)
			if(val[i-1] <= j)
				dp[i][j] = (dp[i-1][j-val[i-1]] or dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];

	// for(vector<bool> i: dp){ auto it = i; debug(it);}
	return dp[n][W]; 
}
//
// 2. Equal Sum Partition Problem: Check if the given numbers can be divided into two parts of equal values.
//
bool equalSumPartition(ll val[], ll n){
	ll sum = 0;
	REP(i,n) sum += val[i];

	if(sum & 1) return false;
	else {
		sum >>= 1;

		// vector<vector<bool>> dp(n+1, vector<bool> (sum+1));

		// REP(i,n+1) REP(j,sum+1){
		// 	if(i==0) dp[i][j] = false;
		// 	if(j==0) dp[i][j] = true;
		// }

		// for(ll i=1;i<n+1;i++)
		// for(ll j=1;j<sum+1;j++){
		// 	if(val[i-1] <= j)
		// 		dp[i][j] = (dp[i-1][j-val[i-1]] or dp[i-1][j]);
		// 	else dp[i][j] = dp[i-1][j];
		// }

		// for(vector<bool> i: dp){ auto it = i; debug(it);}
		// return dp[n][sum];


		// Typed everything but lets call subsetSum(). :P

		return subsetSum(val,sum,n); // Totally worth it ;)

	}
	return false;
}
//
// 3. Count of all subsets: Gives count of all the subsetSums equal to given weight.
//
ll countSubsets(ll val[],ll W,ll n){
	vvl dp(n+1, vector<ll> (W+1));
	REP(i,n+1) REP(j,W+1){
		if(i==0) dp[i][j] = 0;
		if(j==0) dp[i][j] = 1;
	}
	REPN(i,n)
	REPN(j,W){
		if(val[i-1]<=j)
			dp[i][j] = dp[i-1][j] + dp[i-1][j-val[i-1]];
		else dp[i][j] = dp[i-1][j];
	}

		for(auto i: dp){ auto it = i; debug(it);}
	return dp[n][W];
}
//
// 4. Minimize Subset Sum Difference: Partition the array into two parts such that difference between the sums of each part become minimized. 
//
ll minimizeSubsetSumDifference(ll val[],ll n){
	ll sum = accumulate(val, val + n, 0);
	ll range = sum;
	sum = ceil(sum/2.0);

	vector<vector<bool>> dp(n+1, vector<bool> (sum+1));

	REP(i,n+1)
	REP(j,sum+1){
		if(i==0) dp[i][j] = false;
		if(j==0) dp[i][j] = true;
	}

	REPN(i,n) REPN(j,sum){
		if(val[i-1] <= j)
			dp[i][j] = dp[i-1][j-val[i-1]] or dp[i-1][j];
		else dp[i][j] = dp[i-1][j];
	}
	for(auto i: dp){ auto it = i; debug(it);}

	ll mi = 0;
	for(ll j=0;j<sum;j++) if(dp[n][j]) mi = max(mi,j);

	return (range - 2*mi);
}
//
// 5. Count the number of Subset with a given difference: Find the number of such partitions in the list of elements such that the difference in the Subset Sums is equal to the given value.
//
ll countNumberSubsetDiff(ll val[],ll diff, ll n){
	// using S1 - S2 = diff and S1 + S2 = sum
	// we get that required sum = (diff + sum)/2 

	ll sum = accumulate(val,val+n,0);
	ll req_sum = (diff + sum) / 2;
	return countSubsets(val,req_sum,n); // Refer the countSubset() function is required.
}
//
// 6. Target Sum: From the given list of numbers, we need to return the count of different combinations by setting plus(+) or minus(-) signs infront of every element such that the sum becomes equal to the target.
//
ll targetSum(ll val[],ll W,ll n){
	// consider the subsetsum of positive elements be S1 and that of negative elements be S2
	// Now, S1 - S2 = W ( We may notice that it is similar to the previous problem. :D )
	// Hence same implementation will be there.

	return countNumberSubsetDiff(val,W,n); // Saving time ;)
}

void solve(){
	ll n=0,t=0,x=0,k=0,y=0,z=0,a=0,b=0,c=0;
	cin>>n;
	
	//0-1 Knapsack Input
	ll wt[n] = {0}, vl[n] = {0};
	REP(i,n){cin>>vl[i];} // value array
	// REP(i,n){cin>>wt[i];} // weight array
	ll W;
	cin>>W; // capacity

	// cout << zeroOneKnapsackRecursive(wt,vl,W,n);
	// vvl dp(n+1, vector<ll> (W+1,-1)); // 2d vector declared with 'n+1' rows and 'W+1' columns with default value 1.
	// cout<< zeroOneKnapsackMemoized(wt,vl,W,n,dp);
	// cout << zeroOneKnapsackTopDown(wt,vl,W,n);

	// PROBLEMS ON 0-1 KNAPSACK
	// cout<<( subsetSum(vl,W,n) ? "Yes" : "No");
	// cout << (equalSumPartition(vl,n) ? "Yes" : "No");
	// cout << countSubsets(vl,W,n);
	// cout<< minimizeSubsetSumDifference(vl,n);
	// cout << countNumberSubsetDiff(vl,W,n);
	cout << targetSum(vl,W,n);

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