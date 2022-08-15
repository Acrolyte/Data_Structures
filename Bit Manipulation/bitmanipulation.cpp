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
#define SQR(x) ((ll)(x) * (x))
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



// BIT MANIPULATIONS - BASIC OPERATIONS
//
//
// getBit() - gives the bit value at given position
ll getBit(ll n, ll pos){
	return ((n & (1 << pos)) !=0);
}

// setBit() - sets the bit value to '1' at the given position
ll setBit(ll n, ll pos){
	return (n | (1 << pos));
}

// clearBit() - clears the bit value to '0' at the given position
ll clearBit(ll n, ll pos){
	return (n & ~(1 << pos));
}

// updateBit() - updates the bit at the given position first by clearing it, then updating it to given value.
ll updateBit(ll n, ll pos, ll bit){
	clearBit(n,pos);
	return (n | (bit << pos));
}

//check if a given number is power of 2
//returns 1 if n is power of 2 else 0
bool chckPowerofTwo(ll n){
	return (n && !(n & n-1));
}


// count and return the number of ones in binary form for a given number
//
// also __builtin_popcount(x) does the same
ll countNumberOfOnes(ll n){
	ll count = 0;
	while(n){
		n = n & n-1;
		count++;
	}
	return count;
}


//generate all possible subsets of a set
void generateSubsets(vi v){
	ll l = v.size();
	REP(i , (1<<l)){
		REP(j,l){
			if( i & (1 << j)) { // checking for setbit
				cout<<v[j]<<' ';
			}
		}
		cout<<'\n';
	}	
}


// Finding a unique number in an vector where others are present even number of times
int findUniqueNumber(vi v){
	int xorsum = 0;
	FOREACH(i,v){
		xorsum ^= i;
	}
	return xorsum;
}

//Finding two unique numbers in a vector where others are present even number of times
void findTwoUniqueNumber(vi v){
	int xorsum = findUniqueNumber(v);
	int setbit = 0, pos = 0,  tmpxor = xorsum;
	while(setbit!=1){
		setbit = xorsum & 1;
		pos++;
		xorsum = xorsum >> 1;
	}
	
	int newxor = 0 ;

	FOREACH(i,v){
		if(getBit(i,pos-1)){
			newxor ^= i;
		}
	}

	cout<<newxor<<" "<<(tmpxor^newxor)<<endl;
}

//find unique number in a vector where all other numbers are present thrice
void tripletsExceptOne(vi v){
	ll result = 0;
	REP(i,64){
		int sum = 0;
		FOREACH(j,v){
			if(getBit(j,i))
				sum++;
		}
		if(sum % 3 !=0)
			result = setBit(result,i);
	}
	cout<<result;
}

//-------------------------------------------------- BUILTIN_FUNCTIONS -------------------------------------------------------

void builtin(string s){ // taking binary string as input
	bitset<16> bt(s);	// changing to bitset
	ll b = bt.to_ullong(); // converting to long long value
	
	// 1) __builtin_popcount(): Used to give the no. of ones.
	cout << __builtin_popcount(b)<<endl;
	
	// 2) __builtin_parity(): Used to give the parity. If '1' therefore odd count of ones and '0' means even count.
	cout << __builtin_parity(b) << endl;

	// 3) __builtin_clz(): Used to give leading number of zeroes till the MSB (most significant bit).
	cout << __builtin_clz(b) << endl;

	// 4) __builtin_ctz(): Used to give the trailing number of zeroes after the LSB(least significant bit).
	cout << __builtin_ctz(b) << endl;

	// 5) __builtin_ffs(): Used to give the position of the LSB + 1.
	cout << __builtin_ffs(b) << endl;

	// 6) __lg(): Used to give the position of MSB.
	cout << __lg(b) << endl;

	// 7) __builtin_bswap16(): Used to reverse the order of bits. Can also use bswap32, bswap64 and bswap128 as per requirement.
	cout << __builtin_bswap16(b) << endl;
}


//------------------------------------------------- FUNCTION CALLS ------------------------------------------------------------------

void solve(){
	// int n;
	// cin>>n;
	// int k;
	// cin>>k;

	// cout<<getBit(n,k);
	// cout<<setBit(n,k);
	// cout<<clearBit(n,k);
	// cout<<updateBit(n,k,1);

	// cout<<chckPowerofTwo(n);
	// cout<< countNumberOfOnes(n);

	// vi v;
	// int x;
	// TC(n){ cin>>x; v.pb(x); }

	// generateSubsets(v);

	// cout<<findUniqueNumber(v);

	// findTwoUniqueNumber(v);

	// tripletsExceptOne(v);

	string s;
	cin>>s;
	builtin(s);
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