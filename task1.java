
// представление массива данных на Java


students.add("Джон");  
students.add("Джейн");  
students.add("Doe");  
System.out.println(students); // [Джон, Джейн, Doe]  



// пример кода организаци стека на Java



public class MyStack<T> {  
    private T stackArray;  
    private int top;  
    public MyStack(int capacity) {  
        stackArray = (T) new Object[capacity];  
        top = -1;  
    }  
    public void push(T item) {  
        if (top == stackArray.length - 1) {  
            throw new IllegalStateException("Stack overflow");  
        }  
        stackArray[++top] = item;  
    }  
    public T pop() {  
        if (top == -1) {  
            throw new IllegalStateException("Stack underflow");  
        }  
        return stackArray[top--];  
    }  
    public T peek() {  
        if (top == -1) {  
            throw new IllegalStateException("Stack is empty");  
        }  
        return stackArray[top];  
    }  
    public boolean isEmpty() {  
        return (top == -1);  
    }  
    public int size() {  
        return (top + 1);  
    }  
}  
