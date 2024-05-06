#include <stdio.h>

//Computar el factorial de un número dado
int factorial(int n) {
    int i = 1; //Comienzo del contador del factorial
    while (n > 1) {
        i = i * n;
        n = n - 1;
    }
    return i;
}

//Procesamiento de los argumentos de la línea de comandos
int main(int argc, char *argv[]) {
    int num;   //Variable para guardar el número ingresado por el usuario
    printf("Por favor, ingrese un número para calcular su factorial: ");
    scanf("%d", &num);

    int fac_num = factorial(num);
    printf("%d! = %d\n", num, fac_num);

    return 0;
}