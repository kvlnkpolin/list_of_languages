def greedy_task_selection(tasks):
    # Сортируем задачи по времени окончания
    sorted_tasks = sorted(tasks, key=lambda x: x[1])
    selected_tasks = []
    last_end_time = -1
    
    # Выбираем задачи, которые не пересекаются по времени
    for task in sorted_tasks:
        start_time, end_time = task
        if start_time >= last_end_time:
            selected_tasks.append(task)
            last_end_time = end_time
    
    return selected_tasks

# Входные данные - задачи с временными интервалами
tasks = [(1, 3), (2, 5), (4, 6), (5, 8), (7, 9), (8, 10)]

print("Все задачи:")
for task in tasks:
    print(task)

# Применяем алгоритм выбора задач
selected_tasks = greedy_task_selection(tasks)

print("\nВыбранные непересекающиеся задачи:")
for task in selected_tasks:
    print(task)

print(f"\nИтог: выбрано {len(selected_tasks)} из {len(tasks)} задач")
