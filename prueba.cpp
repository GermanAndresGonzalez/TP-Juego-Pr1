#include <iostream>
#include <string>
#include "rlutil.h" // Asegúrate de tener rlutil.h en tu proyecto

// Función para limpiar la consola (si aún la necesitas, rlutil::cls() también sirve)
void limpiarConsola()
{
    rlutil::cls(); // rlutil tiene su propia función para limpiar la pantalla
}

// Función para dibujar el dado
void dibujarDado(int cantCaras, int valorDado, int x, int y)
{
    limpiarConsola(); // Limpiamos la pantalla antes de dibujar

    std::string dado[5]; // 5 filas de caracteres

    // Inicializamos con el borde y espacios
    dado[0] = "+-------+";
    dado[1] = "|       |";
    dado[2] = "|       |";
    dado[3] = "|       |";
    dado[4] = "+-------+";

    // Lógica para colocar los puntos O EL NÚMERO según el valor del dado y cantCaras
    if (cantCaras == 12)
    {
        // Si es un dado de 12 caras, mostramos el número en el centro
        std::string sValor = std::to_string(valorDado); // Convertimos el número a string
        int len = sValor.length();                      // Longitud del número

        // Calculamos la posición inicial para centrar el número
        // La columna 4 es el centro, pero si el número es de 2 dígitos, necesitamos ajustar
        int startCol = 4 - (len / 2);

        // Limpiamos la fila central para asegurar que no haya asteriscos residuales
        dado[2] = "|       |";

        // Colocamos el número en la posición calculada
        for (int i = 0; i < len; ++i)
        {
            dado[2][startCol + i] = sValor[i];
        }
    }
    else
    {
        // Si no es un dado de 12 caras (asumimos que es de 6, pero puedes extenderlo),
        // mantenemos la lógica de los puntos
        switch (valorDado)
        {
        case 1:
            dado[2][4] = '*'; // Punto central
            break;
        case 2:
            dado[1][2] = '*'; // Superior izquierda
            dado[3][6] = '*'; // Inferior derecha
            break;
        case 3:
            dado[1][2] = '*';
            dado[2][4] = '*';
            dado[3][6] = '*';
            break;
        case 4:
            dado[1][2] = '*';
            dado[1][6] = '*';
            dado[3][2] = '*';
            dado[3][6] = '*';
            break;
        case 5:
            dado[1][2] = '*';
            dado[1][6] = '*';
            dado[2][4] = '*';
            dado[3][2] = '*';
            dado[3][6] = '*';
            break;
        case 6:
            dado[1][2] = '*';
            dado[1][6] = '*';
            dado[2][2] = '*';
            dado[2][6] = '*';
            dado[3][2] = '*';
            dado[3][6] = '*';
            break;
        default:
            // Manejar un valor inválido o para dados de más de 6 caras que no sean 12
            break;
        }
    }

    // Imprimir el dado
    for (int i = 0; i < 5; ++i)
    {
        rlutil::locate(x, y + i); // Ahora 'y' es la posición inicial, sumamos 'i' para cada fila
        std::cout << dado[i] << std::endl;
    }
}

int main()
{
    rlutil::hidecursor(); // Opcional: oculta el cursor
    rlutil::cls();        // Limpia la consola al inicio

    // Ejemplo de uso para un dado de 6 caras
    std::cout << "Dado de 6 caras con valor 5:" << std::endl;
    dibujarDado(6, 5, 5, 2); // cantCaras, valorDado, x, y
    rlutil::locate(1, 10);   // Mueve el cursor para que no se pise el texto

    std::cout << "\nPresiona Enter para ver un dado de 12 caras con valor 7...";
    std::cin.ignore(); // Espera una pulsación de Enter
    std::cin.get();    // Consume el Enter

    // Ejemplo de uso para un dado de 12 caras
    dibujarDado(12, 7, 15, 2); // cantCaras, valorDado, x, y
    rlutil::locate(1, 10);

    std::cout << "\nPresiona Enter para ver un dado de 12 caras con valor 12...";
    std::cin.ignore();
    std::cin.get();

    dibujarDado(12, 14, 25, 2); // cantCaras, valorDado, x, y
    rlutil::locate(1, 10);

    std::cout << "\nPresiona Enter para finalizar.";
    std::cin.ignore();
    std::cin.get();

    rlutil::showcursor(); // Opcional: muestra el cursor al finalizar
    return 0;
}