#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Выбираем последний элемент как опорный
    int i = low - 1;        // Индекс меньшего элемента
    
    // Проходим по всем элементам от low до high-1
    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++;  // Увеличиваем индекс меньшего элемента
            swap(arr[i], arr[j]);  // Меняем элементы местами
        }
    }
    swap(arr[i + 1], arr[high]);  // Ставим опорный элемент на правильное место
    return i + 1;  // Возвращаем позицию опорного элемента
}

void quickSort(vector<int>& arr, int low, int high) {
    // Проверяем, что есть что сортировать
    if (low < high) {
        // Разделяем массив и получаем индекс опорного элемента
        int pi = partition(arr, low, high);
        
        // Рекурсивно сортируем элементы до и после опорного
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    // Выводим все элементы массива
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};  // Создаем тестовый массив
    
    cout << "Исходный массив: ";
    printArray(arr);  // Выводим исходный массив
    
    int n = arr.size();  // Получаем размер массива
    quickSort(arr, 0, n - 1);  // Сортируем массив
    
    cout << "Отсортированный массив: ";
    printArray(arr);  // Выводим отсортированный массив
    
    return 0;  // Завершаем программу
}
