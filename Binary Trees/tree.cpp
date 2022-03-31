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
	Node* left;
	Node* right;

	Node(LL val){
		data = val;
		left = NULL;
		right = NULL;
	}
};


// TRAVERSALS
//
// Pre-Order Traversal (Root->Left->Right)
void preOrder(Node* root){
	if(root== NULL) return ;
	cout<<root->data<<' ';
	preOrder(root->left);
	preOrder(root->right);
}
//
// In-Order Traversal (Left->Root->Right)
void inOrder(Node* root){
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->data<<' ';
	inOrder(root->right);
}
//
// Post-Order Traversal (Left->Right->Root)
void postOrder(Node* root){
	if(root== NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<' ';
}
//
// Level-Order Traversal
vl levelOrder(Node* root){
	vl v;
	queue<Node*> q;
	q.push(root);
	q.push(NULL); //better implementation of level order

	while(!q.empty()){
		Node* tmp = q.front();
		v.pb(tmp->data);
		q.pop();

		if(tmp != NULL){
			if(tmp->left) q.push(tmp->left);
			if(tmp->right) q.push(tmp->right);
		}
		else if(!q.empty())
			q.push(NULL);
	}
	return v;
}

// Reverse Level-Order Traversal
void reverseLevelOrder(Node* root){
	vl v;
	queue<Node*> q;
	stack<Node*> s;
	q.push(root);

	while(!q.empty()){
		root = q.front();
		q.pop();
		s.push(root);
		if(root->right) q.push(root->right);
		if(root->left) q.push(root->left);
	}
	while(!s.empty()){
		root = s.top();
		cout<<root->data<<' ';
		s.pop();
	}
}

// InOrder, PreOrder, PostOrder in single Traversal
void singleTraversal(Node* root, vl &ino,vl &pos, vl &pre){
	if(root == NULL) return;
	pre.pb(root->data);
	singleTraversal(root->left,ino,pos,pre);
	ino.pb(root->data);
	singleTraversal(root->right,ino,pos,pre);
	pos.pb(root->data);
}

// Sum of all Nodes at K-th Level
LL sumAtK(Node* root, LL k){
	if(root == NULL) return -1;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	LL lvl = 0;
	LL sum = 0;

	while(!q.empty()){
		Node* node = q.front();
		q.pop();

		if(node != NULL){
			if(lvl == k){
				sum += node->data;
			}
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		else if(!q.empty()){
			q.push(NULL);
			lvl++;
		}
	}
	return sum;
}

// Utility Functions
LL search(vl v, LL start, LL end, LL curr){
	for(LL i=start;i<=end;i++){
		if(v[i] == curr) return i;
	}
	return -1;
}

// Tree Constructions
//
// Using Pre-Order and In-Order
Node* buildTreeUsingPreAndIn(vl preOrd, vl inOrd, LL start, LL end){
	static LL idx = 0;

	if(start>end) return NULL;

	LL curr = preOrd[idx];
	idx++;
	
	Node* node = new Node(curr);

	if(start == end) return node;

	LL pos = search(inOrd,start,end,curr);
	node->left = buildTreeUsingPreAndIn(preOrd,inOrd,start,pos-1);
	node->right = buildTreeUsingPreAndIn(preOrd,inOrd,pos+1, end);

	return node;
}
//
// Using Post-Order and In-Order
Node* buildTreeUsingPostAndIn(vl postOrd, vl inOrd, LL start, LL end){
	static LL idx = postOrd.size()-1;

	if(start>end) return NULL;

	LL curr = postOrd[idx];
	idx--;

	Node* node = new Node(curr);

	if(start == end) return node;
	LL pos = search(inOrd, start, end , curr);
	node->right = buildTreeUsingPostAndIn(postOrd,inOrd,pos+1,end);
	node->left = buildTreeUsingPostAndIn(postOrd,inOrd,start,pos-1);
	return node;
}


// Height of a tree
//
LL height(Node* root){
	if(root== NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

// MIRROR of a binary tree
void mirror(Node* &root){
	if(root == NULL) return;
	Node* tmp = root;
	swap(tmp->left, tmp->right);
	if(tmp->left) mirror(tmp->left);
	if(tmp->right) mirror(tmp->right);
}

// Diameter of a tree
LL diameter(Node* root, LL &ans){
	LL lh = 0, rh = 0, ld = 0, rd = 0;
	if(root==NULL){ ans = 0; return 0;}
	ld = diameter(root->left, lh);
	rd = diameter(root->right, rh);
	ans = max(lh,rh) + 1;
	return max(lh+rh+1, max(ld,rd));
}

//  Count total number of Nodes
LL countNodes(Node* root){
	if(root== NULL) return 0;
	return 1+countNodes(root->left)+countNodes(root->right);
}

// Sum of all Nodes
LL sumNodes(Node* root){
	if(root == NULL) return 0;
	return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Modify every node in a tree to contain the sum of its child nodes with its own sum
void sumReplacement(Node* &root){
	if(root == NULL) return ;
	sumReplacement(root->left);
	sumReplacement(root->right);
	if(root->left)
	root->data += root->left->data;
	if(root->right)
	 root->data += root->right->data;
	// return root->data;
}

// Check if a binary tree is balanced or not
// A binary tree is balance iff for every node difference of the heights of its subtrees is less than or equal to 1.
int checkbalance(Node* root){
	if(root == NULL) return 0;
	
	LL lheight = checkbalance(root->left);
	if(lheight == -1) return -1;
	LL rheight = checkbalance(root->right);
	if(rheight == -1) return -1;

	if(abs(lheight-rheight)>1) return -1;
	return 1+max(lheight,rheight);
}

bool balance(Node* root){
	return checkbalance(root) != -1;
}

// 
//

void solve(){
	// Node* root = new Node(1);
	// root->left = new Node(2);
	// root->right = new Node(3);
	// root->left->left = new Node(4);
	// root->left->right = new Node(5);
	// root->right->left = new Node(6);
	// root->right->right = new Node(7);

	// preOrder(root);
	// inOrder(root);
	// postOrder(root);

	LL n,x;
	cin>>n;
	vl preOrd;
	REP(i,n) {
		cin>>x;
		preOrd.pb(x);
	}
	vl inOrd;
	REP(i,n){
		cin>>x;
		inOrd.pb(x);
	}

	Node* root = buildTreeUsingPreAndIn(preOrd,inOrd,0,n-1);
	// inOrder(root);
	// cout<<height(root);
	// vl v = levelOrder(root);
	// FOREACH(i,v) cout<<i<<' ';
	// cout<<'\n';
	// mirror(root);
	// inOrder(root);

	// LL di = 0;
	// cout<<endl<<"diameter = "<<diameter(root,di)<<endl;

	// Node* root = buildTreeUsingPostAndIn(preOrd,inOrd,0,n-1);
	// preOrder(root);

	// cout<<countNodes(root);
	// cout<<sumNodes(root);

	// cout<<sumAtK(root,3);
	// sumReplacement(root);
	// inOrder(root);

	// vl pre,ino,pos;
	// singleTraversal(root,ino,pos,pre);
	// cout<<"\ninOrder=> ";
	// FOREACH(i,ino) cout<<i<<' ';
	// cout<<"\npreOrder=> ";
	// FOREACH(i,pre) cout<<i<<' ';
	// cout<<"\npostOrder=> ";
	// FOREACH(i,pos) cout<<i<<' ';

	// if(balance(root)) cout<<"Tree is Balanced\n";
	// else cout<<"Tree is unbalanced\n";

	reverseLevelOrder(root);
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