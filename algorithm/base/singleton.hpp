#pragma once

template <class T>
class Singleton
{
protected:
	Singleton() {}

	static T* obj;
public:
	static T* instance() {
		if (nullptr == obj) {
			obj = new T;
		}
		return obj;
	}
};

template<class T>
T* Singleton<T>::obj = Singleton::instance();