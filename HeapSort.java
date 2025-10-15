public class HeapSort {
    
    public static void heapSort(int[] arr) {
        // Получаем длину массива
        int n = arr.length;
        
        // Построение max-кучи (перегруппируем массив)
        // Начинаем с последнего нелистового узла
        for (int i = n / 2 - 1; i >= 0; i--) {
            // Преобразуем поддерево с корнем i в кучу
            heapify(arr, n, i);
        }
        
        // Один за другим извлекаем элементы из кучи
        for (int i = n - 1; i > 0; i--) {
            // Перемещаем текущий корень в конец
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
            // Вызываем heapify на уменьшенной куче
            heapify(arr, i, 0);
        }
    }
    
    // Функция для преобразования поддерева в кучу
    private static void heapify(int[] arr, int n, int i) {
        // Инициализируем наибольший элемент как корень
        int largest = i;
        // Вычисляем индекс левого дочернего элемента
        int left = 2 * i + 1;
        // Вычисляем индекс правого дочернего элемента
        int right = 2 * i + 2;
        
        // Если левый дочерний элемент больше корня
        if (left < n && arr[left] > arr[largest]) {
            // Обновляем индекс наибольшего элемента
            largest = left;
        }
        
        // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
        if (right < n && arr[right] > arr[largest]) {
            // Обновляем индекс наибольшего элемента
            largest = right;
        }
        
        // Если самый большой элемент не корень
        if (largest != i) {
            // Меняем местами корень и наибольший элемент
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            
            // Рекурсивно преобразуем в кучу затронутое поддерево
            heapify(arr, n, largest);
        }
    }
    
    public static void printArray(int[] arr) {
        // Проходим по всем элементам массива
        for (int value : arr) {
            // Выводим текущий элемент
            System.out.print(value + " ");
        }
        // Переходим на новую строку
        System.out.println();
    }
    
    public static void main(String[] args) {
        // Создаем тестовый массив
        int[] arr = {12, 11, 13, 5, 6, 7};
        
        // Выводим исходный массив
        System.out.print("Исходный массив: ");
        printArray(arr);
        
        // Сортируем массив
        heapSort(arr);
        
        // Выводим отсортированный массив
        System.out.print("Отсортированный массив: ");
        printArray(arr);
    }
}
