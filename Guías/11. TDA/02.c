/*
2) Desarrollar un TDA de tipo t_racional que tiene definidas las siguientes
primitivas.
Se pide:
• Especificar pre y post condiciones de las primitivas definidas.
• Implementar las primitivas
typedef struct {
int num;
int den;
} t_racional;
void crear(int numerador, int denominador, t_racional r);
void simplificar(t_racional r);
bool mayor(t_racional r1, t_racional r2);
bool igual(t_racional r1, t_racional r2);
int numerador(t_racional r);
int denominador(t_racional r);
t_racional sumar(t_racional r1, t_racional r2);
t_racional restar(t_racional r1, t_racional r2);
t_racional multiplicar(t_racional r1, t_racional r2);
t_racional dividir(t_racional r1, t_racional r2);
*/