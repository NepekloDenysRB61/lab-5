
/**
 * @file funcs.h
 * @brief Оголошення структур даних і прототипів функцій лабораторної роботи № 5.
 * @author Непекло Денис, група РБ-61.
 */

#ifndef FUNCS_H
#define FUNCS_H

#define GROUP_SIZE 32
#define NAME_SIZE 128

typedef struct
{
    double x_start;
    double x_end;
    double step;
    int points;
    char group[GROUP_SIZE];
    char student[NAME_SIZE];
} InputData;

/**
 * @brief Зчитує початкові дані лабораторної роботи з текстового файлу.
 *
 * @param filename Ім'я вхідного текстового файлу.
 * @param data Вказівник на структуру для збереження зчитаних даних.
 * @return 1 у разі успішного зчитування, 0 у разі помилки.
 */
int read_input_data(const char *filename, InputData *data);

/**
 * @brief Обчислює математичну функцію для варіанта № 10.
 *
 * @param x Значення аргументу функції.
 * @return Значення функції f(x).
 */
double calculate_function(double x);

/**
 * @brief Виводить таблицю значень математичної функції на екран.
 *
 * @param data Вказівник на структуру з початковими даними.
 */
void print_function_table(const InputData *data);

/**
 * @brief Записує таблицю функції та дані студента до текстового файлу.
 *
 * @param filename Ім'я вихідного текстового файлу.
 * @param data Вказівник на структуру з початковими даними.
 * @return 1 у разі успішного запису, 0 у разі помилки.
 */
int write_text_file(const char *filename, const InputData *data);

/**
 * @brief Записує кількість точок і пари значень x та f(x) до бінарного файлу.
 *
 * @param filename Ім'я вихідного бінарного файлу.
 * @param data Вказівник на структуру з початковими даними.
 * @return 1 у разі успішного запису, 0 у разі помилки.
 */
int write_binary_file(const char *filename, const InputData *data);

/**
 * @brief Зчитує таблицю з бінарного файлу у динамічний масив і виводить її.
 *
 * @param filename Ім'я вхідного бінарного файлу.
 * @return 1 у разі успішного зчитування, 0 у разі помилки.
 */
int read_binary_file(const char *filename);

#endif
