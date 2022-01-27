#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define rept(i,n) for (i = n; i > 0; --i)
#define ll long long int

//sum of first n natural numbers
ll sumOfN(ll n){
	return (n*(n+1))/2;
}

//to check pythagorean triplet
bool pytho(int x,int y,int z){
	int a = max(x,max(y,z));
	int b,c;
	
	if(a==x){b=y; c=z;}
	else if(a==y){b=x; c=z;}
	else {b=x;c=y;}

	if(a*a == b*b + c*c) return true;
	return false;
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(pytho(a,b,c)) cout<<"pytho";
	else cout<<"not pytho";
	return 0;
}