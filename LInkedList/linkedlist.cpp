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
		cout<<tmp->data<<"->";
		tmp = tmp->next;
	}
	cout<<"NULL"<<endl;
}

//INSERTIONS
//
//inserting at tail end
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
//inserting at beginning
void insertAtHead(Node* &head, LL val){
	Node* n = new Node(val);
	n->next = head;
	head = n;
}

//Searching for key
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

//DELETIONS
//
//deleting first element
void deleteAtHead(Node* &head){
	Node* del = head;
	head = head->next;
	delete del;
}
//delete anywhere as per given value
void deletion(Node* &head, LL key){
	if(head==NULL) 
		return;

	Node* tmp = head;
	if(tmp->data == key){
		deleteAtHead(head);
		return;
	}
	if(tmp->next == NULL){
		return;
	}
	while(tmp->next->data!=key && tmp->next!=NULL){
		cout<<tmp->data<<endl;
		tmp = tmp->next;
	}
	if(tmp->next == NULL){
		return;
	}

	Node* del = tmp->next;
	tmp ->next = tmp->next->next;
	delete del;
}

//Reverse linked list
// 1. Iterative way
void reverseLinkedList(Node* &head){
	Node* prev = NULL, *curr = head, *nextptr;

	while(curr!=NULL){
		nextptr = curr->next;
		curr->next = prev;

		prev = curr;
		curr = nextptr;
	}
	// return prev;
	head = prev;
}
//2. Recursive
Node* reverseLinkedListRecursive(Node* head){ 
	if(head == NULL || head->next == NULL) return head;
	Node* newhead = reverseLinkedListRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}

//reverse K nodes
Node* reverseKNodes(Node* &head, LL k){
	Node* prev = NULL, *curr = head, *nextptr;
	int count = 0;
	while(curr!=NULL && count<k){
		nextptr = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextptr;
		count++;
	}
	if(nextptr!=NULL)
	head->next = reverseKNodes(nextptr, k);
	return prev;
}

//Cycle detection
bool detectCycle(Node* head){
	Node* slow = head, *fast = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow ->next;
		fast = fast->next->next;
		if(slow== fast)
			return true;
	}
	return false;
}
//Cycle creation
void makeCycle(Node* &head, int pos){
	Node* tmp = head, *startNode;
	int count = 0;
	while(tmp->next!=NULL){
		if(count == pos)
			startNode = tmp;
		tmp = tmp->next;
		count++;
	}
	tmp->next = startNode;
}
//Remove Cycle
void removeCycle(Node* &head){
	Node* fast = head, *slow = head;
	do{
		slow = slow->next;
		fast = fast->next->next;
	}while(slow!=fast);

	fast = head;
	while(slow->next != fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;
}

void solve(){
	LL n,x;
	cin>>n;
	Node* head = NULL;
	TC(n){
		cin>>x;
		insertAtTail(head,x);
	}
	display(head);
	LL key;
	cin>>key;

	// if(search(head,key)) cout<<"Element found";
	// else cout<<"Element not found";
	// deletion(head,key);
	// display(head);

	// reverseLinkedList(head);

	// head = reverseLinkedListRecursive(head);
	// display(reverseLinkedListRecursive(head));

	// head = reverseKNodes(head,key);

	makeCycle(head,key);
	if(detectCycle(head)) cout<<"Cycle present";
	else cout<<"Cycle not present";
	removeCycle(head);
	cout<<endl;
	display(head);
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