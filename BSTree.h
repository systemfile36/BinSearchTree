#pragma once
#include "BinTree.h"

//이진 트리를 상속한 이진 탐색 트리
class BSTree : public BinTree<int> {

public:
	//이진 탐색
	TrNode<int>* BinSearch(int key);
	//이진 삽입, root부터 계산
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
	
	//만약 들어온 값이 nullptr이면 그자리에 넣음(= 즉 루트가 널이라면)
	if (r == nullptr)
		r = n;

	//중복되면 실패
	if (n->data == r->data)
		return false;
	//값이 작으면 왼쪽을 조사해서 널 체크, 널이면 그자리에 넣고 아니면 다시 순환 호출
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