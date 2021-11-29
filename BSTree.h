#pragma once
#include "BinTree.h"

//���� Ʈ���� ����� ���� Ž�� Ʈ��
class BSTree : public BinTree<int> {

public:
	//���� Ž��
	TrNode<int>* BinSearch(int key);
	//���� ����, root���� ���
	bool BinInsert(TrNode<int>* n);
	bool BinInsert(TrNode<int>* r, TrNode<int>* n);
};

TrNode<int>* BSTree::BinSearch(int key)
{
	TrNode<int>* temp = GetRoot();
	while (temp != nullptr)
	{
		if (key == temp->data)
			return temp;
		else if (key < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}

	return nullptr;
}

bool BSTree::BinInsert(TrNode<int>* n)
{
	return BinInsert(GetRoot(), n);
}

bool BSTree::BinInsert(TrNode<int>* i, TrNode<int>* n)
{
	TrNode<int>* r = i;
	
	//���� ���� ���� nullptr�̸� ���ڸ��� ����(= �� ��Ʈ�� ���̶��)
	if (r == nullptr)
		r = n;

	//�ߺ��Ǹ� ����
	if (n->data == r->data)
		return false;
	//���� ������ ������ �����ؼ� �� üũ, ���̸� ���ڸ��� �ְ� �ƴϸ� �ٽ� ��ȯ ȣ��
	else if (n->data < r->data)
	{
		if (r->left == nullptr)
			r->left = n;
		else
			BinInsert(r->left, n);
	}
	else
	{
		if (r->right == nullptr)
			r->right = n;
		else
			BinInsert(r->right, n);
	}

	return true;
}