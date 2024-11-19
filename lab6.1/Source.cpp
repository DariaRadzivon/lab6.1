#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

// Шаблонна функція для знаходження максимального значення елементів масиву
template <typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Шаблонний клас для сортування масиву по спаданню
template <typename T>
class SortDescending {
private:
    T* arr;
    int size;

public:
    SortDescending(T arr[], int size) {
        this->size = size;
        this->arr = new T[size];
        for (int i = 0; i < size; ++i) {
            this->arr[i] = arr[i];
        }
    }

    // Метод для сортування масиву по спаданню
    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    // Метод для виведення масиву
    void display() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~SortDescending() {
        delete[] arr;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Масиви для перевірки шаблонної функції та класу
    int intArr[] = { 1, 5, 3, 9, 2 };
    double doubleArr[] = { 1.5, 3.7, 0.8, 9.3, 2.4 };

    // Виклик шаблонної функції для знаходження максимального значення
    int maxInt = findMax<int>(intArr, 5);
    double maxDouble = findMax<double>(doubleArr, 5);

    cout << "Максимум у масиві int: " << maxInt << endl;
    cout << "Максимум у масиві double: " << maxDouble << endl;

    // Демонстрація використання шаблонного класу для сортування
    int intArrToSort[] = { 4, 2, 9, 1, 5 };
    SortDescending<int> sorter(intArrToSort, 5);

    cout << "Масив до сортування: ";
    sorter.display();

    sorter.sort();

    cout << "Масив після сортування по спаданню: ";
    sorter.display();

    return 0;
}
