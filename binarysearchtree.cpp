//Binary Search Tree
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left; 
	Node* right;
};

struct BSTree {
	Node* root;
};

void NLR(Node* cur) {
	if (cur == NULL) return;
	cout << cur->data << " ";
	NLR(cur->left);
	NLR(cur->right);
}

void LNR(Node* cur) {
	if (cur == NULL) return;
	LNR(cur->left);
	cout << cur->data << " ";
	LNR(cur->right);
}

void LRN(Node* cur) {
	if (cur == NULL) return;
	LRN(cur->left);
	LRN(cur->right);
	cout << cur->data << " ";
}

void Init(BSTree &t) {
	t.root = NULL; 
}

Node* CreateNewNode(int value) {
	Node* newNode = new Node;
	if (newNode == NULL)return NULL;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

bool isEmpty(BSTree t) {
	if (t.root == NULL) return true;
	return false;
}

Node* SearchNode(Node* cur, int value) {
	if (cur == NULL) return NULL; 
	if (cur->data == value) return cur; 
	else if (value < cur->data)return SearchNode(cur->left, value);
	else return SearchNode(cur->right, value);
}

void InsertNode(Node*& cur, int newValue) {
	if (cur == NULL) {
		cur = CreateNewNode(newValue);
		return;
	}
	if (newValue < cur->data) return InsertNode(cur->left, newValue);
	else if (newValue > cur->data) return InsertNode(cur->right, newValue);
	else return;
}

Node* SearchStandFor(Node*& p, Node* cur) {
	if (p->right != NULL) return SearchStandFor(p->right, cur);
	cur->data = p->data;
	Node* tmp = p;
	p = p->left; // Save the left sub-branch
	return tmp;
}

void Delete(Node*& cur) {
	Node* tmp = cur;
	if (cur->right == NULL) cur = cur->left;
	else if (cur->left == NULL) cur = cur->right;
	else tmp = SearchStandFor(cur->left, cur);
	delete tmp;
}

void DeleteNode(Node*& cur, int value) {
	if (cur == NULL) return; // Not Found
	if (value < cur->data) // Find the element on left subtree
		return DeleteNode(cur->left, value);
	else if (value > cur->data) // Find the element on right subtree
		return DeleteNode(cur->right, value);
	Delete(cur);
	return;
}

int degreeNode(Node* root, int value,int &degree) {
	if (root == NULL)return 0;
	if (value < root->data) {
		degree++;
		return degreeNode(root->left, value,degree);
	}
	else if (value > root->data) {
		degree++;
		return degreeNode(root->right, value,degree);
	}
	else {
		return degree;
	}
}

int getLeaf_num(Node* root) {
	int n = 0;
	if (root == NULL)return 0;
	if (root->left == NULL && root->right == NULL)return 1;
	if (root->left != NULL) {
		n = getLeaf_num(root->left);
	}
	if (root->right != NULL) {
		n = n + getLeaf_num(root->right);
	}
	return n;
}



int main() {
	BSTree t;
	Init(t);
	InsertNode(t.root, 10);
	InsertNode(t.root, 3);
	InsertNode(t.root, 12);
	InsertNode(t.root, 2);
	InsertNode(t.root, 5);
	InsertNode(t.root, 11);
	InsertNode(t.root, 13);
	DeleteNode(t.root, 10);
	cout << "NLR : ";
	NLR(t.root);
	cout << endl << "LNR : ";
	LNR(t.root);
	cout << endl << "LRN : ";
	LRN(t.root); 
	return 0;
}