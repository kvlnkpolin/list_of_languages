import java.util.Arrays;

public class MergeSort {
    
    public static int[] mergeSort(int[] arr) {
        // Базовый случай: массив из 0 или 1 элемента уже отсортирован
        if (arr.length <= 1) {
            // Возвращаем массив как есть
            return arr;
        }
        
        // Находим середину массива
        int mid = arr.length / 2;
        
        // Делим массив на левую и правую части
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);
        
        // Рекурсивно сортируем обе половины
        left = mergeSort(left);
        right = mergeSort(right);
        
        // Объединяем отсортированные половины
        return merge(left, right);
    }
    
    public static int[] merge(int[] left, int[] right) {
        // Создаем результирующий массив
        int[] result = new int[left.length + right.length];
        // Индексы для левого, правого и результирующего массивов
        int i = 0, j = 0, k = 0;
        
        // Пока есть элементы в обоих массивах
        while (i < left.length && j < right.length) {
            // Сравниваем элементы из левого и правого массивов
            if (left[i] <= right[j]) {
                // Добавляем элемент из левого массива
                result[k] = left[i];
                // Увеличиваем индекс левого массива
                i++;
            } else {
                // Добавляем элемент из правого массива
                result[k] = right[j];
                // Увеличиваем индекс правого массива
                j++;
            }
            // Увеличиваем индекс результирующего массива
            k++;
        }
        
        // Добавляем оставшиеся элементы из левого массива
        while (i < left.length) {
            // Копируем элемент из левого массива
            result[k] = left[i];
            // Увеличиваем индексы
            i++;
            k++;
        }
        
        // Добавляем оставшиеся элементы из правого массива
        while (j < right.length) {
            // Копируем элемент из правого массива
            result[k] = right[j];
            // Увеличиваем индексы
            j++;
            k++;
        }
        
        // Возвращаем объединенный отсортированный массив
        return result;
    }
    
    public static void printArray(int[] arr) {
        // Проходим по всем элементам массива
        for (int i = 0; i < arr.length; i++) {
            // Выводим текущий элемент
            System.out.print(arr[i] + " ");
        }
        // Переходим на новую строку
        System.out.println();
    }
    
    public static void main(String[] args) {
        // Создаем тестовый массив
        int[] array = {38, 27, 43, 3, 9, 82, 10};
        
        // Выводим исходный массив
        System.out.print("Исходный массив: ");
        printArray(array);
        
        // Сортируем массив
        int[] sortedArray = mergeSort(array);
        
        // Выводим отсортированный массив
        System.out.print("Отсортированный массив: ");
        printArray(sortedArray);
    }
}
