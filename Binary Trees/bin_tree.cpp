#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

//Traversals
void post_order_tra(struct node* root){
	if(root==NULL)	return;

	else{
		post_order_tra(root->left);
		post_order_tra(root->right);
		int dat = root->data;
		printf("%d ",dat);
	}
}
void pre_order_tra(struct node* root){
	if(root==NULL)	return;

	else{
		cout<<root->data<<" ";
		pre_order_tra(root->left);
		pre_order_tra(root->right);
		
	}
}
void in_order_tra(struct node* root){
	if(root==NULL)	return;

	else{
		in_order_tra(root->left);
		cout<<root->data<<" ";
		in_order_tra(root->right);
		
	}
}
//Height of Tree
int height(struct node* root){
	if(root == NULL) return -1;
	else{
		int left = height(root->left);
		int right = height(root->right);
		return 1+max(left,right);
	}
}
//Sum of all nodes
int sum_of_all_nodes(struct node* root){
	if(root == NULL)
		return 0;
	else{
		int left = sum_of_all_nodes(root->left);
		int right = sum_of_all_nodes(root->right);
		return root->data+left+right;
	}
}
//Maximum element
int maxim(struct node* root){
	if(root==NULL) return 0;
	else{
		int left = maxim(root->left);
		int right = maxim(root->right);
		return max(root->data,max(left,right));
	}
}
//Minimum element
int minim(struct node* root){
	if(root==NULL) return INT_MAX;
	else{
		int left = minim(root->left);
		int right = minim(root->right);
		return min(root->data,min(left,right));
	}
}
//Level Order traversal
void LevelOrderRec(struct node* root, int i){
	if(root == NULL) return;
	else if(i==1) cout<<root->data<<' ';
	else if(i>1){
		LevelOrderRec(root->left,i-1);
		LevelOrderRec(root->right,i-1);
	}
}

void LevelOrderTraversal(struct node* root){
	int h = height(root);
	int levels = h+1;
	int i;
	for(i=1;i<=levels;i++){
		LevelOrderRec(root, i);
		cout<<'\n';
	}
}

//Level order traversal using queue
void printLevelTraversal(struct node* root){
	if(root == NULL) return;

	queue<struct node*> q;

	q.push(root);

	while(!q.empty()){
		struct node* nod = q.front();
		cout<<nod->data << " ";
		q.pop();
		if(nod->left!= NULL) q.push(nod->left);
		if(nod->right!= NULL) q.push(nod->right);
	}
}

int main()
{
	struct node* n1 = (struct node*)malloc(sizeof(struct node));
	struct node* n2 = (struct node*)malloc(sizeof(struct node));
	struct node* n3 = (struct node*)malloc(sizeof(struct node));
	struct node* n4 = (struct node*)malloc(sizeof(struct node));
	struct node* n5 = (struct node*)malloc(sizeof(struct node));
	struct node* n6 = (struct node*)malloc(sizeof(struct node));
	struct node* n7 = (struct node*)malloc(sizeof(struct node));

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;

	n1->left = n2;
	n2->left = n4;
	n3->left = n6;
	n4->left = NULL;
	n5->left = NULL;
	n6->left = NULL;
	n7->left = NULL;

	n1->right = n3;
	n2->right = n5;
	n3->right = n7;
	n4->right = NULL;
	n5->right = NULL;
	n6->right = NULL;
	n7->right = NULL;


	// LevelOrderTraversal(n1);
	printLevelTraversal(n1);

	return 0;
}