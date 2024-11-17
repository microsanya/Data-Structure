#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

//! \brief Структура динамического массива.
struct DynamicArray {
private:
    //! \brief Размер массива.
    int _size;

    //! \brief Вместимость массива.
    int _capacity;

    //! \brief Массив.
    int* _array;

    //! \brief Фактор роста массива.
    int _growthFactor;

    //! \brief Изменяет вместимость массива.
    //! \param newCapacity Новая вместимость массива.
    void resize(int newCapacity);

    //! \brief Вспомогательная функция сортировки слиянием.
    //! \param left Левый индекс.
    //! \param right Правый индекс.
    void mergeSort(int left, int right);

    //! \brief Вспомогательная функция для слияния частей массива.
    //! \param left Левый индекс.
    //! \param mid Средний индекс.
    //! \param right Правый индекс.
    void merge(int left, int mid, int right);

public:
    //! \brief Конструктор массива.
    //! \param initCapacity Начальная вместимость.
    //! \param growthFactor Фактор роста массива.
    DynamicArray(int initCapacity = 8, int growthFactor = 2);

    //! \brief Деструктор массива.
    ~DynamicArray();

    //! \brief Возвращает размер массива.
    //! \return Размер массива.
    int GetSize() const;

    //! \brief Возвращает вместимость массива.
    //! \return Вместимость массива.
    int GetCapacity() const;

    //! \brief Возвращает массив.
    //! \return Массив.
    int* GetArray() const;

    //! \brief Добавляет элемент в конец массива.
    //! \param value Значение элемента.
    void AddElement(int value);

    //! \brief Удаляет элемент массива по индексу.
    //! \param index Индекс элемента, который нужно удалить.
    void RemoveByIndex(int index);

    //! \brief Удаляет значение элемента по его значению.
    //! \param value Значение, которое нужно удалить.
    void RemoveByValue(int value);

    //! \brief Возвращает элемент по индексу.
    //! \param index Индекс элемента.
    //! \return Значение элемента под индексом.
    int GetElement(int index) const;

    //! \brief Вставляет элемент в начало массива.
    //! \param value Значение элемента.
    void InsertAtBeginning(int value);

    //! \brief Вставляет элемент в конец массива.
    //! \param value Значение элемента.
    void InsertAtEnd(int value);

    //! \brief Вставляет элемент после заданного значения.
    //! \param value Значение для вставки.
    //! \param afterValue Значение, после которого вставить.
    void InsertAfter(int value, int afterValue);

    //! \brief Сортирует массив методом сортировки слиянием.
    void SortArray();

    //! \brief Линейный поиск индекса элемента по значению.
    //! \param value Значение для поиска.
    //! \return Индекс элемента или -1, если элемент не найден.
    int LinearSearch(int value) const;

    //! \brief Бинарный поиск индекса элемента по значению.
    //! \param value Значение для поиска.
    //! \return Индекс элемента или -1, если элемент не найден.
    int BinarySearch(int value) const;

    //! \brief Выводит массив в консоль.
    void PrintArray() const;
};

#endif