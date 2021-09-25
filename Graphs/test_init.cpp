#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	vector<int> v[n+1];

	int i,x,y,j;
	for (i = 0; i < m; ++i){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	i=0;
	for(auto it: v){
		cout<<i<<' ';
		for(auto h: it)
			cout<<h<<' ';
		cout<<'\n';
		i++;
	}
	return 0;
}