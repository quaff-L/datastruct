#pragma once


//¶þ²æÊ÷
typedef struct bitnode
{
	int data;
	struct bitnode *l, *r;
}bitnode, *bittree;

void visit(bittree T) { ; }

//±éÀú
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


