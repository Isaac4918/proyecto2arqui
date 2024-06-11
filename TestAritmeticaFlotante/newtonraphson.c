#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <stdio.h>
#include <math.h>

double raiz_cuadrada(double S, double x0, int iteraciones) {
    // Metodo de Newton-Raphson para encontrar la raiz cuadrada de S
    double xn = x0;
    for (int i = 0; i < iteraciones; i++) {
        xn = 0.5 * (xn + S / xn);
    }
    return xn;
}

int main() {
    double S = 10.0;
    double x0 = 1.0; 
    int iteraciones = 1000000;
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    double resultado = raiz_cuadrada(S, x0, iteraciones);
    printf("Raiz cuadrada de %.2f = %.15f\n", S, resultado);

    end = clock();
    cpu_time_used = (((double) (end - start)) / (CLOCKS_PER_SEC / 1000))*0.3657;
    printf("Tiempo para quicksort: %f segundos\n", cpu_time_used);

    return 0;
}
