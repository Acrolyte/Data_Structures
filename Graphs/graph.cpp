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

struct Edge
{
	ll src,dest;
};

class Graph
{
public:
	vector<vector<ll>> adjList;
	
	Graph(vector<Edge> const &edges, ll n){
		adjList.resize(n+1);

		for(auto &edge: edges){
			adjList[edge.src].push_back(edge.dest);
			
			// Uncomment for undirected graph
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

void printGraph(Graph const &g, ll n){
	REPN(i,n){
		cerr << i << " => ";
		for(auto v: g.adjList[i])
			cerr << v << " ";
		cerr << endl;
	}
}

// --------------------------------------------------------TRAVERSALS-------------------------------------------------------------
// 
// DEPTH FIRST SEARCH
//
void dfs(Graph const &g,bool vis[], ll vtx){
	// Entering vertex
	//
	if(vis[vtx]) return; // Base condition
	cerr << vtx << ' ';
	vis[vtx] = true;
	for(auto child: g.adjList[vtx]){
		// if(vis[child]) continue; // can also be used instead of base condition.

		// Entering child
		dfs(g,vis,child);
		// Exiting child
	}
	//
	// Exiting vertex
}
//
// BREADTH FIRST SEARCH
//
void bfs(Graph const &g,ll vtx){
	queue<
}



void solve(){
	ll n=0,t=0,x=0,k=0,y=0,z=0,a=0,b=0,c=0;
	cin>>n>>t;
	vector<Edge> edges;

	TC(t){
		cin>>a>>b;
		edges.pb({a,b});
	}

	Graph g(edges,n);
	// g.printGraph();
	// printGraph(g,n);

	bool vis[n]; // visited array
	RESET(vis,0);

	// Traversals
	dfs(g,vis,1);


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