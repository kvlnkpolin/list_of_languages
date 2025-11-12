def greedy_task_selection(tasks):
    sorted_tasks = sorted(tasks, key=lambda x: x[1])
    selected_tasks = []
    last_end_time = -1
    
    for task in sorted_tasks:
        start_time, end_time = task
        if start_time >= last_end_time:
            selected_tasks.append(task)
            last_end_time = end_time
    
    return selected_tasks

def main():
    # Входные данные
    tasks = [(1, 3), (2, 5), (4, 6), (5, 8), (7, 9), (8, 10)]
    
    print("Входные задачи:")
    for task in tasks:
        print(task)
    
    # Применяем алгоритм
    selected_tasks = greedy_task_selection(tasks)
    
    print("\nВыбранные задачи:")
    for task in selected_tasks:
        print(task)
    
    print(f"\nКоличество выбранных задач: {len(selected_tasks)}")
    print(f"Временная сложность: O(n log n)")
    print(f"Пространственная сложность: O(n)")

if __name__ == "__main__":
    main()
