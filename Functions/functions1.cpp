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

//binary, octal, hexadecimal to decimal
int todecimal(string s,int n){
	char a[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int l = s.size()-1, sum=0;
	for(auto i : s){
		auto itr = find(a,a+16,i);
		cout<<(itr-a)<<' ';
		sum += (itr-a)*pow(n,l);
		l--;
	}
	cout<<endl;
	return sum;
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<todecimal(to_string(a),b);
	return 0;
}