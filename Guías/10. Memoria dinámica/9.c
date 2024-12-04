/*
9) Reservar memoria para almacenar una palabra ingresada por el usuario, es
leída en una cadena auxiliar, luego copiada a memoria dinámica, recordando
que se requiere adicionar un carácter de fin de cadena '\n'.
Ejemplo:
"hola mundo" + '\0' -> requiere espacio para 11 caracteres.

char* cadena_aux = "hola mundo";
char* cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);
*/