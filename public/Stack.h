#pragma once
template<typename T>
class Stack
{
public:
	Stack()
		: m_Size { 0 }
		, m_Capacity { 10 }
	{
		m_DataArray = new T[m_Capacity]; // 기본 데이터
	}

	virtual ~Stack()
	{
		delete m_DataArray; // 동적할당 해제
	}

	bool IsEmpty();
	int GetSize();
	void Clear();
	void Push(T data);
	T Pop();
	void Print();
	void TestCaseFirst();


private:
	T* m_DataArray;
	int m_Top;
	int m_Capacity;
	int m_Size;
};

template<typename T>
inline bool Stack<T>::IsEmpty()
{
	return m_Top == -1;
}

template<typename T>
inline int Stack<T>::GetSize()
{
	return m_Size;
}

template<typename T>
inline void Stack<T>::Clear()
{
	m_Top = -1; // 스택이 비어있음을 나타냄
	m_Size = 0;
}

template<typename T>
inline void Stack<T>::Push(T data)
{
	// 용량이 꽉찼다면?
	if (m_Capacity == m_Size)
	{
		m_Capacity *= 2;
		T* newArray = new T[m_Capacity];

		// 값을 채워줍니다.
		for (int i = 0; i < m_Size; ++i)
			newArray[i] = m_DataArray[i];

		delete m_DataArray; // 기존 배열 해제

		m_DataArray = newArray; // 주소 변경.
	}

	m_DataArray[m_Top] = data; // 새로운 데이터 추가.
	m_Top++;
	m_Size++;
}

template<typename T>
inline T Stack<T>::Pop()
{
	if (IsEmpty())
	{
		std::cout << "스택이 비어있습니다. " << std::endl;
		return T(); // 기본값 반환
	}
	
	T data = m_DataArray[m_Top];
	m_Top--; // Top만 밑으로 내립니다.
	return data;
}

template<typename T>
inline void Stack<T>::Print()
{
	// Top부터 0까지 출력합니다.
	for (int i = m_Top - 1; i >= 0; --i)
		std::cout << m_DataArray[i] << std::endl;
}

template<typename T>
inline void Stack<T>::TestCaseFirst()
{
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Pop();	
	Push(5);
	Push(6);
	Pop();
	Print();

	std::cout << "==== Test 1 ====" << std::endl;

	Push(7);

	Print();

	std::cout << "==== Test 2 ====" << std::endl;



}
