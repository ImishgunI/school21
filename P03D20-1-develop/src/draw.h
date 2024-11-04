#ifndef DRAW_H
#define DRAW_H

/*

Структура программы.

    Модуль отрисовки графика (graph_drawer):
        Задача: Построение графика на экране терминала в пространстве 25x80 с учетом заданных границ.
        Вход: Массив значений функции для каждой точки по оси x.
        Выход: График, выведенный в терминал с помощью символов.

    Функции:
        draw_graph(): Отрисовывает график в текстовом виде на экране, используя координатную систему и
округление значений. map_to_screen(): Преобразует значения функции в координаты экрана (25x80).

*/
void draw_graph(double* values, int num_values);
#endif  // DRAW_H