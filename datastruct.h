#pragma once


//二叉树
typedef struct bitnode
{
	int data;
	struct bitnode *l, *r;
	int ltag, rtag;
}bitnode, *bittree;

void visit(bittree T) { ; }

//遍历
void preorder(bittree T)
{
	if (T != nullptr) {
		visit(T);
		preorder(T->l);
		preorder(T->r);
	}
}

void PreOrder(bittree T)
{
	bittree stack[666]; int top = 0;
	bittree p = T;
	while (p || top) {
		if (p) {
			visit(p); stack[top++] = p;
			p = p->l;
		}
		else {
			p = stack[--top];
			p = p->r;
		}
	}
}

void inorder(bittree T)
{
	if (T != nullptr) {
		inorder(T->l);
		visit(T);
		inorder(T->r);
	}
}

void InOrder(bittree T)
{
	bittree stack[666]; int top = 0;
	bittree p = T;
	while (p || top) {
		if (p) {
			stack[top++] = p;
			p = p->l;
		}
		else {
			visit(stack[--top]);
			p = p->r;
		}
	}
}

void postorder(bittree T)
{
	if (T != nullptr) {
		postorder(T->l);
		postorder(T->r);
		visit(T);
	}
}

void PostOrder(bittree T)
{
	bittree stack[999]; int top = 0;
	bittree p = T, read = nullptr;
	while (p || top) {
		if (p) {
			stack[top++] = p;
			p = p->r;
		}
		else {
			p = stack[top-1];
			if (p->r && p->r != read)
				p = p->r;
			else {
				p = stack[--top];
				visit(p);
				read = p;
				p = nullptr;
			}
		}
	}
}

void LeverOrder(bittree T)
{
	bittree queue[666], p = nullptr;
	int front = 0, rear = 0;
	queue[rear++] = T;
	while (front != rear) {
		p = queue[front++];
		visit(p);
		if (p->l != nullptr)
			queue[rear++] = p->l;
		if (p->r != nullptr)
			queue[rear++] = p->r;
	}
}

void InThread(bitnode* p, bitnode* pre)
{
	if (p != nullptr) {
		InThread(p->l, pre);
		if (p->l == nullptr) {
			p->l = pre;
			p->ltag = 1;
		}
		if (pre != nullptr && pre->r == nullptr) {
			pre->r = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->r, pre);
	}
}

void CreateInThead(bittree T)
{
	bittree pre = nullptr;
	if (T != nullptr) {
		InThread(T, pre);
		pre->r = nullptr;
		pre->rtag = 1;
	}
}

void Inorder(bitnode* T)
{
	bitnode* p = T; while(p->ltag == 0) p = p->l; //首先访问最左下结点
	while (p) {
		visit(p);
		if (p->rtag == 0) { //ratg=0表示存在右子树，访问右子树的最左下结点
			p = p->r;
			while (p->ltag == 0) p = p->l;
		}
		else				//rtag=1表示无右子树，中序访问下一个结点
			p = p->r;
	}
}

//并查集
int uf[999], high[999];
void init(int n)
{
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}
}

int find(int x)
{
	return x == uf[x] ? x : (uf[x] = find(uf[x]));
}

void merge(int i, int j)
{
	int x = find(i), y = find(j);
	if (high[x] < high[y])
		uf[x] = uf[y];
	else
		uf[y] = uf[x];
	if (high[x] == high[y] && x != y)
		high[y]++;
}