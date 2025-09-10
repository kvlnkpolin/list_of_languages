//представление массива данных на C++

#include <iostream> #include <list>  
int main() {  
// Создать список с элементами  
std::list<int> numbers = {1, 2, 3, 4, 5};  
// Вывести элементы списка  
for (int num : numbers) { std::cout << num << " "; }  
return 0;  
}  

//пример кода организации стека на C++

struct stack {  
    int a[1000];  
    int head = -1; //Индекс крайнего элемента  
    void push(int x) {  
        head++;  
        a[head] = x;  
    }  
    int pop() {  
        if (head != -1) {  
            head--;  
            return a[head + 1];  
        } else {  
            // Ошибка, попытка извлечь элемент из пустого стека  
        }  
    }  
    bool is_empty() {  
        return head == -1;  
    }  
}; 