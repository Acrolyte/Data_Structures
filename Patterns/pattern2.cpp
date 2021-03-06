#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define rept(i,n) for (i = n; i > 0; --i)
#define ll long long

//to print inverted pattern
// For n = 5
// 1 
// 2 1 
// 3 2 1 
// 4 3 2 1 
// 5 4 3 2 1 
void invertedPattern(int n){
	for(int i=1;i<=n;i++){
		for(int j=i;j>0;j--){
			cout<<j<<' ';
		}
		cout<<'\n';
	}
}

//to print 0-1 pattern
// For n = 5
// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 
// 1 0 1 0 1 
void zeroOnePattern(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if((i+j)%2 == 0)
				cout<<1<<' ';
			else cout<<0<<' ';
		}
		cout<<'\n';
	}
}

//to print Rhombus Pattern
// For n = 5
//      * * * * * 
//     * * * * * 
//    * * * * * 
//   * * * * * 
//  * * * * * 
void RhombusPattern(int n,char ch){
	int i,j;
	for(i=n-1;i>=0;i--){
		for(j=0;j<=i;j++)
			cout<<' ';
		for(j=0;j<n;j++)
			cout<<ch<<' ';
		cout<<'\n';
	}
}

//to print Number Triangle Pattern
// For n = 5
//     1 
//    1 2 
//   1 2 3 
//  1 2 3 4 
// 1 2 3 4 5 
void numberTrianglePattern(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=n-i;j>0;j--)
			cout<<' ';
		for(j=1;j<=i;j++){
			cout<<j<<' ';
		}
		cout<<'\n';
	}
}

//to print Palindromic Pattern
// For n = 5
//         1 
//       2 1 2 
//     3 2 1 2 3 
//   4 3 2 1 2 3 4 
// 5 4 3 2 1 2 3 4 5 
void PalindromicPattern(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=n-i;j>0;j--)
			cout<<"  ";
		for(j=i;j>0;j--)
			cout<<j<<' ';
		for(j=2;j<=i;j++)
			cout<<j<<' ';
		cout<<'\n';
	}
}

//to print Star Pattern
// For n = 4
//       * 
//     * * * 
//   * * * * * 
// * * * * * * * 
// * * * * * * * 
//   * * * * * 
//     * * * 
//       * 
void starPattern(int n,char ch){
	int i,j;
	for(i=0;i<n;i++){
		for(j=n-i-1;j>0;j--)
			cout<<"  ";
		for(j=0;j<2*i+1;j++)
			cout<<ch<<' ';
		cout<<'\n';
	}
	for(i=n-1;i>=0;i--){
		for(j=n-i-1;j>0;j--)
			cout<<"  ";
		for(j=0;j<2*i+1;j++)
			cout<<ch<<' ';
		cout<<'\n';
	}
}

//to print zig-zag pattern
// For n = 9
//   *   *  
//  * * * * 
// *   *   *
void zigzag(int n){
	int i,j;
	for(i=1;i<=3;i++){
		for(j=1;j<=n;j++){
			if((i+j)%4==0 || (i==2 && j%4==0))
				cout<<'*';
			else cout<<' ';
		}
		cout<<'\n';
	}
}


//to print Pascal's Triangle
// For n = 5
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 
int fact(int n){
	if(n==0) return 1;
	return n*fact(n-1);
}
void pascalTriangle(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			cout<<fact(i)/(fact(j)*fact(i-j))<<' ';
		}
		cout<<'\n';
	}
}

int main(){
	int n;
	char ch;
	cin>>n>>ch;
	pascalTriangle(n);
	return 0;
}