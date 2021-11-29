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
	//���� ����, data�� �޴� �����ε�
	bool BinInsert(int data);
	//���� ����
	void BinDelete(TrNode<int>* parent, TrNode<int>* n);
	void BinDelete(int key);
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

bool BSTree::BinInsert(int data)
{
	return BinInsert(new TrNode<int>(data));
}

void BSTree::BinDelete(TrNode<int>* parent, TrNode<int>* n)
{

	//������ ��尡 �ܸ� ����϶�
	if (n->left == nullptr && n->right == nullptr)
	{
		//���� ������ ��尡 ��Ʈ�̸�
		if (parent == nullptr)
			SetRoot(nullptr);
		else
		{
			//���ʿ� �ִ��� �����ʿ� �ִ��� Ȯ�� �� �η� ����
			if (parent->left == n)
			{
				parent->left = nullptr;
			}
			else
				parent->right = nullptr;
		}
	}
	//������ ��尡 �ڽ��� �ϳ��� ��
	else if (n->left == nullptr || n->right == nullptr)
	{
		//�ڽ��� �ӽ� ����, �ڽ��� ��ġ�� �ľ��ؼ� ����
		TrNode<int>* child;
		if (n->left == nullptr)
			child = n->right;
		else
			child = n->left;

		//������ ��尡 ��Ʈ�� ���ٸ� �ڽ��� ��Ʈ�� ����
		if (n == GetRoot()) 
			SetRoot(child);
		else
		{
			if (parent->left == n)
			{
				parent->left = child;
			}
			else
				parent->right = child;
		}
	}
	//������ ��尡 �ڽ��� ���� ��
	else
	{
		//�İ��� ���� ���� �θ� ������ �ʱ�ȭ
		TrNode<int>* Suc_n = n->right, * Suc_parent = n;

		//������ ����Ʈ���� ���� ���� ���� ���� ���� �İ��ڷ�
		//���� ���� �� �϶����� �İ��� ��带 �����ϸ鼭 ���ư���.
		while (Suc_n->left != nullptr)
		{
			Suc_parent = Suc_n;
			Suc_n = Suc_n->left;
		}

		//�İ��ڿ� �θ��� ���迡 ���� �ڽ� �̾����
		if (Suc_parent->left == Suc_n)
			Suc_parent->left = Suc_n->right;
		else
			Suc_parent->right = Suc_n->right;

		//�İ��ڸ� n���ٰ� ������ �� �İ��� �����ϰ� �Լ� ����
		n->data = Suc_n->data;
		delete Suc_n;
		return;
	}
	//ù��°�� �ι�°�� ��쿣 n����
	delete n;
}

void BSTree::BinDelete(int key)
{
	TrNode<int>* parent = nullptr;
	TrNode<int>* n = GetRoot();

	if (n == nullptr)
		return;

	//Ű�� �ִ��� ���θ� Ȯ���ϸ鼭 parent�� ������ ��� ����
	while (n != nullptr && n->data != key)
	{
		parent = n;
		if (key < n->data)
			n = n->left;
		else
			n = n->right;
	}

	//���� ������ ���Դٴ� ���� n�� ���̰ų�, n�� �����Ͱ� key���� ��ġ �Ѵٴ� ��
	if (n == nullptr)
	{
		std::cout << "There is no \"" << key << "\"in the Tree!" << std::endl;
	}
	else
		BinDelete(parent, n);
}