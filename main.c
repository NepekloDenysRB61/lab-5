
#include <stdio.h>
#include <windows.h>
#include "funcs.h"

/**
 * @brief Зчитує дані, формує таблицю функції, зберігає та відновлює її з файлів.
 *
 * @return 0 у разі успішного виконання, 1 у разі помилки.
 */
int main(void)
{
    InputData data;

    SetConsoleOutputCP(CP_UTF8);

    printf("Лабораторна робота № 5. Робота з файлами.\n\n");

    if (!read_input_data("input.txt", &data))
        return 1;

    printf("Початкове значення x: %.6f\n", data.x_start);
    printf("Кінцеве значення x: %.6f\n", data.x_end);
    printf("Кількість точок: %d\n", data.points);
    printf("Крок: %.6f\n", data.step);
    printf("Група: %s\n", data.group);
    printf("Виконавець: %s\n", data.student);

    // Побудова таблиці значень функції за вхідними даними
    printf("\nТаблиця значень функції:\n");
    print_function_table(&data);

    // Збереження таблиці в текстовому та бінарному форматах
    if (!write_text_file("output.txt", &data))
        return 1;

    if (!write_binary_file("output.bin", &data))
        return 1;

    printf("\nТекстовий файл output.txt створено успішно.\n");
    printf("Бінарний файл output.bin створено успішно.\n");

    // Повторне зчитування результатів із бінарного файлу
    if (!read_binary_file("output.bin"))
        return 1;

    return 0;
}
