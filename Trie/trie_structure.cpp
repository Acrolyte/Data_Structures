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


// Implementation of TRIE

// Node
struct Node
{
	Node* links[26];
	bool flag = false;
	bool containsKey(char ch){
		return (links[ch-'a'] != NULL);
	}
	void put(char ch, Node* node){
		links[ch - 'a'] = node;
	}
	Node* get(char ch){
		return links[ch-'a'];
	}
	void setEnd(){
		flag = true;
	}
	bool isEnd(){
		return flag;
	}
};

// Trie Class
class Trie
{
private:
	Node* root;
public:
	Trie(){
		root = new Node();
	}

	void insert(string word){
		Node* node = root;
		for(ll i=0;i<word.size();i++){
			if(!node->containsKey(word[i])){
				node->put(word[i],new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word){
		Node* node = root;
		for(int i=0;i<word.size();i++){
			if(!node->containsKey(word[i]))
				return false;
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string word){
		Node* node = root;
		for(int i=0;i<word.length();i++){
			if(!node->containsKey(word[i]))
				return false;
			node = node->get(word[i]);
		}
		return true;
	}
};

void solve(){
	ll n=0,t=0,x=0,k=0,y=0,z=0,a=0,b=0,c=0;
	cin>>n;
	string s;

	Trie trie;

	TC(n){
		cin>>x>>s;
		if(x==1) trie.insert(s);
		else if(x==2) if(trie.search(s)) cout << "Yes\n" ; else cout << "No\n";
		else if(x==3) if(trie.startsWith(s)) cout << "Yes\n" ; else cout << "No\n";
	}
	
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