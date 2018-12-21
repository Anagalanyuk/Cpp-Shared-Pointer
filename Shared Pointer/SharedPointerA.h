#pragma once

#include"SharedPointer.h"

template<typename T>
class SharedPointer<T[]>
{
public:
	SharedPointer(T* item);
	SharedPointer(SharedPointer& obj);
	T* GetPointer()const;
	T& operator[](const T item);
	T operator *()const;
	T operator ->()const;
	SharedPointer& operator=(const SharedPointer& item);
	~SharedPointer();


private:
	int* capacity;
	T* Array;
};

template<typename T>
SharedPointer<T[]>::SharedPointer( T* item)
{
	Array = item;
	capacity = new int(0);
}

template<typename T>
SharedPointer<T[]>::SharedPointer(SharedPointer& obj)
{
	Array = obj.Array;
	capacity = obj.capacity;
	*capacity += 1;
}

template<typename T>
T* SharedPointer<T[]>::GetPointer()const
{
	return Array;
}

template<typename T>
T& SharedPointer<T[]>::operator[](const T item)
{
	return Array[item];
}

template<typename T>
T SharedPointer<T[]>::operator*()const
{
	return *Array;
}

template<typename T>
T SharedPointer<T[]>::operator->()const
{
	return Array;
}

template<typename T>
SharedPointer<T[]>& SharedPointer<T[]>::operator=(const SharedPointer& item)
{
	if (this != &item)
	{
		if (*capacity == 0)
		{
			delete[] Array;
			delete capacity;
			Array = item.Array;
			*item.capacity += 1;
			capacity = item.capacity;
		}
		else
		{
			*capacity -= 1;
			*item.capacity += 1;
			Array = item.Array;
			capacity = item.capacity;
		}
	}
	return *this;
}

template<typename T>
SharedPointer<T[]>::~SharedPointer()
{
	if (*capacity != 0)
	{
		*capacity -= 1;
		Array = nullptr;
		capacity = nullptr;
	}
	else
	{
		delete[] Array;
		delete capacity;
		Array = nullptr;
		capacity = nullptr;
	}
}


