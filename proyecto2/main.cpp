#include <iostream>
#include <string>
#include "funciones.h"

int main()
{
    std::string placasCarros[92] = {};
    int horaEntradaCarros[92] = {};
    int minutoEntradaCarros[92] = {};
    int ticketCarros[92] = {};

    std::string placasMotos[52] = {};
    int horaEntradaMotos[52] = {};
    int minutoEntradaMotos[52] = {};
    int ticketMotos[52] = {};

    int puestosCarros[92] = {
        34,35,36,37,38,39,40,41,42,43,44,45,46,
        50,51,52,53,54,55,56,57,58,59,60,61,62,
        82,83,84,85,86,87,88,89,90,91,92,93,94,
        98,99,100,101,102,103,104,105,106,107,108,109,110,
        130,131,132,133,134,135,136,137,138,139,140,141,142,
        146,147,148,149,150,151,152,153,154,155,156,157,158,
        226,227,228,229,230,231,232,233,234,235,236,237,238,239
    };

    std::string puestosMotos[52] = {
        "178A","179A","180A","181A","182A","183A","184A","185A","186A","187A","188A","189A","190A",
        "178B","179B","180B","181B","182B","183B","184B","185B","186B","187B","188B","189B","190B",
        "194A","195A","196A","197A","198A","199A","200A","201A","202A","203A","204A","205A","206A",
        "194B","195B","196B","197B","198B","199B","200B","201B","202B","203B","204B","205B","206B"
    };

    int consecutivoTicket = 100;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch(opcion)
        {
            case 1:
                ingresarCarro(placasCarros, horaEntradaCarros, minutoEntradaCarros, ticketCarros, puestosCarros, consecutivoTicket);
                break;
            case 2:
                ingresarMoto(placasMotos, horaEntradaMotos, minutoEntradaMotos, ticketMotos, puestosMotos, consecutivoTicket);
                break;
            case 3:
                menuSalida(placasCarros, horaEntradaCarros, minutoEntradaCarros, ticketCarros, puestosCarros, placasMotos, horaEntradaMotos, minutoEntradaMotos, ticketMotos, puestosMotos);
                break;
            case 4:
                mostrarMapa(placasCarros, placasMotos, puestosCarros, puestosMotos);
                break;
            case 5:
                menuConsulta(placasCarros, horaEntradaCarros, minutoEntradaCarros, ticketCarros, puestosCarros, placasMotos, horaEntradaMotos, minutoEntradaMotos, ticketMotos, puestosMotos);
                break;
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida\n";
        }

    } while(opcion != 0);

    return 0;
}