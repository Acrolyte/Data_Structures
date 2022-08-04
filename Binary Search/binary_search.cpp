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

//---------------------------------------------- Simple Binary Search ----------------------------------------------

// Search a list of elements and return the index if the element, else return -1;
ll bsearch(vl &v,ll elem){
	ll lo = 0, hi = v.size()-1;
	while(lo<=hi){
		ll mid = lo + (hi-lo)/2;	// for large values storing (lo + hi) could lead to overflow
		if(v[mid] == elem) return mid;
		if(elem > v[mid]) lo = mid +1;
		else hi = mid -1; 
	}
	return -1;
}

// Search a list of reversely sorted array elements, if not present return -1;
ll revbsearch(vl &v,ll elem){
	ll lo = v.size()-1, hi = 0;
	while(hi<=lo){
		ll mid = hi + (lo-hi)/2;
		if(v[mid] == elem) return mid;
		if(elem > v[mid]) lo = mid -1;
		else hi = mid +1;
	}
	return -1;
}

// Search in a anonymous order list of elements.
ll anonysearch(vl &v, ll elem){
	if(v.size() == 1){
		if(v[0] == elem) return 0;
		else return -1;
	}
	if(v[0]<v[1]) return bsearch(v,elem);  
	else if(v[0] > v[1]) return revbsearch(v,elem);
	return -1;
}

// ---------------------------------------------------------------------------------------------------------------------

// Search and find the index of the first occurence of an element in a list
template<class T>
ll first_occurence(vector<T> &v, T elem){
	ll lo = 0, hi = v.size()-1, res = -1;
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;
		if(elem == v[mid]){
			res = mid;
			hi = mid - 1;
		}
		else if(elem < v[mid])
			hi = mid - 1;
		else lo = mid + 1;
	}
	return res;
}

void solve(){
	ll n=0,t=0,x=0,k=0,y=0,z=0,a=0,b=0,c=0;
	cin>>n;
	
	// vl v;
	// REP(i,n){cin>>x; v.pb(x);}
	// cin>>k;
	// SORT(v);
	// debug(v)
	// cout<<bsearch(v,k)<<endl;
	// RSORT(v);
	// debug(v)
	// cout<<revbsearch(v,k);

	// srand(time(0));		// seeding for rand()
	// t = rand() % 2 + 0; // using rand() to sort randomly for anonymous searching
	// t ? SORT(v) : RSORT(v);
	// cout<<anonysearch(v,k);

	cout<<first_occurence(vc,ch); 
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