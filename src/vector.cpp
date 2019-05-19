#include "../headers/vector.h"

//KONSTRUKTORIAI

template<typename T>
Vector<T>::Vector() : _size(0), _capacity(0), _elem(new T[nullptr]) {}

template<typename T>
Vector<T>::Vector(size_t size) : _size(size), _capacity(size), _elem(new T[size]) {}

template<typename T>
Vector<T>::Vector(size_t size, T value) : _size{size}, _capacity{size} , _elem{ new T[size] } {
	std::fill_n(_elem, size, value);
}


 



//OPERATORIAI



//FUNKCIJOS

