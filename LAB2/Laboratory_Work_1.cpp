#include "DynamicArray.h"
#include <iostream>

//! \brief Выводит меню опций для пользователя.
void printMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add element to the end\n";
    std::cout << "2. Remove element by index\n";
    std::cout << "3. Remove element by value\n";
    std::cout << "4. Insert element at beginning\n";
    std::cout << "5. Insert element at the end\n";
    std::cout << "6. Insert element after given value\n";
    std::cout << "7. Sort the array\n";
    std::cout << "8. Linear search\n";
    std::cout << "9. Binary search\n";
    std::cout << "10. Show the array\n";
    std::cout << "0. Quit\n";
    std::cout << "Choose the option: ";
}

int main() {
    DynamicArray array;
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            //! \brief Добавление элемента в конец массива.
            int value;
            std::cout << "Enter value to add: ";
            std::cin >> value;
            array.AddElement(value);
            break;
        }
        case 2: {
            //! \brief Удаление элемента по индексу.
            int index;
            std::cout << "Enter index to delete: ";
            std::cin >> index;
            try {
                array.RemoveByIndex(index);
            }
            catch (const std::out_of_range& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            //! \brief Удаление элемента по значению.
            int value;
            std::cout << "Enter value to delete: ";
            std::cin >> value;
            array.RemoveByValue(value);
            break;
        }
        case 4: {
            //! \brief Вставка элемента в начало массива.
            int value;
            std::cout << "Enter a value to insert at the beginning: ";
            std::cin >> value;
            array.InsertAtBeginning(value);
            break;
        }
        case 5: {
            //! \brief Вставка элемента в конец массива.
            int value;
            std::cout << "Enter a value to insert at the end: ";
            std::cin >> value;
            array.InsertAtEnd(value);
            break;
        }
        case 6: {
            //! \brief Вставка элемента после определенного значения.
            int value, afterValue;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            std::cout << "Enter the value after which to insert: ";
            std::cin >> afterValue;
            array.InsertAfter(value, afterValue);
            break;
        }
        case 7: {
            //! \brief Сортировка массива.
            array.SortArray();
            std::cout << "Array sorted.\n";
            break;
        }
        case 8: {
            //! \brief Линейный поиск элемента.
            int value;
            std::cout << "Enter a value for linear search: ";
            std::cin >> value;
            int index = array.LinearSearch(value);
            if (index != -1) {
                std::cout << "Element found at index: " << index << std::endl;
            }
            else {
                std::cout << "Element not found.\n";
            }
            break;
        }
        case 9: {
            //! \brief Бинарный поиск элемента.
            int value;
            std::cout << "Enter a value for binary search: ";
            std::cin >> value;
            int index = array.BinarySearch(value);
            if (index != -1) {
                std::cout << "Element found at index: " << index << std::endl;
            }
            else {
                std::cout << "Element not found.\n";
            }
            break;
        }
        case 10: {
            //! \brief Вывод массива.
            std::cout << "Array: ";
            array.PrintArray();
            break;
        }
        case 0:
            std::cout << "Exit.\n";
            break;
        default:
            std::cout << "Incorrect choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
