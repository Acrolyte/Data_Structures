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

//--------------------------------------------------------------- STRING ALGORITHMS --------------------------------------------------------------

// HASHING is used in strings to help in easy computation and processing.

// This function is used to return a numeric-hash based on given string. It uses a Polynomial-hash function.
ll compute_hash(string const& s){
	const int p = 31, m = 1e9+9;
	ll hash_value=0, p_pow = 1;

	for(char i: s){
		hash_value = (hash_value + (i - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}

// Search for duplicate strings in an array of strings.
vvl group_similar_strings(vector<string> const& s){
	int n = s.size();
	vector<pll> hashes(n);
	REP(i,n) hashes[i] = {compute_hash(s[i]), i};
	
	SORT(hashes);
	vvl groups;

	REP(i,n){
		if(i==0 or hashes[i].fi != hashes[i-1].fi)
			groups.emplace_back();
		groups.back().push_back(hashes[i].se);
	}
	return groups;
}

// Find the different substrings in a string.
ll count_unique_substrings(string const& s){
	int n = s.size();
	const int p = 31, m = 1e9+9;

	vl p_pow(n);
	p_pow[0] = 1;

	REPN(i,n-1) p_pow[i] = (p_pow[i-1]*p) % m;
	// debug(p_pow)

	vl h(n+1,0);
	REP(i,n){ h[i+1] = (h[i] + (s[i] -'a'+1)* p_pow[i]) % m;}
	debug(h)

	ll cnt = 0;
	REPN(i,n){
		set<ll> hs;
		REP(j,n-i+1){
			ll cur_h = (h[j+i] + m - h[j]) % m;
			cur_h = (cur_h * p_pow[n-j-1]) % m;
			hs.insert(cur_h);
		}
		cnt += hs.size();
		// debug(hs)
	}

	return cnt;
}

// String Matching using RABIN KARP
vl rabin_karp(string const& pattern, string const& text){
	const int p = 31, m = 1e9+9;
	int n1 = pattern.size(), n2 = text.size();

	vl p_pow(max(n1,n2));
	p_pow[0] = 1;

	for(int i=1;i<(int)p_pow.size();i++)
		p_pow[i] = (p_pow[i-1]*p) % m;

	vl h(n2 + 1, 0);

	REP(i,n2) h[i+1] = (h[i] + (text[i] - 'a' + 1)*p_pow[i]) % m;

	ll hs = 0;

	REP(i,n1) hs = (hs + (pattern[i] - 'a' + 1) * p_pow[i]) % m;

	vl occurences;

	for(ll i=0; i+n1-1 < n2; i++){
		ll cur_h = (h[i+n1] + m - h[i]) % m;
		if(cur_h == hs * p_pow[i] % m)
			occurences.pb(i);
	}

	return occurences;
}

vl prefix_function(string s){
	ll n = (ll)s.length();
	vl pi(n,0);
	for(ll i=1;i<n;i++){
		int j= pi[i-1];
		while(j>0 && s[i]!=s[j])
			j = pi[j-1];
		if(s[i]==s[j]) j++;
		pi[i] = j;
	}
	return pi;
}



void solve(){
	ll n=0,x=0,k=0,y=0,z=0,a=0,b=0,c=0;
	string s,t;
	cin>>s;
	// cin>>t;
	// n = compute_hash(s);
	// debug(n)

	// cin>>n;
	// vector<string> v;
	// REP(i,n){cin>>s; v.pb(s);}
	// vvl ans = group_similar_strings(v);
	// debug(ans)

	// k = count_unique_substrings(s);
	// debug(k)

	// vl v = rabin_karp(s,t);
	// debug(v)

	vl ans = prefix_function(s);
	debug(ans)

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("Error.in","w",stderr);
	#endif
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    TC(t)
    solve();

	return 0;
}