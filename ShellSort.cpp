#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr) {
    // Получаем размер массива
    int n = arr.size();
    
    // Начинаем с большого gap, затем уменьшаем его
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Делаем сортировку вставками для этого gap
        for (int i = gap; i < n; i++) {
            // Сохраняем arr[i] во временной переменной
            int temp = arr[i];
            int j;
            
            // Сдвигаем ранее отсортированные элементы, пока не найдем правильное место для arr[i]
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                // Сдвигаем элемент на gap позиций вперед
                arr[j] = arr[j - gap];
            }
            
            // Вставляем temp в правильное место
            arr[j] = temp;
        }
    }
}

void printArray(const vector<int>& arr) {
    // Проходим по всем элементам массива
    for (int i = 0; i < arr.size(); i++) {
        // Выводим текущий элемент
        cout << arr[i] << " ";
    }
    // Переходим на новую строку
    cout << endl;
}

int main() {
    // Создаем тестовый массив
    vector<int> arr = {12, 34, 54, 2, 3};
    
    // Выводим исходный массив
    cout << "Исходный массив: ";
    printArray(arr);
    
    // Сортируем массив
    shellSort(arr);
    
    // Выводим отсортированный массив
    cout << "Отсортированный массив: ";
    printArray(arr);
    
    // Завершаем программу
    return 0;
}
