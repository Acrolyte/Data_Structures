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

class Node{
public:
	LL data;
	Node* next;
	Node(LL val){
		data = val;
		next = NULL;
	}
};

//printing linked list
void display(Node* head){
	Node* tmp = head;
	while(tmp!=NULL){
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}

//inserting at beginning
void insertAtTail(Node* &head, LL val){

	Node* n = new Node(val);
	if(head == NULL) {
		head = n;
		return;
	}
	Node* tmp = head;
	while(tmp->next != NULL){
		tmp = tmp ->next;
	}
	tmp->next = n;
}

void insertAtHead(Node* &head, LL val){
	Node* n = new Node(val);
	n->next = head;
	head = n;
}

bool search(Node* head, LL key){
	Node* tmp = head;
	while(tmp!=NULL){
		if(tmp->data == key){
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void solve(){
	LL n,x;
	cin>>n;
	Node* head = NULL;
	TC(n){
		cin>>x;
		insertAtHead(head,x);
	}
	display(head);
	LL key;
	cin>>key;

	if(search(head,key)) cout<<"Element found";
	else cout<<"Element not found";
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin>>t;
    //TC(t)
    solve();

	return 0;
}