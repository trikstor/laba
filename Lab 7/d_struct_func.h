#ifndef d_stuct_func_h
#define d_stuct_func_h

struct point
{
	int key;									 // Содержание элемента списка
	point* next;								 // Указатель на следующий элемент списка
	point* pre;									 // Указатель на предыдущий элемент списка
};
/*
Создание корневого элемента списка, возвращает корневой элемент
*/
point* make_point(int);
/*
Вставка элемента в конец списка, возвращает указатель на последний элемент списка
*/
point* insert_elem(point*, int);
/*
Удаление элемента списка с соответствующим указателем
*/
point* delete_point(point*, point*);
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
point* delete_elem(point*, point*, int, int);
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
point *insert_root_elem(point*, int);

#endif
