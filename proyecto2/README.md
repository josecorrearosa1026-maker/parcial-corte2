# Proyecto 2 - Sistema de parqueadero con innovación y creatividad

## Descripción
Este proyecto corresponde a la versión mejorada del sistema de parqueadero.  
Se tomó como base el proyecto 1 y se le agregaron desarrollos innovadores para mejorar la experiencia de uso, la validación de datos y la presentación de la información.

## Funcionalidades base
- Registro de ingreso de carros.
- Registro de ingreso de motos.
- Registro de salida de vehículos.
- Cálculo del valor a pagar según el tiempo de permanencia.
- Visualización del mapa del parqueadero.
- Organización del programa mediante funciones.

## Desarrollos innovadores

### 1. Validación de placas repetidas
**¿Para qué se implementó?**  
Se implementó para evitar que un mismo vehículo fuera registrado más de una vez dentro del parqueadero.

**¿Por qué se consideró necesario?**  
Porque si una placa se repite, el sistema puede asignar dos puestos al mismo vehículo y generar errores en las consultas, en la salida y en el cálculo del cobro.

**¿Cómo se llevó a cabo su implementación?**  
Se recorrieron los arreglos de placas de carros y motos antes de registrar un nuevo ingreso. Si la placa ya existía en el sistema, se muestra un mensaje de error y se cancela el registro.

---

### 2. Validación de formato de placas
**¿Para qué se implementó?**  
Se implementó para asegurar que las placas ingresadas cumplan con una estructura realista.

**¿Por qué se consideró necesario?**  
Porque al inicio el sistema aceptaba cualquier dato como placa, incluso números sueltos o textos incorrectos, lo cual hacía poco realista el programa.

**¿Cómo se llevó a cabo su implementación?**  
Se agregaron funciones auxiliares para validar el formato:
- Carros: 3 letras y 3 números. Ejemplo: `ABC123`
- Motos: 3 letras, 2 números y 1 letra. Ejemplo: `ABC12D`

Si la placa no cumple la estructura, el sistema muestra error y no deja continuar.

---

### 3. Validación de hora y minuto
**¿Para qué se implementó?**  
Se implementó para controlar que las horas y minutos ingresados estén dentro de rangos válidos.

**¿Por qué se consideró necesario?**  
Porque el sistema podía recibir horas imposibles o minutos mayores a 59, lo que generaba errores en los cálculos del tiempo y del valor a pagar.

**¿Cómo se llevó a cabo su implementación?**  
Se agregaron validaciones en ingresos, consultas y retiros:
- Hora válida: de 0 a 23
- Minuto válido: de 0 a 59

Si el valor ingresado no cumple, se muestra un mensaje de error y la función termina.

---

### 4. Consulta de tiempo acumulado y valor pendiente
**¿Para qué se implementó?**  
Se implementó para permitir al usuario consultar cuánto tiempo lleva estacionado un vehículo y cuánto dinero debe hasta el momento.

**¿Por qué se consideró necesario?**  
Porque mejora la utilidad del sistema y permite conocer el cobro antes de retirar el vehículo.

**¿Cómo se llevó a cabo su implementación?**  
Se creó una opción adicional en el menú principal con un submenú de consulta para carros y motos. El sistema busca la placa, calcula los minutos transcurridos y muestra el valor acumulado.

---

### 5. Recibo bonito de salida
**¿Para qué se implementó?**  
Se implementó para mostrar la información de salida de manera más clara, ordenada y presentable.

**¿Por qué se consideró necesario?**  
Porque mejora la presentación del sistema y hace que el resultado final se vea más profesional.

**¿Cómo se llevó a cabo su implementación?**  
Se crearon funciones especiales para imprimir recibos de salida de carros y motos, mostrando:
- placa
- puesto
- ticket
- hora de entrada
- hora de salida
- tiempo total
- total a pagar

---

### 6. Mapa mejorado con indicador de ocupación "FILI"
**¿Para qué se implementó?**  
Se implementó para mostrar visualmente cuáles puestos del parqueadero están ocupados.

**¿Por qué se consideró necesario?**  
Porque el mapa básico solo mostraba los espacios, pero no permitía identificar rápidamente si estaban libres u ocupados.

**¿Cómo se llevó a cabo su implementación?**  
Se conectó el mapa con los arreglos de carros y motos registrados. Cuando un puesto está ocupado, en vez de mostrar el número normal, el sistema imprime `FILI` en el mapa.

## Estructura del proyecto
- `main.cpp`: contiene el menú principal y las llamadas a las funciones.
- `funciones.h`: contiene las declaraciones de las funciones.
- `funciones.cpp`: contiene la implementación de la lógica y las mejoras innovadoras.

## Conclusión
Este proyecto representa la versión mejorada del sistema de parqueadero.  
Además de cumplir con la base funcional del proyecto 1, incorpora validaciones, consultas, mejoras visuales y una presentación más completa de la información, fortaleciendo la lógica del programa y su nivel de realismo.