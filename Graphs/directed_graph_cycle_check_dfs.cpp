#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> v[], int vis[])

bool isCyclic(int n, vector<int> v[]){
	int vis[n], dfsvis[n];
	memset(vis, 0, sizeof vis);
	memset(dfsvis, 0, sizeof dfsvis);

	for(int i=0;i<N;i++){
		if(!vis[i]){
			if(checkCycle(i, v, vis, dfsvis))
				return true;
		}
	}
	return false;
}

int main(){

	int n,m;
	cin>>n>>m;

	vector<int> v[n];

	int i,x,y,j;
	for (i = 0; i < m; ++i){
		cin>>x>>y;
		v[x].push_back(y);
	}
	i =0;
	for(auto it : v){
		cout<<i<<' ';
		for(auto it2 : v[i])
			cout<<it2<<' ';
		cout<<'\n';
		i++;
	}
	
	if(isCyclic(n,v))
		cout << "Cyclic";
	else cout << "Not Cyclic";
	return 0;
}