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

//count the number of nodes in a linkedlist
LL countNodes(Node* &head){
	Node *tmp = head;
	LL count = 0;
	while(tmp!=NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}

//append last K nodes to the start of linkedlist
void appendLastKtoStart(Node* &head, LL k){

	Node* newhead, *newTail, *tail = head;
	LL len = countNodes(head);
	LL count = 1;
	k = k % len;
	while(tail->next != NULL){
		if(count == len - k)
			newTail = tail;
		if(count == len - k + 1)
			newhead = tail;
		tail = tail ->next;
		count++;
	}	
	tail->next = head;
	newTail ->next = NULL;
	head = newhead;
}

//intersect two linkedlists manually
void intersect(Node* &head1, Node* &head2, LL k){
	Node* tmp1 = head1;
	k--;
	TC(k) tmp1 = tmp1 ->next;
	Node* tmp2 = head2;
	while(tmp2->next!=NULL){
		tmp2 = tmp2 ->next;
	}
	tmp2->next = tmp1;
}

//find the intersectoin of two linkedlist
void intersectionPoint(Node* &head1, Node* &head2){
	LL l1 = countNodes(head1);
	LL l2 = countNodes(head2);
	LL d = 0;
	Node* ptr1, *ptr2;
	if(l1>l2){
		d = l1 - l2;
		ptr1 = head1;
		ptr2 = head2;
	}
	else {
		d = l2 - l1;
		ptr1 = head2;
		ptr2 = head1;
	}

	TC(d){ 
		ptr1 = ptr1->next;
		if(ptr1 == NULL){
			cout<<"No Intersection!!\n";
			return;
		}
	}

	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1 == ptr2){
			cout<<ptr1->data<<" is the intersection Point\n";
			return;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2 ->next;
	}
	cout<<"No Intersection!!\n";
}

//merge two sorted linkedlist (itearative way)
Node* mergelists(Node* &head1, Node* &head2){
	Node* p1 = head1, *p2 = head2, *dummyNode = new Node(-1);
	Node* p3 = dummyNode;

	while(p1!=NULL && p2!=NULL){
		if(p1->data < p2->data){
			p3->next = p1;
			p1 = p1->next;
		}
		else {
			p3 ->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
	}
	while(p1!=NULL){
		p3->next = p1;
		p1 = p1->next;
		p3 = p3 ->next;
	}
	while(p2!=NULL){
		p3->next = p2;
		p2 = p2->next;
		p3 = p3->next;
	}
	return dummyNode->next;
}

//merge two linked lists (recursive way)
Node* mergelistsRecursive(Node* &head1, Node* head2){

	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
	Node* result;
	if(head1->data < head2->data){
		result = head1;
		result->next = mergelistsRecursive(head1->next,head2);
	}
	else{
		result = head2;
		result->next = mergelistsRecursive(head1,head2->next);
	}
	return result;
}

//Question: Put elements at even postion after the elements at odd position
void evenAfterOdd(Node* &head){
	Node* odd = head;
	Node* even = head->next;
	Node* evenStart = even;
	while(odd->next!=NULL && even->next!=NULL){
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenStart;
	if(odd->next!=NULL) even->next = NULL;
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
	deletion(head,key);
	display(head);

	// reverseLinkedList(head);

	// head = reverseLinkedListRecursive(head);
	// display(head);
	// display(reverseLinkedListRecursive(head));

	// head = reverseKNodes(head,key);

	// makeCycle(head,key);
	// if(detectCycle(head)) cout<<"Cycle present";
	// else cout<<"Cycle not present";
	// removeCycle(head);
	// cout<<endl;

	// appendLastKtoStart(head , key);

	// Node* head2 = NULL;
	// LL n2;
	// cin>>n2;
	// TC(n2){
	// 	cin>>x;
	// 	insertAtTail(head2,x);
	// }
	// intersect(head,head2,key);
	// intersectionPoint(head,head2);

	// display(head);
	// display(head2);

	// Node* newhead = mergelistsRecursive(head,head2);
	// display(newhead);

	// evenAfterOdd(head);
	// display(head);
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