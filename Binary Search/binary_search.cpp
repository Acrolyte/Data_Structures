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
ll first_occurrence(vector<T> &v, T elem){
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

// Search and find the index of the last occurence of an element in a list
template<class T>
ll last_occurrence(vector<T> &v, T elem){
	ll lo = 0, hi = v.size()-1, res = -1;
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;
		if(elem == v[mid]){
			res = mid;
			lo = mid + 1;
		}
		else if(elem < v[mid])
			hi = mid - 1;
		else lo = mid + 1;
	}
	return res;
}

// Find the count of an element in a sorted list
template<class T>
ll count_occurrence(vector<T> &v, T elem){
	ll a = first_occurrence(v,elem);
	ll b = last_occurrence(v,elem);
	if(a == b and a == -1) return -1;
	return b - a + 1;
}

// Find the number of times a sorted list is rotated.
template<class T>
ll num_times_rotated(vector<T> &v){
	ll lo = 0, hi = v.size() - 1, n = v.size();
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;
		ll prv = (mid - 1 + n) % n, nxt = (mid + 1)%n;
		if(v[mid] <= v[prv] and v[mid] <= v[nxt])
			return mid;
		else if(v[mid] <= v[hi])
			hi = mid - 1;
		else if(v[mid] >= v[lo])
			lo = mid + 1;
	}
	return 0;
}

template<class T>
ll modbsearch(vector<T> &v,T elem, ll low, ll high){
	ll lo = low, hi = high;
	while(lo<=hi){
		ll mid = lo + (hi-lo)/2;	// for large values storing (lo + hi) could lead to overflow
		if(v[mid] == elem) return mid;
		if(elem > v[mid]) lo = mid +1;
		else hi = mid -1; 
	}
	return -1;
}

// Find if a number is present in rotated sorted array.
template<class T>
ll find_rotsort(vector<T> &v, T elem){
	ll idx = num_times_rotated(v); // idx of minimum element
	return max(modbsearch(v,elem,0,idx-1),modbsearch(v,elem,idx,v.size()-1));
}

// Find element in a nearly sorted array.
template<class T>
ll find_nearlysort(vector<T> &v, T elem){
	ll lo = 0, hi = v.size()-1;
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;

		if(v[mid] == elem) return mid;

		if(mid+1 <= v.size()-1)
		if(v[mid+1] == elem) return mid+1;
		
		if(mid-1 >= 0)
		if(v[mid-1] == elem) return mid-1;
		
		if(elem > v[mid]) lo = mid + 2;
		if(elem < v[mid]) hi = mid - 2;
	}
	return -1;
}

// Find the greatest of the smaller number present for an element. (Floor)
template<class T>
ll floor_elem(vector<T> &v, T elem){
	ll lo = 0, hi = v.size() - 1, res = -1;
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;

		if(elem == v[mid]) 
			return v[mid];
		if(elem < v[mid])
			hi = mid - 1;
		if(elem > v[mid]){
			res = max(res,v[mid]);
			lo = mid + 1;
		}
	}
	return res;
}

// Find the smallest of the greater elements present for an element. (Ceil)
template<class T>
ll ceil_elem(vector<T> &v, T elem){
	ll lo = 0, hi = v.size() - 1, res = -1;
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;

		if(elem == v[mid]) 
			return v[mid];
		if(elem < v[mid]){
			res = min(res,v[mid]);
			hi = mid - 1;
		}
		if(elem > v[mid])
			lo = mid + 1;
	}
	return res;
}

// Find the next alphabetical element (ceil + 1).
char next_alpha(vector<char> &v, char elem){
	ll lo = 0, hi = v.size() - 1, res = '#';
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;

		if(elem == v[mid]) 
			lo = mid + 1;
		if(elem < v[mid]){
			res = v[mid];
			hi = mid - 1;
		}
		if(elem > v[mid])
			lo = mid + 1;
	}
	return res;
}

// Searching for element if size of data is uncertain or infinite.
template<class T>
ll bsearch_infi(vector<T> &v,T elem){
	ll lo = 0, hi = 1;
	while(v[hi]<elem){
		lo = hi;
		hi = hi << 1;
	}
	return modbsearch(v,elem,lo,hi);
}

// Search for the first occurence of 1 in a infinite binary(0s ad 1s) sorted array.
// The problem is based on two of the previous smaller problems combined: first_occurence and bsearch_infi.
template<class T>
ll first_1_infi(vector<T> &v, T elem){
	ll lo = 0, hi = 1;
	while(v[hi]<elem){
		lo = hi;
		hi = hi << 1;
	}
	ll res = -1;
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;
		if(elem == v[mid]){
			res = mid;
			hi = mid - 1;
		}
		if(v[mid] > elem)
			hi = mid - 1;
		if(v[mid] < elem)
			lo = mid + 1;
	}
	return res;
}

// Minimum difference element
template<class T>
ll mini_diff(vector<T> &v, T elem){
	ll lo = 0, hi = v.size() - 1, fl = -1, ce;
	while(lo <= hi){
		ll mid = lo + (hi-lo)/2;

		if(elem == v[mid]) 
			return v[mid];
		if(elem < v[mid]){
			ce = min(ce,v[mid]);
			hi = mid - 1;
		}
		if(elem > v[mid]){
			fl = max(fl, v[mid]);
			lo = mid + 1;
		}
	}
	return ce-elem < elem - fl ? ce : fl;
}


void solve(){
	ll n=0,t=0,x=0,k=0,y=0,z=0,a=0,b=0,c=0;
	cin>>n;
	
	vl v;
	REP(i,n){cin>>x; v.pb(x);}
	cin>>k;
	// SORT(v);
	debug(v)
	// cout<<bsearch(v,k)<<endl;
	// RSORT(v);
	// debug(v)
	// cout<<revbsearch(v,k);

	// srand(time(0));		// seeding for rand()
	// t = rand() % 2 + 0; // using rand() to sort randomly for anonymous searching
	// t ? SORT(v) : RSORT(v);
	// cout<<anonysearch(v,k);

	// cout<<first_occurrence(v,k);
	// cout<<last_occurrence(v,k);
	// cout<<count_occurrence(v,k);

	// rotate(v.begin(),v.begin()+(n-k),v.end());
	// cout<<num_times_rotated(v);
	// cout<<find_rotsort(v,k);

	// cout<<find_nearlysort(v,k);
	// cout<<floor_elem(v,k);
	// cout<<ceil_elem(v,k);

	// vector<char> v;
	// char ch,ck;
	// REPN(i,n){cin>>ch; v.pb(ch);}
	// cin>>ck;
	// cout<<next_alpha(v,ck);

	// cout<<bsearch_infi(v,k);
	// cout<<first_1_infi(v,k);

	cout<<mini_diff(v,k);
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