#include <iostream>
#include <iomanip>
#include <string>
#include "funciones.h"

int mostrarMapa()
{
    int a[16][16];
    int num = 1;

    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 16; j++){
            a[i][j] = num++;
        }
    }

    for (int i = 0; i < 16; i++){
        for (int h = 0; h < 5; h++){
            for (int j = 0; j < 16; j++){
                bool viahorizontal1 = (a[i][j] >= 17 && a[i][j] <= 31);
                bool viahorizontal2 = (a[i][j] >= 65 && a[i][j] <= 79);
                bool viahorizontal3 = (a[i][j] >= 113 && a[i][j] <= 127);
                bool viahorizontal4 = (a[i][j] >= 161 && a[i][j] <= 175);
                bool viahorizontal5 = (a[i][j] >= 209 && a[i][j] <= 223);

                bool viavertical = ((a[i][j] - 47) % 16 == 0 && a[i][j] >= 47 && a[i][j] <= 223);

                bool borde =
                    (a[i][j] >= 1 && a[i][j] <= 16) ||
                    (a[i][j] >= 241 && a[i][j] <= 256) ||
                    (a[i][j] % 16 == 1) ||
                    (a[i][j] % 16 == 0);

                bool entrada = (a[i][j] == 17);
                bool salida = (a[i][j] == 209);
                bool doble = (a[i][j] >= 178 && a[i][j] <= 206);
                bool especial_via = (a[i][j] == 191);
                bool especial_pared = (a[i][j] == 192 || a[i][j] == 193);

                if (especial_via) {
                    if (h == 2) std::cout << "via  ";
                    else std::cout << "     ";
                }
                else if (especial_pared) {
                    if (h == 2) std::cout << "pared";
                    else std::cout << "     ";
                }
                else if (entrada) {
                    if (h == 2) std::cout << "entra";
                    else std::cout << "     ";
                }
                else if (salida) {
                    if (h == 2) std::cout << "salid";
                    else std::cout << "     ";
                }
                else if (doble) {
                    std::cout << "|";
                    if (h == 2) {
                        std::cout << std::setw(3) << a[i][j] << "A";
                    }
                    else if (h == 4) {
                        std::cout << std::setw(3) << a[i][j] << "B";
                    }
                    else
                        std::cout << "    ";
                }
                else if (borde) {
                    if (h == 2) std::cout << "pared";
                    else std::cout << "     ";
                }
                else if (viahorizontal1 || viahorizontal2 || viahorizontal3 || viahorizontal4 || viahorizontal5 || viavertical) {
                    if (h == 2) std::cout << "via  ";
                    else std::cout << "     ";
                }
                else {
                    std::cout << "|";
                    if (h == 4) {
                        std::cout << std::setw(3) << a[i][j] << " ";
                    } else {
                        std::cout << "    ";
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

int mostrarMenu()
{
    std::cout << "\n===== MENU PARQUEADERO =====\n";
    std::cout << "1. Ingresar carro\n";
    std::cout << "2. Ingresar moto\n";
    std::cout << "3. Retirar vehiculo\n";
    std::cout << "4. Mostrar mapa\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
    return 0;
}

int ingresarCarro(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[], int &consecutivoTicket)
{
    std::string placa;
    int hora;
    int minuto;

    std::cout << "Ingrese placa: ";
    std::cin >> placa;
    std::cout << "Ingrese hora de entrada: ";
    std::cin >> hora;
    std::cout << "Ingrese minuto de entrada: ";
    std::cin >> minuto;

    for (int i = 0; i < 92; i++) {
        if (placasCarros[i] == "") {
            placasCarros[i] = placa;
            horaEntradaCarros[i] = hora;
            minutoEntradaCarros[i] = minuto;
            ticketCarros[i] = consecutivoTicket;

            std::cout << "Placa: " << placa << "\n";
            std::cout << "Puesto asignado: " << puestosCarros[i] << "\n";
            std::cout << "Ticket: " << ticketCarros[i] << "\n";
            std::cout << "Hora de entrada: " << hora << ":";
            if (minuto < 10) {
                std::cout << "0";
            }
            std::cout << minuto << "\n";

            consecutivoTicket++;
            return 0;
        }
    }

    std::cout << "Parqueadero de carros lleno\n";
    return 0;
}

int ingresarMoto(std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[], int &consecutivoTicket)
{
    std::string placa;
    int hora;
    int minuto;

    std::cout << "Ingrese placa: ";
    std::cin >> placa;
    std::cout << "Ingrese hora de entrada: ";
    std::cin >> hora;
    std::cout << "Ingrese minuto de entrada: ";
    std::cin >> minuto;

    for (int i = 0; i < 52; i++) {
        if (placasMotos[i] == "") {
            placasMotos[i] = placa;
            horaEntradaMotos[i] = hora;
            minutoEntradaMotos[i] = minuto;
            ticketMotos[i] = consecutivoTicket;

            std::cout << "Placa: " << placa << "\n";
            std::cout << "Puesto asignado: " << puestosMotos[i] << "\n";
            std::cout << "Ticket: " << ticketMotos[i] << "\n";
            std::cout << "Hora de entrada: " << hora << ":";
            if (minuto < 10) {
                std::cout << "0";
            }
            std::cout << minuto << "\n";

            consecutivoTicket++;
            return 0;
        }
    }

    std::cout << "Parqueadero de motos lleno\n";
    return 0;
}

float calcularValorPagar(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida, float tarifaMinuto)
{
    int minutosEntrada = horaEntrada * 60 + minutoEntrada;
    int minutosSalida = horaSalida * 60 + minutoSalida;
    int minutosTranscurridos = minutosSalida - minutosEntrada;

    if (minutosTranscurridos < 0) {
        std::cout << "Error: La hora de salida no puede ser anterior a la hora de entrada\n";
        return 0.0f;
    }

    return minutosTranscurridos * tarifaMinuto;
}

int retirarCarro(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[])
{
    std::string placa;
    int horaSalida;
    int minutoSalida;

    std::cout << "Ingrese placa del carro: ";
    std::cin >> placa;

    for (int i = 0; i < 92; i++) {
        if (placasCarros[i] == placa) {
            std::cout << "Ingrese hora de salida: ";
            std::cin >> horaSalida;
            std::cout << "Ingrese minuto de salida: ";
            std::cin >> minutoSalida;

            int minutosTotales = (horaSalida * 60 + minutoSalida) - (horaEntradaCarros[i] * 60 + minutoEntradaCarros[i]);
            if (minutosTotales < 0) {
                std::cout << "Error: La hora de salida no puede ser anterior a la hora de entrada\n";
                return 0;
            }

            float valorPagar = calcularValorPagar(horaEntradaCarros[i], minutoEntradaCarros[i], horaSalida, minutoSalida, 110.0f);
            std::cout << "Total a pagar: $" << valorPagar << "\n";

            // Liberar el espacio
            placasCarros[i] = "";
            horaEntradaCarros[i] = 0;
            minutoEntradaCarros[i] = 0;
            ticketCarros[i] = 0;

            return 0;
        }
    }

    std::cout << "Carro no encontrado\n";
    return 0;
}

int retirarMoto(std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[])
{
    std::string placa;
    int horaSalida;
    int minutoSalida;

    std::cout << "Ingrese placa de la moto: ";
    std::cin >> placa;

    for (int i = 0; i < 52; i++) {
        if (placasMotos[i] == placa) {
            std::cout << "Ingrese hora de salida: ";
            std::cin >> horaSalida;
            std::cout << "Ingrese minuto de salida: ";
            std::cin >> minutoSalida;

            int minutosTotales = (horaSalida * 60 + minutoSalida) - (horaEntradaMotos[i] * 60 + minutoEntradaMotos[i]);
            if (minutosTotales < 0) {
                std::cout << "Error: La hora de salida no puede ser anterior a la hora de entrada\n";
                return 0;
            }

            float valorPagar = calcularValorPagar(horaEntradaMotos[i], minutoEntradaMotos[i], horaSalida, minutoSalida, 60.0f);
            std::cout << "Total a pagar: $" << valorPagar << "\n";

            // Liberar el espacio
            placasMotos[i] = "";
            horaEntradaMotos[i] = 0;
            minutoEntradaMotos[i] = 0;
            ticketMotos[i] = 0;

            return 0;
        }
    }

    std::cout << "Moto no encontrada\n";
    return 0;
}

int menuSalida(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[], std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[])
{
    int subOpcion;
    std::cout << "\n=== SUBMENU SALIDA ===\n";
    std::cout << "1. Retirar carro\n";
    std::cout << "2. Retirar moto\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> subOpcion;

    switch(subOpcion)
    {
        case 1:
            retirarCarro(placasCarros, horaEntradaCarros, minutoEntradaCarros, ticketCarros, puestosCarros);
            break;
        case 2:
            retirarMoto(placasMotos, horaEntradaMotos, minutoEntradaMotos, ticketMotos, puestosMotos);
            break;
        default:
            std::cout << "Opcion invalida\n";
    }
    return 0;
}