#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcs.h"

/**
 * @brief Зчитує з окремого рядка дійсне число.
 *
 * @param file Вказівник на відкритий текстовий файл.
 * @param value Вказівник для збереження прочитаного числа.
 * @return 1 у разі успіху, 0 у разі помилки.
 */
static int read_double_line(FILE *file, double *value)
{
    char line[256];
    char extra;

    if (fgets(line, sizeof(line), file) == NULL)
        return 0;

    return sscanf(line, " %lf %c", value, &extra) == 1 && isfinite(*value);
}

/**
 * @brief Зчитує з окремого рядка ціле число.
 *
 * @param file Вказівник на відкритий текстовий файл.
 * @param value Вказівник для збереження прочитаного числа.
 * @return 1 у разі успіху, 0 у разі помилки.
 */
static int read_int_line(FILE *file, int *value)
{
    char line[256];
    char extra;

    if (fgets(line, sizeof(line), file) == NULL)
        return 0;

    return sscanf(line, " %d %c", value, &extra) == 1;
}

/**
 * @brief Зчитує непорожній текстовий рядок без символу нового рядка.
 *
 * @param file Вказівник на відкритий текстовий файл.
 * @param text Масив символів для збереження рядка.
 * @param size Розмір масиву символів.
 * @return 1 у разі успіху, 0 у разі помилки.
 */
static int read_text_line(FILE *file, char *text, size_t size)
{
    size_t length;

    if (fgets(text, (int)size, file) == NULL)
        return 0;

    length = strcspn(text, "\r\n");

    // Перевірка, що текстовий рядок прочитано повністю
    if (text[length] == '\0' && !feof(file))
    {
        int next = fgetc(file);
        if (next != '\n' && next != EOF)
            return 0;
    }

    text[length] = '\0';
    return length > 0;
}

int read_input_data(const char *filename, InputData *data)
{
    FILE *file;
    double expected_end;
    double tolerance;

    if (filename == NULL || data == NULL)
        return 0;

    // Відкриття вхідного файлу для читання
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Помилка: не вдалося відкрити файл %s.\n", filename);
        return 0;
    }

    // Зчитування числових параметрів і даних виконавця
    if (!read_double_line(file, &data->x_start) ||
        !read_double_line(file, &data->x_end) ||
        !read_int_line(file, &data->points) ||
        !read_double_line(file, &data->step) ||
        !read_text_line(file, data->group, sizeof(data->group)) ||
        !read_text_line(file, data->student, sizeof(data->student)))
    {
        printf("Помилка: вхідний файл містить некоректні або неповні дані.\n");
        fclose(file);
        return 0;
    }

    fclose(file);

    // Перевірка узгодженості діапазону, кроку та кількості точок
    if (data->points < 2 || data->step == 0.0)
    {
        printf("Помилка: кількість точок має бути не менше 2, а крок — ненульовим.\n");
        return 0;
    }

    expected_end = data->x_start + (data->points - 1) * data->step;
    tolerance = 1e-8 * (1.0 + fabs(data->x_end));

    if (!isfinite(expected_end) || fabs(expected_end - data->x_end) > tolerance)
    {
        printf("Помилка: кінцеве значення аргументу не відповідає кроку та кількості точок.\n");
        return 0;
    }

    return 1;
}
