#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE_MAX 10
#define SIZE_MIN 1

int findLargestSquare(int matrix[][SIZE_MAX], int size);

int main() {
    int n, i, j;
    int matrix[SIZE_MAX][SIZE_MAX];
    
    //Solicitándole al usuario el tamaño de la matriz nxn
    printf("Ingrese un valor del 1 al 10 para denotar el número de filas de la matriz nxn: ");
    scanf("%d", &n);

    //CONSTATAR que el tamaño ingresado esté dentro del rango permitido
    if (n < SIZE_MIN || n > SIZE_MAX) {
        printf("El número ingresado no es válido. Se utilizará un valor por defecto.\n");
        n = 9; //Valor por defecto
    }

    //Llena la matriz de manera aleatoria
    srand(time(NULL)); //Inicializado el valor inicial del generador de números aleatorios
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 2; //Suscitar un número aleatorio entre 0 y 1
        }
    }

    //Revelar la matriz generada
    printf("La matriz utilizada corresponde a:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //Hallando el tamaño del cuadrado más grande de unos
    int largestSquareSize = findLargestSquare(matrix, n);
    printf("El tamaño del cuadrado más grande de unos es: %dx%d\n", largestSquareSize, largestSquareSize);

    return 0;
}

int findLargestSquare(int matrix[][SIZE_MAX], int size) {
    int max = 0;
    int i, j;

    //Inicializando la matriz para almacenar los tamaños de los cuadrados
    int dp[size][size];
    
    //Llenando la primera fila y la primera columna de la matriz dp
    for (i = 0; i < size; i++) {
        dp[i][0] = matrix[i][0];
        dp[0][i] = matrix[0][i];
        if (dp[i][0] > max || dp[0][i] > max)
            max = 1;
    }

    //Ubicar los tamaños de los cuadrados y actualizar el máximo
    for (i = 1; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = 1 + fmin(dp[i - 1][j], fmin(dp[i][j - 1], dp[i - 1][j - 1]));
                if (dp[i][j] > max)
                    max = dp[i][j];
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return max;
}