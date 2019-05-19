#ifndef vector_h
#define vector_h

#include <iterator>
#include <algorithm>

template <typename T>
class Vector
{
    private:
        size_t _size;
        size_t _capacity;
        T* _elem;

    public:

        typedef T& reference;
        typedef const T& const_reference;
        typedef T* iterator;
        typedef const T* const_iterator;

        //KONSTRUKTORIAI, DESTRUKTORIAI

        Vector() : _size(0), _capacity(0), _elem(new T[_capacity]) {}
        Vector(size_t size):  _size(size), _capacity(size), _elem(new T[size]) {};

        Vector(size_t size, T value): _size{size}, _capacity{size} , _elem{ new T[size] } {
	    std::fill_n(_elem, size, value);}

        ~Vector() { delete[] _elem; };

        Vector(Vector&& other) : _size(other.size()), _capacity(other.capacity()), _elem(other._elem){
            other._elem = nullptr;
            other._size = 0;
            other._capacity = 0;
	    }

        //OPERATORIAI


        reference operator [] (size_t i) {
			if (i < 0 || i >= _size) throw std::out_of_range("Element is out of range");
			return _elem[i];
		}

        const_reference operator [] (size_t i) const {
            if (i < 0 || i >= _size) throw std::out_of_range("Element is out of range");
			return _elem[i];
        }

        Vector& operator = (const Vector& v) {
            if (&v == this) return *this; 

            T* temp = new T[v.size()];

            for (int i=0; i != v.size(); ++i) 
                temp[i] = v._elem[i];

            delete[] _elem; 
            _elem = temp;      
            _size = v.size();     
            _capacity = v.capacity();
            return *this;  
        }




        //FUNKCIJOS

        iterator begin()
        {
            if (_size == 0) throw std::out_of_range("Vector is empty");
            return _elem;
        }
        iterator end()
        {
            if (_size == 0) throw std::out_of_range("Vector is empty");
            return _elem + _size;
        }

        reference front()
        {
            return _elem[0];
        }

        reference back()
        {
            return _elem[size() - 1];
        }

        size_t size() const
        {
            return _size;
        }
        size_t capacity() const
        {
            return _capacity;
        }

        bool empty()
        {
            return size() != 0;
        }

        void pop_back()
        {
            _size = _size - 1;
        }

        void clear()
        {
            _size = 0;
            delete _elem;
            _elem = new T[_capacity];
        }

        size_t max_size() const 
        {
            return std::numeric_limits<size_t>::max();
        }

        void shrink_to_fit() 
        {
			if (_size == _capacity) return;

			T *temp = new T[_size];
			std::move(&_elem[0], &_elem[_size], temp);
			_capacity = _size;

			delete[] _elem;
			_elem = temp;
		}

        void resize(size_t n) 
        {
            size_t end;
            if (n == _capacity) return;

            T *temp = new T[n];

            if (n < _size) {
                _size = n;
                end = n;
            }
            else end = _size;

            std::move(&_elem[0], &_elem[end], temp);
            _capacity = n;
            delete[] _elem;
            _elem = temp;
        }


        void push_back(const T& value)
        {
            if (_size >= _capacity)
            {
                reserve( ( _size + 1 ) *2 );
                _elem[_size] = value;
                _size++;
            }
            else 
            {
                _elem[_size] = value;
                _size++;
            }
        }

        void push_back( T&& value ){
            if (_size >= _capacity)
            {
                reserve( ( _size + 1 ) *2 );
                _elem[_size] = value;
                _size++;
            }
            else 
            {
                _elem[_size] = value;
                _size++;
            }
        }
        
        void reserve(size_t n) 
        {
            if (_capacity < n) 
            {
                T *temp = new T[n];
                for (auto i = 0; i < _size; i++) {
                    temp[i] = _elem[i];
                }
                delete[] _elem;
                _elem = temp;
                _capacity = n;
                temp = nullptr;
		    }
	    }
        
};

#endif