#ifndef struct_func_h
#define struct_func_h

// ���������� ������ �� ����� � �������
void while_read(char*, struct patient, int);

// ���������� temp_file �������� �� file �� ����������� ������� � ��������� num
int while_reader(char* ,char*, struct patient, int, int);

// ������ ���������
void print_struct(struct patient);

// ������� ���������� ������ �� ������
patient cin_get(struct patient);

// ������� ������ ���, ���� �� ������ � ����
void insert_file(char *, struct patient, int);

// ������� �������� ����� , � ������ � ���� 2 ����� ������� �� ������
void insert_newfile(char*, char*, struct patient, int);

// ������� ��� ����������� ������
void filecpy(char*, char*, struct patient, int);

// �������� �����
void delete_f(char*);

#endif
