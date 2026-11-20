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

#endif
