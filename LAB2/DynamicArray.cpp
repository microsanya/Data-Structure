#include "DynamicArray.h"
#include <stdexcept>

//! \brief Конструктор массива.
//! \param initCapacity Начальная вместимость массива.
//! \param growthFactor Фактор роста массива при расширении.
DynamicArray::DynamicArray(int initCapacity, int growthFactor)
    : _size(0), _capacity(initCapacity), _growthFactor(growthFactor) {
    _array = new int[_capacity];
}

//! \brief Деструктор массива.
DynamicArray::~DynamicArray() {
    delete[] _array;
}

//! \brief Возвращает размер массива.
//! \return Размер массива.
int DynamicArray::GetSize() const {
    return _size;
}

//! \brief Возвращает вместимость массива.
//! \return Вместимость массива.
int DynamicArray::GetCapacity() const {
    return _capacity;
}

//! \brief Возвращает указатель на массив.
//! \return Указатель на массив.
int* DynamicArray::GetArray() const {
    return _array;
}

//! \brief Изменяет вместимость массива.
//! \param newCapacity Новая вместимость массива.
void DynamicArray::resize(int newCapacity) {
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _size; i++) {
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

//! \brief Добавляет элемент в конец массива.
//! \param value Значение элемента.
void DynamicArray::AddElement(int value) {
    if (_size == _capacity) {
        resize(_capacity * _growthFactor);
    }
    _array[_size++] = value;
}

//! \brief Удаляет элемент массива по индексу.
//! \param index Индекс элемента, который нужно удалить.
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

//! \brief Удаляет элемент массива по значению.
//! \param value Значение элемента, который нужно удалить.
void DynamicArray::RemoveByValue(int value) {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) {
            RemoveByIndex(i);
            return;
        }
    }
}

//! \brief Возвращает элемент по индексу.
//! \param index Индекс элемента.
//! \return Значение элемента под индексом.
int DynamicArray::GetElement(int index) const {
    if (index < 0 || index >= _size) throw std::out_of_range("Index out of range");
    return _array[index];
}

//! \brief Вставляет элемент в начало массива.
//! \param value Значение элемента.
void DynamicArray::InsertAtBeginning(int value) {
    AddElement(0); // увеличиваем размер массива
    for (int i = _size - 1; i > 0; i--) {
        _array[i] = _array[i - 1];
    }
    _array[0] = value;
}

//! \brief Вставляет элемент в конец массива.
//! \param value Значение элемента.
void DynamicArray::InsertAtEnd(int value) {
    AddElement(value);
}

//! \brief Вставляет элемент после заданного значения.
//! \param value Значение для вставки.
//! \param afterValue Значение, после которого нужно вставить.
void DynamicArray::InsertAfter(int value, int afterValue) {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == afterValue) {
            AddElement(0); // увеличиваем размер массива
            for (int j = _size - 1; j > i + 1; j--) {
                _array[j] = _array[j - 1];
            }
            _array[i + 1] = value;
            return;
        }
    }
}

//! \brief Функция слияния двух отсортированных частей
void DynamicArray::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Копируем данные в временные массивы
    for (int i = 0; i < n1; i++) leftArray[i] = _array[left + i];
    for (int j = 0; j < n2; j++) rightArray[j] = _array[mid + 1 + j];

    // Слияние временных массивов обратно в основной массив
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            _array[k++] = leftArray[i++];
        }
        else {
            _array[k++] = rightArray[j++];
        }
    }

    // Копируем оставшиеся элементы
    while (i < n1) {
        _array[k++] = leftArray[i++];
    }

    while (j < n2) {
        _array[k++] = rightArray[j++];
    }

    delete[] leftArray;
    delete[] rightArray;
}

//! \brief Рекурсивная функция сортировки слиянием
void DynamicArray::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);    // Сортировка левой части
        mergeSort(mid + 1, right); // Сортировка правой части

        merge(left, mid, right); // Слияние отсортированных частей
    }
}


//! \brief Сортирует массив методом сортировки слиянием.
void DynamicArray::SortArray() {
    mergeSort(0, _size - 1);
}

//! \brief Линейный поиск индекса элемента по значению.
//! \param value Значение для поиска.
//! \return Индекс элемента или -1, если элемент не найден.
int DynamicArray::LinearSearch(int value) const {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) return i;
    }
    return -1;
}

//! \brief Бинарный поиск индекса элемента по значению.
//! \param value Значение для поиска.
//! \return Индекс элемента или -1, если элемент не найден.
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

//! \brief Выводит массив в консоль.
void DynamicArray::PrintArray() const {
    for (int i = 0; i < _size; i++) {
        std::cout << _array[i] << " ";
    }
    std::cout << std::endl;
}
