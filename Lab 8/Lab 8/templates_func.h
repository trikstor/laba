#ifndef templates_func_h
#define templates_func_h

template <typename T>
struct point
{
	T key;									 // Содержание элемента списка
	point *next;								 // Указатель на следующий элемент списка
	point *pre;									 // Указатель на предыдущий элемент списка
};
/*
Создание корневого элемента списка, возвращает корневой элемент
*/
template <typename T>
point *make_point(T);
/*
Вставка элемента в конец списка, возвращает указатель на последний элемент списка
*/
template <typename T>
point *insert_elem(point*, T);
/*
Удаление элемента списка с соответствующим указателем
*/
point *delete_point(point*, point*);
/*
Печать списка
*/
void listprint(point*, int);
/*
Удаление всех элементов списка
*/
point* delete_all(point*);
/*
Удаление заданного количества элементов до заданного
*/
template <typename T>
point* delete_elem(point*, point*, T, int);
/*
Запись списка в файл
*/
void in_file(point*, char*, int);
/*
Вывод списка из файла
*/
point* from_file(char*);
/*
Запись дополнительных элементов в начало файла
*/
point* insert_root_elem(point*, int);
/*
Запись элементов в конец списка
*/
point* insert_end_elem(point*, int);
/*
Функция для получения ключевого значения списка из потока
*/
template <typename T>
T scan_elem(T);

#endif
