#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node* prev;
	Node* next;
	

	Node(T data)
		: data{ data }
		, prev { nullptr }
		, next { nullptr }
	{

	}

};

template<typename T>
class List
{
public:
	List()
		: m_head { nullptr }
		, m_Size { 0 }
	{
		
	}

	// 소멸자
	virtual ~List()
	{
		Clear();
	};


	bool IsEmpty();
	int  GetSize();
	void Add(T data);
	void Remove(T data);	// 가장 먼저 만난 data를 삭제한다.
	void RemoveAll(T data); // data를 모두 삭제한다.
	Node<T>* FindNode(T data); // data를 찾아서 Node를 반환한다.
	void Clear();

	void Print();

	void TestCaseFirst();


private:
	Node<T>* m_head;
	int		 m_Size;
};

template<typename T>
inline bool List<T>::IsEmpty()
{
	if (GetSize() == 0)
		return true;
	return false;
}

template<typename T>
inline int List<T>::GetSize()
{
	return m_Size;
}

template<typename T>
inline void List<T>::Add(T data) // O(N) // 끝에 추가.
{
	Node<T>* node = new Node<T>(data);
	++m_Size;

	if (nullptr == m_head)
	{
		m_head = node;
		return;
	}
	else
	{
		Node<T>* current = m_head;
		while (current->next != nullptr) // 끝까지 이동
			current = current->next;

		current->next = node;
		node->prev = current;
	}

	
}

template<typename T>
inline void List<T>::Remove(T data)
{
	Node<T>* current = FindNode(data);
	if (current == nullptr)
		return;

	if (current->prev != nullptr)
		current->prev->next = current->next;
	else
		m_head = current->next;

	--m_Size;
	delete current; // 메모리 해제.
}

template<typename T>
inline void List<T>::RemoveAll(T data)
{
	Node<T>* current = m_head;
	while (current != nullptr)
	{
		Node<T>* next = current->next; // 다음 노드를 저장.
		if (current->data == data)
		{
			if (current->prev != nullptr)
				current->prev->next = current->next;
			else
				m_head = current->next;

			if (current->next != nullptr)
				current->next->prev = current->prev;

			delete current; // 메모리 해제.
			--m_Size;
		}
		current = next;
	}	
}

template<typename T>
inline Node<T>* List<T>::FindNode(T data) // 선형 탐색. O(N)
{
	if (nullptr == m_head)
		return m_head;

	Node<T>* current = m_head;
	while (current != nullptr)
	{
		if (current->data == data)
			return current;
		current = current->next;
	}		

	return nullptr;
}

template<typename T>
inline void List<T>::Clear()
{
	Node<T>* current = m_head;
	while (current != nullptr)
	{
		Node<T>* next = current->next;
		delete current; // 메모리 해제.
		current = next;
	}
	m_head = nullptr;
	m_Size = 0;
}

template<typename T>
inline void List<T>::Print()
{
	Node<T>* current = m_head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline void List<T>::TestCaseFirst()
{
	Add(1);
	Add(2);
	Add(3);
	Add(2);
	Add(2);

	Print();
	Remove(2);
	Print();
	RemoveAll(2);

	Print();

}
