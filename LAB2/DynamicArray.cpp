#include "DynamicArray.h"
#include <stdexcept>

//! \brief ����������� �������.
//! \param initCapacity ��������� ����������� �������.
//! \param growthFactor ������ ����� ������� ��� ����������.
DynamicArray::DynamicArray(int initCapacity, int growthFactor)
    : _size(0), _capacity(initCapacity), _growthFactor(growthFactor) {
    _array = new int[_capacity];
}

//! \brief ���������� �������.
DynamicArray::~DynamicArray() {
    delete[] _array;
}

//! \brief ���������� ������ �������.
//! \return ������ �������.
int DynamicArray::GetSize() const {
    return _size;
}

//! \brief ���������� ����������� �������.
//! \return ����������� �������.
int DynamicArray::GetCapacity() const {
    return _capacity;
}

//! \brief ���������� ��������� �� ������.
//! \return ��������� �� ������.
int* DynamicArray::GetArray() const {
    return _array;
}

//! \brief �������� ����������� �������.
//! \param newCapacity ����� ����������� �������.
void DynamicArray::resize(int newCapacity) {
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _size; i++) {
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

//! \brief ��������� ������� � ����� �������.
//! \param value �������� ��������.
void DynamicArray::AddElement(int value) {
    if (_size == _capacity) {
        resize(_capacity * _growthFactor);
    }
    _array[_size++] = value;
}

//! \brief ������� ������� ������� �� �������.
//! \param index ������ ��������, ������� ����� �������.
void DynamicArray::RemoveByIndex(int index) {
    if (index < 0 || index >= _size) throw std::out_of_range("Index out of range");
    for (int i = index; i < _size - 1; i++) {
        _array[i] = _array[i + 1];
    }
    _size--;
    if (_capacity / _size >= _growthFactor) {
        resize(_capacity / _growthFactor);
    }
}

//! \brief ������� ������� ������� �� ��������.
//! \param value �������� ��������, ������� ����� �������.
void DynamicArray::RemoveByValue(int value) {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) {
            RemoveByIndex(i);
            return;
        }
    }
}

//! \brief ���������� ������� �� �������.
//! \param index ������ ��������.
//! \return �������� �������� ��� ��������.
int DynamicArray::GetElement(int index) const {
    if (index < 0 || index >= _size) throw std::out_of_range("Index out of range");
    return _array[index];
}

//! \brief ��������� ������� � ������ �������.
//! \param value �������� ��������.
void DynamicArray::InsertAtBeginning(int value) {
    AddElement(0); // ����������� ������ �������
    for (int i = _size - 1; i > 0; i--) {
        _array[i] = _array[i - 1];
    }
    _array[0] = value;
}

//! \brief ��������� ������� � ����� �������.
//! \param value �������� ��������.
void DynamicArray::InsertAtEnd(int value) {
    AddElement(value);
}

//! \brief ��������� ������� ����� ��������� ��������.
//! \param value �������� ��� �������.
//! \param afterValue ��������, ����� �������� ����� ��������.
void DynamicArray::InsertAfter(int value, int afterValue) {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == afterValue) {
            AddElement(0); // ����������� ������ �������
            for (int j = _size - 1; j > i + 1; j--) {
                _array[j] = _array[j - 1];
            }
            _array[i + 1] = value;
            return;
        }
    }
}

//! \brief ������� ������� ���� ��������������� ������
void DynamicArray::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // �������� ������ � ��������� �������
    for (int i = 0; i < n1; i++) leftArray[i] = _array[left + i];
    for (int j = 0; j < n2; j++) rightArray[j] = _array[mid + 1 + j];

    // ������� ��������� �������� ������� � �������� ������
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            _array[k++] = leftArray[i++];
        }
        else {
            _array[k++] = rightArray[j++];
        }
    }

    // �������� ���������� ��������
    while (i < n1) {
        _array[k++] = leftArray[i++];
    }

    while (j < n2) {
        _array[k++] = rightArray[j++];
    }

    delete[] leftArray;
    delete[] rightArray;
}

//! \brief ����������� ������� ���������� ��������
void DynamicArray::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);    // ���������� ����� �����
        mergeSort(mid + 1, right); // ���������� ������ �����

        merge(left, mid, right); // ������� ��������������� ������
    }
}


//! \brief ��������� ������ ������� ���������� ��������.
void DynamicArray::SortArray() {
    mergeSort(0, _size - 1);
}

//! \brief �������� ����� ������� �������� �� ��������.
//! \param value �������� ��� ������.
//! \return ������ �������� ��� -1, ���� ������� �� ������.
int DynamicArray::LinearSearch(int value) const {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) return i;
    }
    return -1;
}

//! \brief �������� ����� ������� �������� �� ��������.
//! \param value �������� ��� ������.
//! \return ������ �������� ��� -1, ���� ������� �� ������.
int DynamicArray::BinarySearch(int value) const {
    int left = 0, right = _size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (_array[mid] == value) return mid;
        if (_array[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

//! \brief ������� ������ � �������.
void DynamicArray::PrintArray() const {
    for (int i = 0; i < _size; i++) {
        std::cout << _array[i] << " ";
    }
    std::cout << std::endl;
}
