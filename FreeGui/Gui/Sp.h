#pragma once
#include "ObjectShell.h"

template <typename T = ObjectShell>
class Sp
{

public:

	Sp();		
	~Sp();

	void operator=(const Sp<T> &another);
	void operator=(T *shell);
	
    bool operator==(const Sp<T> &next);
	bool isValid();	

	T * operator->();		
	T & pop();
	T & operator()();

	T * Get();

	
private:

	T * _pointerOnObject;
	int _pointerID;

};

template <typename T>
Sp<T>::~Sp()
{
	if(_pointerOnObject != nullptr)
	{
		_pointerOnObject->decrement();	
	}
	//cout << "Zanik pointra " << _pointerID << endl;
	
}

template <typename T>
Sp<T>::Sp()
{	
	_pointerID = rand();
	//cout << "Creating empty pointer " << _pointerID << endl;;
}


template <typename T>
void Sp<T>::operator=(const Sp<T> & another)
{	
	_pointerID = rand();
	//cout << _pointerID <<" calling = s objektom " << another._pointerOnObject->getID() << endl;
	if(_pointerOnObject != nullptr)
	{
		_pointerOnObject->decrement();
	}
	this->_pointerOnObject = another._pointerOnObject;	
	if (_pointerOnObject != nullptr)
	{
		_pointerOnObject->increment();
	}
}

template <typename T>
void Sp<T>::operator=(T *shell)
{
	ObjectShell *help = _pointerOnObject;
		
	this->_pointerOnObject = shell;
	if (_pointerOnObject != nullptr)
	{
		_pointerOnObject->increment();
	}
	if (help != nullptr)
	{
		help->decrement();
	}
	

}



template <typename T>
T* Sp<T>::operator->()
{
	if (isValid())
	{
		return reinterpret_cast<T*>(_pointerOnObject);
	}	
	return nullptr;	
}

template <typename T>
T& Sp<T>::pop()
{
	_pointerOnObject->increment();
	return *_pointerOnObject;
}

template <typename T>
T& Sp<T>::operator()()
{
	return *_pointerOnObject;
}

template <typename T>
T * Sp<T>::Get()
{
	return _pointerOnObject;
}


template <typename T>
bool Sp<T>::operator==(const Sp<T>& next)
{
	return _pointerOnObject == next._pointerOnObject;
}

template <typename T>
bool Sp<T>::isValid()
{
	bool help = _pointerOnObject != nullptr;
	return help;
}



