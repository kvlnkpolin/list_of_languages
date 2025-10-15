#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    // Проходим по всем элементам массива
    for (int i = 0; i < n - 1; i++) {
        // Предполагаем, что текущий элемент минимальный
        int minIndex = i;
        
        // Ищем минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; j++) {
            // Если находим элемент меньше текущего минимального
            if (arr[j] < arr[minIndex]) {
                // Обновляем индекс минимального элемента
                minIndex = j;
            }
        }
        
        // Меняем местами найденный минимальный элемент с текущим
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    // Выводим все элементы массива
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Создаем тестовый массив
    int arr[] = {64, 25, 12, 22, 11};
    // Вычисляем размер массива
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Выводим исходный массив
    cout << "Исходный массив: ";
    printArray(arr, n);
    
    // Сортируем массив
    selectionSort(arr, n);
    
    // Выводим отсортированный массив
    cout << "Отсортированный массив: ";
    printArray(arr, n);
    
    return 0;
}
