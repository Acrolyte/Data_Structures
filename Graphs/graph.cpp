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
//debugger
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x << ' '<< x << '\n';
#else
#define debug(x)
#endif

// DISPLAY GRAPH
void display(vl adj[], ll n){
	REPN(i,n){
		cout<<i<<"=> ";
		for(auto j: adj[i])
			cout<<j<<' ';
		cout<<endl;
	}
}

// ADD EDGE TO GRAPH
void addEdge(vl adj[], ll u, ll v){
	adj[u].pb(v);
	adj[v].pb(u);
}

//-------------------------------------------- TRAVERSALS-------------------------------------------
//
// 1. BREADTH-FIRST-SEARCH
//
void bfs(vl adj[], ll n){
	vl bft;
	vl vis(n+1,0);

	REPN(i,n){
		if(!vis[i]){

			queue<ll> q;
			q.push(i);
			vis[i] = 1;

			while(!q.empty()){
				ll node = q.front();
				q.pop();
				bft.pb(node);

				for(auto it: adj[node]){

					if(!vis[i]){
						q.push(it);
						vis[it] = 1;
					}
				}
			}
		}
	}
	for(auto it: bft) 
		cout<<it<<' ';
}
//
// 2. DEPTH-FIRST-SEARCH
//
void dfsUtil(ll node, vl &vis, vl adj[], vl &dft){

	dft.pb(node);
	vis[node] = 1;
	for(auto it : adj[node]){
		if(!vis[it])
			dfsUtil(it, vis, adj, dft);
	}
}

void dfs(vl adj[], ll n){
	vl dft;
	vl vis(n+1, 0);
	REPN(i,n){
		if(!vis[i]){
			dfsUtil(i, vis, adj, dft);
		}
	}
	for(auto it: dft)
		cout<<it<<' ';
}
//----------------------------------------------------------------------------------------------------



void solve(){
	ll n;
	cin>>n;

	//using adjaceny matrix
	// ll adjmat[n+1][m+1];

	ll edges;
	cin>>edges;

	// REP(i,edges){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	adjmat[u][v] = 1;
	// 	adjmat[v][u] = 1;
	// }

	//using Adjacency list
	vl adj[n+1];
	REPN(i,edges){
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}
	// cout<<'k';
	// display(adj,n);
	bfs(adj,n);
	cout<<endl;
	dfs(adj,n);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("Error.in","w",stderr);
	#endif
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin>>t;
    //TC(t)
    solve();

	return 0;
}
