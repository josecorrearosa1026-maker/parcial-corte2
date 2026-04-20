#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

int mostrarMapa();
int mostrarMenu();
int ingresarCarro(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[], int &consecutivoTicket);
int ingresarMoto(std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[], int &consecutivoTicket);
float calcularValorPagar(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida, float tarifaMinuto);
int retirarCarro(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[]);
int retirarMoto(std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[]);
int menuSalida(std::string placasCarros[], int horaEntradaCarros[], int minutoEntradaCarros[], int ticketCarros[], int puestosCarros[], std::string placasMotos[], int horaEntradaMotos[], int minutoEntradaMotos[], int ticketMotos[], std::string puestosMotos[]);

#endif