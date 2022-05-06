#pragma once
#include	<stdlib.h>
#include	<malloc.h>
#include	<iostream>

/*
Insert();
Size();
Erase();
Swap();*/
typedef unsigned __int64 uint64_t;
template <class T>
class Container
{

private:
	uint64_t maximumNumbersOfElements = 0;
	uint64_t numberOfElements = 0;
	T* a = nullptr;
public:
	Container() {
		a = AllocateMemory(1000);
		if (a == NULL) {
			std::cout << "ERROR::CANNOTALLOCATEMEMORY" << std::endl;
		}
		else maximumNumbersOfElements = 1000;
	};
	Container(uint64_t n)
	{
		if (n == 0) {
			std::cout << "ERROR::NUMBEROFELEMENTSMUSTBEMORETHANZERO" << std::endl;
			std::cout << "ERROR::CONTAINERNOTCREATED" << std::endl;
			return;
		}
		a = AllocateMemory(n);
		if (a == NULL) {
			std::cout << "ERROR::CANNOTALLOCATEMEMORY" << std::endl;
		}
		else maximumNumbersOfElements = n;
		
	};
	~Container() {
		FreeMemory(a);
	}
	void Append(T n);
	T Pop();
	bool IsEmpty();
	uint64_t Size();
	void Erase();
	T& operator[](uint64_t index){
		if (index < numberOfElements && index >= 0) {
			return a[index];
		}
		std::cout << "ERROR::OPERATOR[]::INCORRECTINDEX" << std::endl;
		return a[0];
	}
	
private:
	T* AllocateMemory(uint64_t n);
	T* ReAllocateMemory(void* memory, uint64_t newSize);
	void FreeMemory(void* memory);
};


template<typename T>
T* Container<T>::AllocateMemory(uint64_t n) {
	return (T*)calloc(n, sizeof(T));
}
template<typename T>
T* Container<T>::ReAllocateMemory(void* memory, uint64_t newSize) {
	return (T*)realloc(memory, newSize);
}
template<typename T>
void Container<T>::FreeMemory(void* memory) {
	free(memory);
}

template<typename T>
void Container<T>::Append(T n) {
	if (maximumNumbersOfElements <= numberOfElements) {
		uint64_t newSize = maximumNumbersOfElements + 10;
		T* b = ReAllocateMemory((void*)a, newSize*sizeof(T));
		if (b) {
			a = b;
			maximumNumbersOfElements += 10;
			a[numberOfElements] = n;
			numberOfElements++;
			
		}
		else std::cout << "ERROR::APPEND::CANNOTRESIZECONTAINER" << std::endl;
	}
	else {
		a[numberOfElements] = n;
		numberOfElements++;
	}

}
template<typename T>
T Container<T>::Pop() {
	if (numberOfElements == 0) {
		std::cout << "ERROR::POP::CANNOTPOPFROMEMPTYCONTAINER" << std::endl;
		return NULL;
	}
	else
	{
		T b = a[numberOfElements];
		a[numberOfElements] = NULL;
		numberOfElements--;
		return b;
	}

}
template<typename T>
bool Container<T>::IsEmpty() {
	if (numberOfElements) {
		return false;
	}
	return true;
}
template<typename T>
uint64_t Container<T>::Size() {
	return numberOfElements;
}
template<typename T>
void Container<T>::Erase() {
	for (uint64_t i = 0; i < numberOfElements; i++) {
		a[i] = NULL;
	}
}


