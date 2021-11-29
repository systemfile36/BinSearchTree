#pragma once
#include <iostream>
#include <queue>

template <class T>
class TrNode {
public:
	T data;
	TrNode<T>* left;
	TrNode<T>* right;
	TrNode<T>(T data,TrNode<T>* left = nullptr, TrNode<T>* right = nullptr)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class BinTree {
private:
	TrNode<T>* root = nullptr;
	std::queue<TrNode<T>*> L_queue;

public:
	void Init();
	bool IsEmpty();
	TrNode<T>* CreateTree(T v, TrNode<T>* l, TrNode<T>* r);
	TrNode<T>* GetRoot();
	void SetRoot(TrNode<T>* r);
	void PrintPreOrder(TrNode<T>* n);
	//매개변수 없으면 루트부터 순환
	void PrintPreOrder();
	void PrintInOrder(TrNode<T>* n);
	//매개변수 없으면 루트부터 순환
	void PrintInOrder();
	void PrintPostOrder(TrNode<T>* n);
	//매개변수 없으면 루트부터 순환
	void PrintPostOrder();
	void PrintLevelOrder();
	//후위 순환방식의 노드 개수 연산
	int CountNode(TrNode<T>* n);
	//매개변수 없으면 루트부터 순환
	int CountNode();
	//이진 트리 메모리 해제 함수
	void DestroyTree(TrNode<T>* n);
	void DestroyTree();
};

template <class T>
void BinTree<T>::Init()
{
	this->root = nullptr;
}

template <class T>
bool BinTree<T>::IsEmpty()
{
	return this->root == nullptr;
}

template <class T>
TrNode<T>* BinTree<T>::CreateTree(T data, TrNode<T>* left, TrNode<T>* right)
{
	TrNode<T>* n = new TrNode<T>;
	n->data = data;
	n->left = left;
	n->right = right;
	return n;
}

template <class T>
TrNode<T>* BinTree<T>::GetRoot()
{
	return this->root;
}

template <class T>
void BinTree<T>::SetRoot(TrNode<T>* r)
{
	this->root = r;
}

template <class T>
void BinTree<T>::PrintPreOrder(TrNode<T>* n)
{
	if (n != nullptr)
	{
		std::cout << "[" << n->data << "] ";
		this->PrintPreOrder(n->left);
		this->PrintPreOrder(n->right);
	}
}

template <class T>
void BinTree<T>::PrintPreOrder()
{
	PrintPreOrder(root);
}

template <class T>
void BinTree<T>::PrintInOrder(TrNode<T>* n)
{
	if (n != nullptr)
	{
		this->PrintPreOrder(n->left);
		std::cout << "[" << n->data << "] ";
		this->PrintPreOrder(n->right);
	}
}

template <class T>
void BinTree<T>::PrintInOrder()
{
	PrintInOrder(root);
}

template <class T>
void BinTree<T>::PrintPostOrder(TrNode<T>* n)
{
	if (n != nullptr)
	{
		this->PrintPreOrder(n->left);
		this->PrintPreOrder(n->right);
		std::cout << "[" << n->data << "] ";
	}
}

template <class T>
void BinTree<T>::PrintPostOrder()
{
	PrintPostOrder(root);
}

template <class T>
void BinTree<T>::PrintLevelOrder()
{
	TrNode<T>* temp;

	if (IsEmpty())
		return;

	//root를 큐에 넣는다.
	L_queue.push(root);

	//큐가 비어있지 않는 동안 큐에서 꺼내고 자식 노드들을 집어넣으며 반복
	while (!L_queue.empty())
	{
		temp = L_queue.front();
		L_queue.pop();
		if (temp != nullptr)
		{
			std::cout << "[" << temp->data << "] ";
			L_queue.push(temp->left);
			L_queue.push(temp->right);
		}
	}
}

template <class T>
int BinTree<T>::CountNode(TrNode<T>* n)
{
	if (n == nullptr) return 0;
	return 1 + CountNode(n->left) + CountNode(n->right);
}

template <class T>
int BinTree<T>::CountNode()
{
	return CountNode(root);
}

template <class T>
void BinTree<T>::DestroyTree()
{

}

template <class T>
void BinTree<T>::DestroyTree(TrNode<T>* n)
{
	if (n != nullptr)
	{
		DestroyTree(n->left);
		DestroyTree(n->right);
		delete n;
	}
	root = nullptr;
}