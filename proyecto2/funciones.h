#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

int mostrarMapa(std::string placasCarros[], std::string placasMotos[], int puestosCarros[], std::string puestosMotos[]);
int mostrarMenu();
int ingresarCarro(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[], int &consecutivoTicket);
int ingresarMoto(std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[], int &consecutivoTicket);
int consultarCarro(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[]);
int consultarMoto(std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[]);
int imprimirReciboCarro(std::string placa, int puesto, int ticket, int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida, int minutosTotales, float totalPagar);
int imprimirReciboMoto(std::string placa, std::string puesto, int ticket, int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida, int minutosTotales, float totalPagar);
float calcularValorPagar(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida, float tarifaMinuto);
int retirarCarro(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[]);
int retirarMoto(std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[]);
int menuSalida(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[], std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[]);
int menuConsulta(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[], std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[]);

bool validarPlacaCarro(std::string placa);
bool validarPlacaMoto(std::string placa);

#endif