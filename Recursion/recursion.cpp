#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
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

//Basics
void printNameNTimes(LL idx,LL n, string s){
	if(idx==n)return;
	cout<<s<<'\n';
	printNameNTimes(idx+1,n,s);
}

void numbers1toN(LL idx,LL n){
	if(idx > n) return;
	cout<<idx<<'\n';
	numbers1toN(idx+1,n);
}

void numbersNto1(LL n){
	if(n < 1)return;
	cout<<n<<'\n';
	numbersNto1(n-1);
}

//Backtracking basics
void BTnumbers1toN(LL idx,LL n){
	if(idx < 1) return;
	BTnumbers1toN(idx-1,n);
	cout<<idx<<'\n';
}
void BTnumbersNto1(LL idx, LL n){
	if(idx > n) return;
	BTnumbersNto1(idx+1,n);
	cout<<idx<<'\n';
}

//Parameterised Recursion
void sumOfN_numbers(LL idx,LL sum){
	if(idx < 1){
	cout<<sum;
	return;
	}
	sumOfN_numbers(idx-1,sum+idx);
}
//Functional Recursion
LL sumOfN_numbers(LL n){
	if(n==0) return 0;
	return n+sumOfN_numbers(n-1);
}

void facto(LL idx,LL mul){
	if(idx<=1){
		cout<<mul<<'\n';
		return;
	}
	facto(idx-1,mul*idx);
}

//parameterised 
void reverse_an_array_two_pointers(vi &v,LL l, LL r){
	if(l>=r) return;
	swap(v[l],v[r]);
	reverse_an_array_two_pointers(v,l+1,r-1);
}

//functional
void reverse_an_array(vi &v, LL idx, LL n){
	if(idx >= n/2) return;
	swap(v[idx],v[n-idx-1]);
	reverse_an_array(v,idx+1,n);
}

bool check_palindrome(string s,LL idx,LL n){
	if(idx >= n/2) return true;
	if(s[idx] != s[n-idx-1])return false;
	return check_palindrome(s,idx+1,n);
}

//multiple function calls
LL fibbonacci(LL n){
	if(n==0) return 0;
	if(n==1) return 1;
	return fibbonacci(n-1)+fibbonacci(n-2);
}

//printing subsequences (Can also be done by Bit Manipulation)
void printSubs(LL idx, vector<char> v, string s){
	if(idx >= s.length()){
		for(auto i : v) cout<<i;
			cout<<'\n';
			return;
	}
	v.pb(s[idx]);
	printSubs(idx+1, v, s);
	v.pop_back();
	printSubs(idx+1,v,s);
}

//printing subsequences whose sum is K
void printSubsIsK(LL idx,vi &v2, vi &v, LL sum, LL k){
	if(idx >= v.size()){
		if(sum == k){
			for(auto i: v2) cout<<i<<' ';
				cout<<'\n';
		}
		return;
	}
	v2.pb(v[idx]);
	printSubsIsK(idx+1,v2,v,sum+v[idx],k);
	v2.pop_back();
	printSubsIsK(idx+1,v2,v,sum,k);
}

//print any one subsequence whose sum is K
bool printOneSubsSumIsK(LL idx, vi &v2, vi &v, LL sum, LL k){
	if(idx >= v.size()){
		if(sum == k){
			for(auto i: v2)cout << i<<' ';
				cout<<'\n';
			return true;
		}
		return false;
	}
	v2.pb(v[idx]);
	if(printOneSubsSumIsK(idx+1,v2,v,sum+v[idx],k)) return true;
	v2.pop_back();
	if(printOneSubsSumIsK(idx+1,v2,v,sum,k)) return true;
	return false;
}

//prints the total no. of sum subsequences whose sum is k
LL printNoOfSubsSumIsK(LL idx, vi &v, LL sum, LL k){
	
	if(idx >= v.size()){
		if(sum == k){
			return 1;
		}
		else return 0;
	}

	
	LL l = printNoOfSubsSumIsK(idx+1,v,sum+v[idx],k);
	
	sum += v[idx];

	sum -= v[idx];

	LL r = printNoOfSubsSumIsK(idx+1,v,sum,k);
	return l+r;
}

//prints combinations of numbers whose sum is provided (Nos are repeated)
void combinationSum(vi &v,vi &v2, LL idx, LL sum){
	if(idx==v.size()){
		if(sum <=0){
			for(auto i:v2)
				cout<<i<<' ';
			cout<<'\n';
		}
		return;
	}
	if(v[idx] <= sum){
		v2.pb(v[idx]);
		combinationSum(v,v2,idx,sum-v[idx]);
		v2.pop_back();
	}
	combinationSum(v,v2,idx+1,sum);
}

//prints combination of numbers whose sum is provided (Nos should not be repeated when calculating the sum)  
void combinationSum2(vi &v, vi &v2, LL idx, LL sum, vvi &ans){
	if(sum == 0){
		ans.pb(v2);
		return;
	}
	for(LL i = idx; i<v.size();i++){
		if(i>idx && v[i] == v[i-1]) continue;
		if(v[i] > sum) break;
		v2.pb(v[i]);
		combinationSum2(v,v2,i+1,sum-v[i],ans);
		v2.pop_back();
	}
}

void solve(){
	LL n,x;
	cin>>n;
	string s;
	cin>>s;
	vi v;
	REP(i,n){cin>>x;v.pb(x);}
	LL k;
	cin>> k;
	vi v2; //Data Structure being used

	// printNameNTimes(0,n,s);
	// numbers1toN(1,n);
	// numbersNto1(n);
	// BTnumbers1toN(n,n);
	// BTnumbersNto1(1,n);
	// sumOfN_numbers(n,0);
	// cout<<sumOfN_numbers(n);
	// facto(n,1);
	
	// reverse_an_array_two_pointers(v,0,n-1);
	// for(auto i: v)cout<<i<<' ';

	// reverse_an_array(v,0,n);
	// for(auto i: v)cout<<i<<' ';

	// if(check_palindrome(s,0,n)) cout<<"palin";else cout<<"not palin";
	
	// cout<<fibbonacci(n);
	// vector<char> v2;
	// printSubs(0,v2,s);

	// for(auto i: v) cout<<i<<' ';
	
	// printSubsIsK(0,v2,v,0,k);
	// printOneSubsSumIsK(0,v2,v,0,k);
	// cout<<printNoOfSubsSumIsK(0,v,0,k);

	// combinationSum(v,v2,0,k);

	SORT(v);
	vvi ans;
	combinationSum2(v,v2,0,k,ans);
	FOREACH(i,ans){
		FOREACH(j,i) cout<<j<<' ';
		cout<<'\n';
	}


}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();

	return 0;
}