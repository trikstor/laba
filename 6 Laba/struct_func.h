#ifndef struct_func_h
#define struct_func_h

// Считывание данных из файла в консоль
void while_read(char*, struct patient, int);

// Заполнение temp_file записями из file за исключением записей с указанным num
int while_reader(char* ,char*, struct patient, int, int);

// Печать структуры
void print_struct(struct patient);

// Функция считывания данных из потока
patient cin_get(struct patient);

// Функция записи мед, карт из потока в файл
void insert_file(char *, struct patient, int);

// Функция очищения файла , и записи в него 2 новых записей из потока
void insert_newfile(char*, char*, struct patient, int);

// Функция для копирования файлов
void filecpy(char*, char*, struct patient, int);

// Удаление файла
void delete_f(char*);

#endif
