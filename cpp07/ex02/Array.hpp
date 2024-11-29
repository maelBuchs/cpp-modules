#pragma once

#include <exception>
#define MAX_VAL 256
#include <iostream>



template <typename T> class Array {
public:
  Array() : _array(NULL), _size(0){};
  Array(const Array &t) : _array(NULL), _size(t._size) {
    if (_size > 0) {
      _array = new T[_size];
      for (int i = 0; i < _size; i++) {
        _array[i] = t._array[i];
      }
    }
  }

  explicit Array(unsigned int size) : _size(size) { _array = new T[size]; };
  ~Array() {
    if (_array)
      delete[] _array;
  };

  T &operator[](int idx) const {
    if (idx > _size || idx < 0)
      throw std::exception();
    return _array[idx];
  };

  Array &operator=(const Array &in) {
    if (this != &in) {
      if (_array)
        delete[] _array;
      _array = NULL;
      _size = in._size;
      if (_size > 0) {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
          _array[i] = in._array[i];
        }
      } else
        _array = NULL;
    }
    return *this;
  }

private:
  T *_array;
  int _size;
};
