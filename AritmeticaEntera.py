import random

class KeyManagement:
    """
    Manejo de las llaves, su generación y validación.
    """

    # Método para encontrar s y r
    # s es el mayor número entero tal que 2^s divide exactamente a n-1
    # r es un número impar tal que n-1 = 2^s * r donde r es un entero
    # Recibe n y devuelve s y r
    @staticmethod
    def encontrarSyR(n):
        s = 1
        while True:
            # Verifica si (n-1) no es divisible uniformemente por 2^s.
            if (n-1) % (2**s) != 0:
                break
            s += 1
        s = s - 1  # Ajusta s porque el último incremento rompió el bucle
        r = (n-1) // (2**s)  # Calcula r dividiendo (n-1) entre 2^s
        return s, r

    # Función de prueba de primalidad de Miller-Rabin
    # t es el número de iteraciones de prueba
    # n es el número a probar
    @staticmethod
    def millerRabin(t, n):
        while True:
            s, r = KeyManagement.encontrarSyR(n)
            check = 1  # Indicador de primalidad, 1 asume que es primo

            for _ in range(1, t):
                a = random.randint(2, n - 2)  # Elige un número aleatorio a en el rango [2, n-2]
                y = pow(a, r, n)  # Calcula a^r mod n

                # Verifica si y no es 1 ni n-1
                if y != 1 and y != n - 1:
                    j = 1
                    # Repite el proceso s-1 veces
                    while j <= s - 1 and y != n - 1:
                        y = pow(y, 2, n)  # Calcula y^2 mod n
                        if y == 1:
                            check = 0  # Si y se convierte en 1, n no es primo
                        j += 1
                    if y != n - 1:
                        check = 0  # Si y no es n-1, n no es primo
            if check == 0:
                return "No es primo", False  # Si check es 0, n no es primo
            else:
                return n, True  # Si check sigue siendo 1, n es primo
    
    @staticmethod
    def generate_key():
        t = 10  # Número de iteraciones para Miller-Rabin
        bits = 1024  # Cantidad de bits del tamaño del número
        """
        Primo aleatorio de n bits
        """
        while True:
            # Genera un número aleatorio candidato de 1024 bits
            candidato = random.randint(2**(bits-1), 2**bits)
            # Prueba si el candidato es primo usando Miller-Rabin
            n, estado = KeyManagement.millerRabin(t, candidato)
            if estado:
                return n  # Si el candidato es primo, retorna n
