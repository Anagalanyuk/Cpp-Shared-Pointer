#pragma once

#include"Ptr.h"

template<typename T>
class SharedPointer
{
public:
	SharedPointer( T* item);
	SharedPointer(const SharedPointer& obj);
	T* GetPointer()const;
	T operator *()const;
	T* operator->()const;
	SharedPointer& operator =(const SharedPointer& item);
	~SharedPointer();
private:
	T* Ptr;
	int* capacity = nullptr;
};



template<typename T>
SharedPointer<T>::SharedPointer( T* item)
{
	std::cout << "constructor\n";
    Ptr = item;
	capacity = new int(0);
}

template<typename T>
SharedPointer<T>::SharedPointer(const SharedPointer& obj)
{
	Ptr = obj.Ptr;
	capacity = obj.capacity;
	*capacity += 1;
}

template<typename T>
T* SharedPointer<T>::GetPointer()const
{
	return Ptr;
}

template<typename T>
T SharedPointer<T>::operator*()const
{
	return *Ptr;
}

template<typename T>
T* SharedPointer<T>::operator->()const
{
	return Ptr;
}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& item)
{
	if (this != &item)
	{
		if (*capacity == 0)
		{
			delete Ptr;
			delete capacity;
			Ptr = item.Ptr;
			*item.capacity += 1;
			capacity = item.capacity;
		}
		else if (Ptr != item.Ptr)
		{
			*capacity -= 1;
			*item.capacity += 1;
			Ptr = item.Ptr;
			capacity = item.capacity;
		}
	}
	return *this;
}

template<typename T>
SharedPointer<T>::~SharedPointer()
{

	if (*capacity != 0)
	{
		*capacity -= 1;
		Ptr = nullptr;
		capacity = nullptr;
	}
	else
	{
		std::cout << "destructor\n";
		delete Ptr;
		delete capacity;
		Ptr = nullptr;
		capacity = nullptr;
	}
}