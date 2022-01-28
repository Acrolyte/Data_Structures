#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define rept(i,n) for (i = n; i > 0; --i)
#define ll long long

int partition(vector<int> &A, int p, int r){
	int x = A[r];
	int i = p-1;
	for(int j = p; j<=r-1; j++){
		if(A[j] <= x){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}
void quick_sort(vector<int> &A, int p, int r){
	if(p<r){
		int q = partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
	else return;
}

int main(){

	int n,i;
	cin>>n;

	vector<int> a;
	rep(i,n){
		int x;
		cin>>x;
		a.push_back(x);
	}
	quick_sort(a,0,n);
	for(auto it: a) cout<<it<<' ';
	return 0;
}