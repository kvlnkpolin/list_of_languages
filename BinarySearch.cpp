#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    // Инициализируем левую границу поиска
    int left = 0;
    // Инициализируем правую границу поиска
    int right = arr.size() - 1;
    
    // Пока интервал поиска не пуст
    while (left <= right) {
        // Находим средний элемент
        int mid = left + (right - left) / 2;
        
        // Проверяем, равен ли средний элемент целевому
        if (arr[mid] == target) {
            // Возвращаем индекс найденного элемента
            return mid;
        }
        
        // Если целевой элемент меньше среднего
        if (arr[mid] > target) {
            // Сужаем поиск до левой половины
            right = mid - 1;
        } else {
            // Сужаем поиск до правой половины
            left = mid + 1;
        }
    }
    
    // Элемент не найден, возвращаем -1
    return -1;
}

int main() {
    // Создаем отсортированный массив
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    // Задаем целевое значение для поиска
    int target = 7;
    
    // Выполняем бинарный поиск
    int result = binarySearch(sortedArray, target);
    
    // Проверяем результат поиска
    if (result != -1) {
        // Выводим сообщение о найденном элементе
        cout << "Элемент найден на позиции: " << result << endl;
    } else {
        // Выводим сообщение о ненайденном элементе
        cout << "Элемент не найден" << endl;
    }
    
    // Завершаем программу
    return 0;
}
