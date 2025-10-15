#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibonacciSearch(const vector<int>& arr, int x) {
    // Получаем размер массива
    int n = arr.size();
    
    // Инициализируем числа Фибоначчи
    int fibMMm2 = 0; // (m-2)-е число Фибоначчи
    int fibMMm1 = 1; // (m-1)-е число Фибоначчи
    int fibM = fibMMm2 + fibMMm1; // m-е число Фибоначчи
    
    // Находим наименьшее число Фибоначчи, большее или равное n
    while (fibM < n) {
        // Обновляем числа Фибоначчи для следующей итерации
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    
    // Отмечаем удаленный диапазон спереди
    int offset = -1;
    
    // Пока есть элементы для проверки
    while (fibM > 1) {
        // Проверяем, не выходит ли i за пределы массива
        int i = min(offset + fibMMm2, n - 1);
        
        // Если x больше значения в i, отрезаем подмассив от offset до i
        if (arr[i] < x) {
            // Обновляем числа Фибоначчи
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            // Обновляем offset
            offset = i;
        }
        // Если x меньше значения в i, отрезаем подмассив после i
        else if (arr[i] > x) {
            // Обновляем числа Фибоначчи
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        // Если элемент найден
        else {
            // Возвращаем индекс найденного элемента
            return i;
        }
    }
    
    // Сравниваем последний элемент с x
    if (fibMMm1 && offset + 1 < n && arr[offset + 1] == x) {
        // Возвращаем индекс, если элемент найден
        return offset + 1;
    }
    
    // Возвращаем -1, если элемент не найден
    return -1;
}

int main() {
    // Создаем отсортированный массив
    vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    // Задаем целевое значение для поиска
    int x = 85;
    
    // Выполняем поиск Фибоначчи
    int result = fibonacciSearch(arr, x);
    
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
