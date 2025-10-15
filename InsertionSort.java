public class InsertionSort {
    
    public static void insertionSort(int[] array) {
        int n = array.length;  // Получаем длину массива
        
        // Начинаем со второго элемента (индекс 1)
        for (int i = 1; i < n; i++) {
            int key = array[i];  // Текущий элемент для вставки
            int j = i - 1;       // Индекс последнего элемента отсортированной части
            
            // Сдвигаем элементы большие key вправо
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];  // Сдвигаем элемент вправо
                j = j - 1;                // Переходим к следующему элементу слева
            }
            
            array[j + 1] = key;  // Вставляем key в правильную позицию
        }
    }
    
    public static void printArray(int[] array) {
        // Выводим все элементы массива
        for (int value : array) {
            System.out.print(value + " ");  // Выводим элемент с пробелом
        }
        System.out.println();  // Переходим на новую строку
    }
    
    public static void main(String[] args) {
        int[] array = {12, 11, 13, 5, 6};  // Создаем тестовый массив
        
        System.out.print("Исходный массив: ");
        printArray(array);  // Выводим исходный массив
        
        insertionSort(array);  // Сортируем массив
        
        System.out.print("Отсортированный массив: ");
        printArray(array);  // Выводим отсортированный массив
    }
}
