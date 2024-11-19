#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

// �������� ������� ��� ����������� ������������� �������� �������� ������
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

// ��������� ���� ��� ���������� ������ �� ��������
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

    // ����� ��� ���������� ������ �� ��������
    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    // ����� ��� ��������� ������
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
    // ������ ��� �������� �������� ������� �� �����
    int intArr[] = { 1, 5, 3, 9, 2 };
    double doubleArr[] = { 1.5, 3.7, 0.8, 9.3, 2.4 };

    // ������ �������� ������� ��� ����������� ������������� ��������
    int maxInt = findMax<int>(intArr, 5);
    double maxDouble = findMax<double>(doubleArr, 5);

    cout << "�������� � ����� int: " << maxInt << endl;
    cout << "�������� � ����� double: " << maxDouble << endl;

    // ������������ ������������ ���������� ����� ��� ����������
    int intArrToSort[] = { 4, 2, 9, 1, 5 };
    SortDescending<int> sorter(intArrToSort, 5);

    cout << "����� �� ����������: ";
    sorter.display();

    sorter.sort();

    cout << "����� ���� ���������� �� ��������: ";
    sorter.display();

    return 0;
}
