# OOP-4


__Spartos analizė:__

| Elementu sk. | Vector <> | std::vector <> |
| --- | --- | --- |
| 10000 |  0.00097800 s   |  0.00100200 s      | 
| 100000 |  0.00100300 s   |  0.00200600 s      |
| 1000000 |  0.01103000 s    |  0.01802100 s      |  
| 10000000 |  0.12032000 s    |  0.18451700 s     |  
| 100000000 |  1.13100500 s   |  1.77872700 s      |  

__Išvados__

Pastebima, kad sukurta Vector <> klasė veikia sparčiau negu std::vector <>

__Funkcijos__

- Operatorius [], su vieno tipo size_t parametru, kuris leidzia pasiekti kurį nori vektoriaus elementą, nurodant to elemento indeksą 

```c++
reference operator [] (size_t i) {
			if (i < 0 || i >= _size) throw std::out_of_range("Element is out of range");
			return _elem[i];
		}
```

- Funkcija, kuri gražina iteratorių (rodyklę) į pirmą elementą, prieš tai dar patikrindama ar Vektorius nėra tuščias
```c++
iterator begin()
        {
            if (_size == 0) throw std::out_of_range("Vector is empty");
            return _elem;
        }
```

- Funkcija, kuri gražina paskutinio vektoriaus elemento reikšmę
```c++
 reference back()
        {
            return _elem[size() - 1];
        }
```

- Funkcija, turinti vieno const T& tipo parametrą, leidžianti pridėti naują elementą į vektoriaus galą, noradant to elemento reikšmę per parametrą 
```c++
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

```

- Funkcija, su vieno size_t tipo parametru, kuri pakeičia vektoriaus dydį į tokį, kad tilptų visi n elementai. 

```c++
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

```

