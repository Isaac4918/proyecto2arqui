#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

/*
    El objetivo del programa es realizar un
    benchmark utilizando la conjetura de Collatz
*/

// Funciones
/*
    Realiza la conjetura de Collatz para un número dado

    Complejidad: O(log n)
*/
void collatz_conjecture(unsigned long long n) {
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = 3 * n + 1;
        }
    }
}

/*
    Realiza collatz_conjecture() una cantidad
    "m" de veces (number_iterations)

    Complejidad: O(m log n) (m: number_iterations)
*/
double cicle_collatz_conjecture(int number_iterations) {
    std::vector<double> execution_times;

    for (int i = 0; i < number_iterations; ++i) {
        // Iteración
        std::cout << "Iteración #" << i + 1 << std::endl;

        // Generar un número grande
        unsigned long long num = 12345678901234567ULL + i;

        // Tiempo de inicio
        auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Inicio: " <<
            std::chrono::duration_cast<std::chrono::milliseconds>(start.time_since_epoch()).count() <<
            " ms" << std::endl;

        // Ejecutar la conjetura de Collatz
        collatz_conjecture(num);

        // Obtener el tiempo de finalización
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Fin: " <<
            std::chrono::duration_cast<std::chrono::milliseconds>(end.time_since_epoch()).count() <<
            " ms" << std::endl;

        // Calcular la duración
        std::chrono::duration<double> duration = end - start;
        execution_times.push_back(duration.count());

        // Imprimir el tiempo que tomó la ejecución
        std::cout << "Ejecucion: " << duration.count() << " segundos" << std::endl;

        // Separador
        std::cout << "-----------------------------------------------------------------------" << std::endl;
    }

    // Calcular el promedio de los tiempos de ejecución
    double average_time = std::accumulate(execution_times.begin(), execution_times.end(), 0.0) / execution_times.size();

    // Retornar el valor
    return average_time;
}

// Benchmark
void benchmark_collatz(int number_iterations) {

    // Tiempo de inicio
    auto start = std::chrono::high_resolution_clock::now();

    // Ejecución de ciclo intensivo y promedio de las iteraciones
    double average_time = cicle_collatz_conjecture(number_iterations);

    // Obtener el tiempo de finalización
    auto end = std::chrono::high_resolution_clock::now();

    // Calcular la duración
    std::chrono::duration<double> duration = end - start;

    // Mensajes de salida
    std::cout << "Tiempo inicio: " <<
        std::chrono::duration_cast<std::chrono::milliseconds>(start.time_since_epoch()).count() <<
        " ms" << std::endl;

    std::cout << "Tiempo final: " <<
        std::chrono::duration_cast<std::chrono::milliseconds>(end.time_since_epoch()).count() <<
        " ms" << std::endl;

    std::cout << "Tiempo de ejecucion: " << duration.count() << " segundos" << std::endl;

    std::cout << "Tiempo de ejecucion promedio: " << average_time << " segundos" << std::endl;
}

int main() {
    int number_iterations = 100000;  // Cambiar el valor si se quiere

    benchmark_collatz(number_iterations);
}
