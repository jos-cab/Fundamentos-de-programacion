/*
7) Implementar una función que retorna un puntero a un vector de n struct del
tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica,
respetando la siguiente declaración. En caso de no poder reservar la memoria,
retornar NULL.

t_alumno* crear_alumnos(int n);

typedef struct {
int padron;
char nombre[30];
char apellido[30];
} t_alumno;
*/