package MainPackage;

import MainPackage.Fibonacci;

public class Main {
    public static void main(String[] args) {
        long inicio = System.currentTimeMillis();
        long result = Fibonacci.fib(50);
        long fin = System.currentTimeMillis();
        double tiempoDeEjecucion = (fin - inicio)/1000.0;
        System.out.println("Resultado: " + result);
        System.out.println("Tiempo de ejecución: " + tiempoDeEjecucion + " segundos");
    }
}