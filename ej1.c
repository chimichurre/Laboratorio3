#include <stdio.h>

int main() {
    int num_triangulares[100];
    int i, suma = 0;

    //Computar los números triangulares y almacenarlos en el array
    for (i = 0; i < 100; i++) {
        suma += i;
        num_triangulares[i] = suma;
    }

    //Imprimir los números triangulares
    printf("Los primeros 100 números triangulares son:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", num_triangulares[i]);
    }
    printf("\n");

    return 0;
}