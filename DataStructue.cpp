// DataStructue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "List.h"
#include "Stack.h"

using namespace std;

void TestList()
{
	List<int>* list = new List<int>;
	list->TestCaseFirst();
	delete list;
}

void TestStack()
{
	Stack<int>* stack = new Stack<int>;
	stack->TestCaseFirst();
	delete stack;
}


int main()
{
	TestStack();
}

