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
	//이진 삽입, data를 받는 오버로딩
	bool BinInsert(int data);
	//이진 삭제
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

bool BSTree::BinInsert(int data)
{
	return BinInsert(new TrNode<int>(data));
}

void BSTree::BinDelete(TrNode<int>* parent, TrNode<int>* n)
{

	//삭제할 노드가 단말 노드일때
	if (n->left == nullptr && n->right == nullptr)
	{
		//만약 삭제할 노드가 루트이면
		if (parent == nullptr)
			SetRoot(nullptr);
		else
		{
			//왼쪽에 있는지 오른쪽에 있는지 확인 후 널로 변경
			if (parent->left == n)
			{
				parent->left = nullptr;
			}
			else
				parent->right = nullptr;
		}
	}
	//삭제할 노드가 자식이 하나일 때
	else if (n->left == nullptr || n->right == nullptr)
	{
		//자식을 임시 저장, 자식의 위치를 파악해서 저장
		TrNode<int>* child;
		if (n->left == nullptr)
			child = n->right;
		else
			child = n->left;

		//삭제할 노드가 루트와 같다면 자식을 루트로 연결
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
	//삭제할 노드가 자식이 둘일 때
	else
	{
		//후계자 노드와 그의 부모를 적절히 초기화
		TrNode<int>* Suc_n = n->right, * Suc_parent = n;

		//오른쪽 서브트리의 가장 작은 가장 작은 값을 후계자로
		//왼쪽 값이 널 일때까지 후계자 노드를 갱신하면서 나아간다.
		while (Suc_n->left != nullptr)
		{
			Suc_parent = Suc_n;
			Suc_n = Suc_n->left;
		}

		//후계자와 부모의 관계에 따라 자식 이어받음
		if (Suc_parent->left == Suc_n)
			Suc_parent->left = Suc_n->right;
		else
			Suc_parent->right = Suc_n->right;

		//후계자를 n에다가 복사한 후 후계자 삭제하고 함수 종료
		n->data = Suc_n->data;
		delete Suc_n;
		return;
	}
	//첫번째와 두번째의 경우엔 n삭제
	delete n;
}

void BSTree::BinDelete(int key)
{
	TrNode<int>* parent = nullptr;
	TrNode<int>* n = GetRoot();

	if (n == nullptr)
		return;

	//키가 있는지 여부를 확인하면서 parent와 삭제할 노드 결정
	while (n != nullptr && n->data != key)
	{
		parent = n;
		if (key < n->data)
			n = n->left;
		else
			n = n->right;
	}

	//위의 루프를 나왔다는 것은 n이 널이거나, n의 데이터가 key값과 일치 한다는 것
	if (n == nullptr)
	{
		std::cout << "There is no \"" << key << "\"in the Tree!" << std::endl;
	}
	else
		BinDelete(parent, n);
}