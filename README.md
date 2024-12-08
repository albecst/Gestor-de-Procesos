# Gestor de Procesos

Este proyecto es un gestor de procesos que simula el funcionamiento de un sistema operativo. Permite crear, gestionar y simular la ejecución de procesos en un entorno controlado.

## Características

- **Creación de procesos**: Permite crear una pila de procesos con diferentes atributos como PID, tiempo de inicio, tiempo de vida, prioridad, etc.
- **Gestión de procesos**: Mueve procesos a la cola de espera, asigna procesos a núcleos libres y libera núcleos cuando el tiempo de vida del proceso ha terminado.
- **Simulación de tiempo**: Simula el paso del tiempo y muestra el estado de la pila de procesos, la cola de espera y los núcleos en ejecución.
- **Cálculo de tiempos**: Calcula el tiempo total y medio de estancia de los procesos en el sistema operativo.

## Cómo utilizarlo

Para utilizar la parte 1 introducir en la terminal:
* ```g++ -I./include src/main.cpp -o main && ./main```

Para utilizar la parte 2 introducir en la terminal:
* ```g++ -I./include src/main2.cpp -o main2 && ./main2```

*Hay disponibles dos sh para facilitar la compilación, pero dependiendo de la codificación del equipo puede mostrar un caracter NULL*

## Uso

Al ejecutar el programa, se mostrará un menú con las siguientes opciones:

### Si ejecuta el programa con `main`:
1. Crear la pila de procesos
2. Mostrar los procesos que se iniciarán
3. Borrar la pila de procesos
4. Mostrar la cola de espera de procesos
5. Mostrar los detalles de los procesos en ejecución
6. Simular que han pasado N minutos
7. Simular el funcionamiento de todos los procesos
0. Salir

### Si ejecuta el programa con `main2`:
1. Crear la pila de procesos
2. Mostrar los procesos que se iniciarán
3. Borrar la pila de procesos y reiniciar
4. Simular que han pasado N minutos
5. Mostrar los datos de la lista de núcleos
6. Consultar el núcleo con menos procesos y el más ocupado
7. Consultar el número total de núcleos operativos
8. Simular el funcionamiento de todos los procesos
0. Salir

Selecciona una opción para realizar la acción correspondiente.

## Contribuidores

- [@robeertosv](https://github.com/robeertosv)
- [@albecst](https://github.com/albecst)
