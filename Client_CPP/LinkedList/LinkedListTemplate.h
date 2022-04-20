#pragma once

template <typename T>
class Node
{
	T _item;
	Node* _prev;
	Node* _next;
};

template <typename T>
class LinkedList
{
	Node* _first, * _last, *_tmp;


	// 링크드 리스트 템플릿 구현해보기
	// C 때 했던거 참고
	// 멤버함수는
	// void AddFirst(T item) 
	// void AddLast(T item)
	// void AddAfter(Node& node, T item) 
	// void AddBefore(Node& node, T item)
	// Node<T>& First
	// Node<T>& Last
	// Node<T>& Find(T item)
	// Node<T>& FindLast (T item)
	// bool Remove (T item)
	// bool RemoveLast (T item)
	// void Delete()


public :
	
	void AddFirst(T item);
	void AddLast(T item);
	void AddAfter(Node&, node, T item);
	void AddBefore(Node&, node, T item);
	Node<T>& First();
	Node<T>& Last();
	Node<T>& Find(T item);
	Node<T>& FindLast(T item);
	bool Remove(T item);
	bool RemoveLast(T item);
	void Delete();

	
};
/// <summary>
/// 리스트의 가장 앞에 신규 노드 삽입하는 함수
/// </summary>
template<typename T>
inline void LinkedList<T>::AddFirst(T item)
{
	_tmp = new Node<T>(); // 신규노드 생성
	_tmp->_item = item; // 신규노드 값 대입

	// first 가 존재함 ?
	if (_first != nullptr)
	{
		_tmp->_next = _first; // 신규노드의 다음 노드가 first 를 가르키게 한다.
		_first->_prev = _tmp; // first 의 이전 노드가 신규 노드를 가리키게 한다.
	}

	// last 가 존재안함 ?
	// : 이번 신규노드가 가장 처음으로 생성된 노드.
	// 즉, first와 last 포인터가 신규 노드를 가리켜야 한다.

	if (_last == nullptr)
		//_first = _tmp; // 어차피 마지막에 last가 신규노드를 가리키게 할거니까 생략
		_last = _tmp;
	_first = _tmp;
}


/// <summary>
/// 리스트의 가장 앞에 신규 노드 삽입하는 함수
/// </summary>
template<typename T>
inline void LinkedList<T>::AddLast(T item)
{
	_tmp = new Node<T>(); // 신규노드 생성
	_tmp->_item = item; // 신규노드 값 대입

	// last 가 존재함 ?
	if (_first != nullptr)
	{
		_tmp->_prev = _Last; // 신규노드의 다음 노드가 last 를 가르키게 한다.
		_Last->_next = _tmp; // last 의 이전 노드가 신규 노드를 가리키게 한다.
	}

	// fiast 가 존재안함 ?
	// : 이번 신규노드가 가장 처음으로 생성된 노드.
	// 즉, first와 last 포인터가 신규 노드를 가리켜야 한다.

	if (_first == nullptr)
		//_last = _tmp; // 어차피 마지막에 first가 신규노드를 가리키게 할거니까 생략
		_first = _tmp;
	_last = _tmp;
}
