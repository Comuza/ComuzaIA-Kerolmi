#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// El Cerebro de Kecomu
class Kecomu
{
public:
    map<string, string> memoria;

    Kecomu()
    {
        // --- NIVEL 1: BINARIO (Impulsos) ---
        memoria["0110"] = "Protocolo de inicio activado.";

        // --- NIVEL 2: ESPAÑOL (Órdenes) ---
        memoria["hola"] = "Hola Creador. Sistema listo.";
        memoria["limpiar"] = "cls"; // Comando real para Windows
        memoria["navegador"] = "start https://google.com";
    }

    void procesar(string entrada)
    {
        if (memoria.count(entrada))
        {
            // Si es un comando de sistema (como cls o start)
            if (entrada == "limpiar" || entrada == "navegador")
            {
                system(memoria[entrada].c_str());
                cout << "Kecomu: Orden ejecutada en la maquina." << endl;
            }
            else
            {
                // Si es solo una respuesta de texto
                cout << "Kecomu: " << memoria[entrada] << endl;
            }
        }
        else
        {
            cout << "Kecomu: No entiendo '" << entrada << "'. ¿Quieres enseñarme?" << endl;
        }
    }
};

int main()
{
    Kecomu cerebro;
    string orden;

    cout << "--- CABEZA.CPP CARGADA (5MB LIMIT) ---" << endl;

    while (true)
    {
        cout << "> ";
        getline(cin, orden);

        if (orden == "salir")
            break;
        cerebro.procesar(orden);
    }

    return 0;
}