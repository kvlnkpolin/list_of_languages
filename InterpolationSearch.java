public class InterpolationSearch {
    
    public static int interpolationSearch(int[] arr, int x) {
        int low = 0;
        int high = arr.length - 1;
        
        while (low <= high && x >= arr[low] && x <= arr[high]) {
            // Вычисляем предполагаемую позицию с помощью интерполяционной формулы
            int pos = low + ((high - low) * (x - arr[low])) / (arr[high] - arr[low]);
            
            if (arr[pos] == x) {
                return pos;  // Элемент найден
            } else if (arr[pos] < x) {
                low = pos + 1;  // Ищем в правой части
            } else {
                high = pos - 1;  // Ищем в левой части
            }
        }
        
        return -1;  // Элемент не найден
    }
    
    public static void main(String[] args) {
        int[] arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
        int x = 18;
        
        int result = interpolationSearch(arr, x);
        
        if (result != -1) {
            System.out.println("Элемент найден на позиции: " + result);
        } else {
            System.out.println("Элемент не найден");
        }
    }
}