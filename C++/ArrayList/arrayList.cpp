#include "arrayList.h"

template <typename T> void ArrayList<T>::resize(int new_max_size) {
  T *temp = new T[new_max_size];

  for (int k = 0; k < size; k++) {
    temp[k] = data[k];
  }

  delete[] data;
  data = temp;
}

template <typename T> T &ArrayList<T>::operator[](int i) {
  try {
    if (i < 0 || i >= size) {
      throw "Out of bounds.";
    }
    return data[i];

  } catch (...) {
    std::cerr << "Error: Out of bounds. " << std::endl;
  }
}

template <typename T> void ArrayList<T>::insert(int i, const T &x) {

  try {
    if (0 > i && i >= size) {
      throw "Out of Bounds.";
    }

    if (size == max_size) {
      resize(max_size * 2);
    }
    for (int k = size; k > i; k--) {
      data[k] = data[k - 1];
    }

    data[i] = x;
    size++;
  } catch (...) {
    std::cerr << "Error: Out of bounds. " << std::endl;
  }
}

template <typename T> void ArrayList<T>::remove(int i) {

  try {
    if (0 > i && i >= size) {
      throw "Out of Bounds.";
    }

    for (int k = i; k < size - 1; k++) {
      data[k] = data[k + 1];
    }

    size--;
    if (size < max_size / 4) {
      resize(max_size / 2);
    }
  } catch (...) {
    std::cerr << "Error: Out of bounds. " << std::endl;
  }
}

template <typename T> bool ArrayList<T>::find(const T &x) {
  for (int k = 0; k < size; k++) {
    if (data[k] == x) {
      return true;
    }
  }
  return false;
}

template <typename T> ArrayList<T>::~ArrayList() { delete[] data; }

template <typename T>
const ArrayList<T> &ArrayList<T>::operator=(const ArrayList &rhs) {
  if (this != &rhs) {
    T *tmp = new T[rhs.max];
    for (int k = 0; k < rhs.size; k++) {
      tmp.data[k] = rhs.data[k];
    }

    max_size = rhs.max_size;
    size = rhs.size;
    delete[] data;
    data = tmp;
  }

  return (*this);
}

// Copy Contructor Creates a new object that is a copy of another.
// New object not just changing the values and copying the old object.

template <typename T> ArrayList<T>::ArrayList(const ArrayList &rhs) {

  data = nullptr;
  *this = rhs;
}
