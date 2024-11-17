#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

//! \brief ��������� ������������� �������.
struct DynamicArray {
private:
    //! \brief ������ �������.
    int _size;

    //! \brief ����������� �������.
    int _capacity;

    //! \brief ������.
    int* _array;

    //! \brief ������ ����� �������.
    int _growthFactor;

    //! \brief �������� ����������� �������.
    //! \param newCapacity ����� ����������� �������.
    void resize(int newCapacity);

    //! \brief ��������������� ������� ���������� ��������.
    //! \param left ����� ������.
    //! \param right ������ ������.
    void mergeSort(int left, int right);

    //! \brief ��������������� ������� ��� ������� ������ �������.
    //! \param left ����� ������.
    //! \param mid ������� ������.
    //! \param right ������ ������.
    void merge(int left, int mid, int right);

public:
    //! \brief ����������� �������.
    //! \param initCapacity ��������� �����������.
    //! \param growthFactor ������ ����� �������.
    DynamicArray(int initCapacity = 8, int growthFactor = 2);

    //! \brief ���������� �������.
    ~DynamicArray();

    //! \brief ���������� ������ �������.
    //! \return ������ �������.
    int GetSize() const;

    //! \brief ���������� ����������� �������.
    //! \return ����������� �������.
    int GetCapacity() const;

    //! \brief ���������� ������.
    //! \return ������.
    int* GetArray() const;

    //! \brief ��������� ������� � ����� �������.
    //! \param value �������� ��������.
    void AddElement(int value);

    //! \brief ������� ������� ������� �� �������.
    //! \param index ������ ��������, ������� ����� �������.
    void RemoveByIndex(int index);

    //! \brief ������� �������� �������� �� ��� ��������.
    //! \param value ��������, ������� ����� �������.
    void RemoveByValue(int value);

    //! \brief ���������� ������� �� �������.
    //! \param index ������ ��������.
    //! \return �������� �������� ��� ��������.
    int GetElement(int index) const;

    //! \brief ��������� ������� � ������ �������.
    //! \param value �������� ��������.
    void InsertAtBeginning(int value);

    //! \brief ��������� ������� � ����� �������.
    //! \param value �������� ��������.
    void InsertAtEnd(int value);

    //! \brief ��������� ������� ����� ��������� ��������.
    //! \param value �������� ��� �������.
    //! \param afterValue ��������, ����� �������� ��������.
    void InsertAfter(int value, int afterValue);

    //! \brief ��������� ������ ������� ���������� ��������.
    void SortArray();

    //! \brief �������� ����� ������� �������� �� ��������.
    //! \param value �������� ��� ������.
    //! \return ������ �������� ��� -1, ���� ������� �� ������.
    int LinearSearch(int value) const;

    //! \brief �������� ����� ������� �������� �� ��������.
    //! \param value �������� ��� ������.
    //! \return ������ �������� ��� -1, ���� ������� �� ������.
    int BinarySearch(int value) const;

    //! \brief ������� ������ � �������.
    void PrintArray() const;
};

#endif