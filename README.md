./compile.sh                                                                                        0000777 0001750 0001750 00000000077 14705445405 013134  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                clear
g++ -I./include src/main.cpp -o mi_programa
./mi_programa                                                                                                                                                                                                                                                                                                                                                                                                                                                                 ./include/                                                                                          0000777 0001750 0001750 00000000000 14706455367 012575  5                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                ./include/Cola/                                                                                     0000777 0001750 0001750 00000000000 14706514240 013435  5                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                ./include/Cola/Cola.cpp                                                                             0000777 0001750 0001750 00000006551 14706514240 015031  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include <iostream>
#include "NodoCola.h"
#include "Cola.h"
#include "Proceso/Proceso.h"
#include "Pila/Pila.h"

using namespace std;

Cola::Cola() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() {
    while (!isEmpty()) {
        pop();
    }
}

void Cola::push(Proceso proceso) {
    NodoCola *nuevo_nodo = new NodoCola(proceso);
    if (isEmpty()) {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    } else {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}

Proceso Cola::pop() {
    if (!isEmpty()) {
        Proceso proceso = primero->proceso;
        NodoCola *aux = primero;
        primero = primero->siguiente;
        if (primero == NULL) {
            ultimo = NULL;
        }
        delete aux;
        longitud--;
        return proceso;
    }
    throw runtime_error("La cola está vacía");
}

Proceso Cola::first() {
    if (!isEmpty()) {
        return primero->proceso;
    }
    throw runtime_error("La cola está vacía");
}

Proceso Cola::last() {
    if (!isEmpty()) {
        return ultimo->proceso;
    }
    throw runtime_error("La cola está vacía");
}

int Cola::getLength() {
    return longitud;
}

bool Cola::isEmpty() {
    return ((primero == NULL) && (ultimo == NULL));
}

void Cola::showQueue() {
    NodoCola *aux = primero;
    if (isEmpty()) {
        cout << "Cola Vacía: " << endl;
    } else {
        cout << "Datos de la Cola: " << endl;
        while (aux) {
            cout << "PID: " << aux->proceso.PID << endl;
            aux = aux->siguiente;
        }
    }
}

//1)
void Cola::reverse() {
    Cola c2;
    Cola c3;
    while (!isEmpty()) {
        c2.push(pop());
    }
    while (!c2.isEmpty()) {
        Proceso ultimo = c2.pop();
        while (!c2.isEmpty()) {
            c3.push(ultimo);
            ultimo = c2.pop();
        }
        push(ultimo);
        while (!c3.isEmpty()) {
            c2.push(c3.pop());
        }
    }
}

void Cola::isSorted() {
    if (isEmpty()) {
        cout << "La cola está vacía" << endl;
        return;
    }

    Cola aux;
    bool ordenada = true;
    Proceso valorAnterior = pop();
    aux.push(valorAnterior);

    while (!isEmpty()) {
        Proceso valorActual = pop();
        if (valorActual.priority < valorAnterior.priority) {
            ordenada = false;
        }
        aux.push(valorActual);
        valorAnterior = valorActual;
    }

    while (!aux.isEmpty()) {
        push(aux.pop());
    }

    if (ordenada) {
        cout << "La cola está ordenada de menor a mayor" << endl;
    } else {
        cout << "La cola no está ordenada de menor a mayor" << endl;
    }
}

//Para el scheduler
void Cola::sort() {
    Pila pilaAux;  

    while (!isEmpty()) {
        Proceso procesoActual = pop();

        while (!pilaAux.isEmpty() && pilaAux.top().priority > procesoActual.priority) {
            push(pilaAux.top());
            pilaAux.pop();
        }

        pilaAux.push(procesoActual);
        }

    // Volvemos a insertar los procesos desde la pila auxiliar a la cola
    while (!pilaAux.isEmpty()) {
        push(pilaAux.top());
        pilaAux.pop();
    }
}

// Para el scheduler
void Cola::clear() {
    while (!isEmpty()) {
        pop();
    }
}


                                                                                                                                                       ./include/Cola/Cola.h                                                                               0000777 0001750 0001750 00000001026 14706514240 014466  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Proceso/Proceso.h"

class Cola {
    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;

    public:
        Cola(); ~Cola();
        void push(Proceso);
        Proceso first();
        Proceso last();
        Proceso pop();
        bool isEmpty();
        int getLength();
        void reverse();
        void showQueue();
        void isSorted();
        void sort();
        void clear();
};
#endif // COLA_H                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ./include/Cola/NodoCola.cpp                                                                         0000777 0001750 0001750 00000000476 14705454131 015652  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "NodoCola.h"
#include "Proceso/Proceso.h"

NodoCola::NodoCola()
{
    proceso = Proceso(-1, -1, -1, -1, -1, -1);
    siguiente=NULL;
    //constructor por defecto
}

NodoCola::NodoCola(Proceso p, NodoCola*sig )
{
    proceso = p;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
    //dtor
}                                                                                                                                                                                                  ./include/Cola/NodoCola.h                                                                           0000777 0001750 0001750 00000000557 14705454616 015327  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "Proceso/Proceso.h"

class NodoCola {
    private:
        NodoCola *siguiente;
        Proceso proceso;

        friend class Cola;
        friend class Proceso;
    
    public:
        NodoCola();
        NodoCola(Proceso p, NodoCola*sig = NULL);
        ~NodoCola();
};

#endif                                                                                                                                                 ./include/Lista/                                                                                    0000777 0001750 0001750 00000000000 14706445405 013641  5                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                ./include/Lista/Lista.cpp                                                                           0000777 0001750 0001750 00000006456 14706703252 015434  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "NodoLista.h"
#include "Lista.h"
#include "Proceso/Proceso.h"
#include <iostream>

using namespace std;

Lista::Lista()
{
    nodo = new NodoLista(Proceso(), NULL);
    length = 0;
}

Lista::Lista(Proceso p)
{
    nodo = new NodoLista(p, NULL);
    length = 1;
}

Lista::~Lista()
{
}

int Lista::getLength() { return length; }

bool Lista::isEmpty()
{
    return length == 0;
}

// Funciones de adición
void Lista::append(Proceso p)
{
    if (length != 0)
    {
        plista current = nodo;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new NodoLista(p);
        length++;
    }
    else
    {
        nodo = new NodoLista(p);
        length = 1;
    }
}

void Lista::appendFront(Proceso p)
{
    plista current = nodo;
    plista nuevo = new NodoLista(p);
    nuevo->next = current;
    nodo = nuevo;
    length++;
}

void Lista::appendIndex(Proceso p, int idx) {
    cout << "YESS" << endl;

    if (idx <= 0) {  // Añadir al inicio si idx es 0 o negativo
        appendFront(p);
        return;
    }

    if (idx >= length) {  // Añadir al final si idx es mayor o igual a la longitud actual
        append(p);
        return;
    }

    plista current = nodo;

    for (int count = 0; count < idx - 1; count++) {  // Avanza hasta el nodo anterior a idx
        current = current->next;
    }

    // Inserta el nuevo nodo en la posición deseada
    plista insert = new NodoLista(p);
    insert->next = current->next;
    current->next = insert;  
}

// Funciones de borrado
void Lista::popLast()
{
    plista current = nodo;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    current->next = NULL;
    length--;
}
void Lista::popFront()
{
    nodo = nodo->next;
    length--;
}

void Lista::popIndex(int idx)
{
    plista current = nodo;
    plista sig = nodo;
    int count = 0;

    if(idx == 0) { popFront(); return;}

    if(idx == 1) {
        sig = sig->next->next;
        current->next = sig;
        length--;
        return;
    }

    while (count != idx - 1)
    {
        current = current->next;
        sig = current->next->next;
        count++;
    }

    if (sig)
    {
        current->next = sig;
        length--;        
    } else {
        popLast();
    }
}

// Getters

Proceso Lista::getFirst()
{
    return nodo->proceso;
}

Proceso Lista::getLast()
{
    plista current = nodo;

    while (current->next != NULL)
    {
        current = current->next;
    }

    return current->proceso;
}

Proceso Lista::getIndex(int idx) {
    plista current = nodo;
    
    for(int i = 0; i<idx; i++) current = current->next;

    return current->proceso;
}

// Funciones para usar en debug
void Lista::printFirst()
{
    cout << nodo->proceso.PID << endl;
}

void Lista::printLast()
{
    plista current = nodo;

    while (current->next != NULL)
    {
        current = current->next;
    }

    cout << current->proceso.PID << endl;
}

void Lista::toString()
{
    plista current = nodo;

    while (current != NULL)
    {
        cout << current->proceso.PID << ", ";
        current = current->next;
    }

    cout << endl;
}                                                                                                                                                                                                                  ./include/Lista/Lista.h                                                                             0000777 0001750 0001750 00000001324 14706674645 015103  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include "Proceso/Proceso.h"

class Lista {
    private:
        plista nodo; 
        int length;
        friend class Proceso;

    public:
        Lista();
        Lista(Proceso p);
        ~Lista();

        bool isEmpty();
        int getLength();

        void append(Proceso p);
        void appendFront(Proceso p);
        void appendIndex(Proceso p, int idx);

        void popLast();
        void popFront();
        void popIndex(int idx);

        Proceso getFirst();
        Proceso getLast();
        Proceso getIndex(int idx);

        void printFirst();
        void printLast();
        void toString();

};

#endif                                                                                                                                                                                                                                                                                                            ./include/Lista/NodoLista.cpp                                                                       0000777 0001750 0001750 00000000321 14706447353 016244  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "NodoLista.h"
#include "Proceso/Proceso.h"

NodoLista::NodoLista() {}

NodoLista::NodoLista(Proceso proc, NodoLista* sig) {
    proceso = proc;
    next = NULL;
}

NodoLista::~NodoLista() {}                                                                                                                                                                                                                                                                                                               ./include/Lista/NodoLista.h                                                                         0000777 0001750 0001750 00000000623 14706445606 015715  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Proceso/Proceso.h"
#include <iostream>

class NodoLista {
    public:
        Proceso proceso;
        NodoLista* next;
        friend class Proceso;
        friend class Lista;

    private:
        NodoLista();
        NodoLista(Proceso proc, NodoLista* sig = NULL);
        ~NodoLista();

};

typedef NodoLista* plista;

#endif                                                                                                             ./include/Pila/                                                                                     0000777 0001750 0001750 00000000000 14706514240 013444  5                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                ./include/Pila/NodoPila.cpp                                                                         0000777 0001750 0001750 00000000241 14705452460 015661  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "NodoPila.h"
#include "Proceso/Proceso.h"

NodoPila::NodoPila(Proceso p, NodoPila* sig) {
	proceso = p;
	next = sig;
}

NodoPila::~NodoPila() {}                                                                                                                                                                                                                                                                                                                                                               ./include/Pila/NodoPila.h                                                                           0000777 0001750 0001750 00000000475 14705452425 015340  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef NODOPILA_H
#define NODOPILA_H

#include <iostream>
#include "Proceso/Proceso.h"

class NodoPila
{
private:
	Proceso proceso;
	NodoPila *next;
	friend class Pila;
	friend class Proceso;

public:
	NodoPila(Proceso p, NodoPila *sig = NULL);
	~NodoPila();
};

typedef NodoPila *pnodo;

#endif                                                                                                                                                                                                   ./include/Pila/Pila.cpp                                                                             0000777 0001750 0001750 00000006115 14706514240 015043  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "Proceso/Proceso.h"
#include "NodoPila.h"
#include "Pila.h"
#include <iostream>
using namespace std;

// Constructor para la pila
Pila::Pila() {
	cima = NULL;
}

// Destructor
Pila::~Pila() {
	while(cima) pop();
}

// Push item to the top
void Pila::push(Proceso p) {
	pnodo nuevo = new NodoPila(p, cima);
	cima = nuevo;
}

// Pop the last item (LIFO)
Proceso Pila::pop() {
	pnodo nodo;

	if(cima) {
		nodo = cima;
		cima = nodo->next;
		delete nodo;
	}
	return nodo->proceso;
}

// Check if stack is empty
bool Pila::isEmpty() {
	return cima == NULL;
}

// Length of the stack
int Pila::length() {
	Pila aux;
	int length = 0;

	while(!isEmpty()) {
		aux.push(top());
		pop();
		length++;
	}

	for(int i = 0; i<length; i++) {
		push(aux.cima->proceso);
		aux.pop();
	}

	return length;
}

// View the top (without popping)
Proceso Pila::top() {
	if(!isEmpty()) {
		return cima->proceso;
	} else {
		return Proceso(-1, -1, -1, -1, -1, -1);
	}
}

// Reverse the stack
void Pila::reverse() {
	Pila aux;
	Pila aux2;

	while(!isEmpty()) {
		aux.push(cima->proceso);
		pop();
	}

	while(!aux.isEmpty()) {
		aux2.push(aux.cima->proceso);
		aux.pop();
	}

	while(!aux2.isEmpty()) {
		push(aux2.cima->proceso);
		aux2.pop();
	}

}

// Print the top item
void Pila::toString() {
	if(isEmpty()) {
		cout << "La pila está vacía" << endl;		
	} else {
		cout << "Cima de la pila: " << cima->proceso.PID << endl; 
	}
}

// Print all items
void Pila::showAll() {
	Pila tmp;

	while(!isEmpty()) {
		cout << cima->proceso.PID << ", ";
		tmp.push(cima->proceso);
		pop();
	}

	cout << "\n";

	while(!tmp.isEmpty()) {
		push(tmp.cima->proceso);
		tmp.pop();
	}
}

// Pop the last item
void Pila::popLast() {
	reverse();
	pop();
	reverse();
}

// Add sec to the stack
void Pila::concat(Pila sec) {
	sec.reverse();

	while(!sec.isEmpty()) {
		push(sec.cima->proceso);
		sec.cima = sec.cima->next;
	}
}

// Check is stack is ordered (Por orden de tiempo de salida)
bool Pila::isOrder() {
	bool order = true;
	pnodo aux = cima;

	while(aux->next != NULL && order) {
		if(aux->proceso.startTime > aux->next->proceso.startTime) {
			order = false;
		}

		aux = aux->next;
	}

	return order;
}


// Sort the stack por (Por orden de tiempo de salida) Ej (tiempo de vida): [1.2, 1.3, 1.1] -> [1.1, 1.2, 1.3]
void Pila::sortTTL() {
    Pila aux;
    Proceso tmp;

    while(!isEmpty()) {
        tmp = top();
        pop();

        while(!aux.isEmpty() && aux.top().startTime > tmp.startTime) { 
            push(aux.top());
            aux.pop();
        }

        aux.push(tmp);
    }

    while(!aux.isEmpty()) {
        push(aux.top());
        aux.pop();
    }
}

// Clear the stack
void Pila::clear() {
	while(!isEmpty()) {
		pop();
	}
}

// Get the sum of all TTL
int Pila::getAllTTL() {
	Pila aux;
	int ttl = 0;

	while(!isEmpty()) {
		ttl += top().ttl;
		aux.push(top());
		pop();
	}

	while(!aux.isEmpty()) {
		push(aux.top());
		aux.pop();
	}

	return ttl;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                   ./include/Pila/Pila.h                                                                               0000777 0001750 0001750 00000001636 14706514240 014513  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "Proceso/Proceso.h"

class Pila {
	private:
		pnodo cima;

	public:
		Pila();
		~Pila();
		void push(Proceso p); // Añadir un proceso a la pila
		Proceso pop(); // Quitar el proceso que esté en la cima de la pila
		Proceso top(); // Devuelve el proceso que está en la cima de la pila
		void toString(); // Mostrar la cima de la pila como texto
		void showAll(); // Mostrar toda la pila como texto
		int length(); // Ver el tamaño de la pila
		bool isEmpty(); // Saber si la pila está vacía
		void reverse(); // Invertir la pila
		void popLast(); // Quitar el último proceso de la pila
		void concat(Pila sec); // Unir dos pilas
		bool isOrder(); // Mirar si la pila está ordenada
		void sortTTL(); // Ordenar la pila por ttl
		void clear(); // Vaciar la pila
		int getAllTTL(); // Sumar todos los TTL de los procesos
};

#endif
                                                                                                  ./include/Proceso/                                                                                  0000777 0001750 0001750 00000000000 14705654105 014175  5                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                ./include/Proceso/Proceso.cpp                                                                       0000777 0001750 0001750 00000001523 14706674245 016327  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "Proceso.h"
#include <iostream>

using namespace std;

Proceso::Proceso() {
    PID = -1;
    PPID = -1;
    startTime = -1;
    ttl = -1;
    priority = -1;
    core = -1;
}

Proceso::Proceso(int pid, int START_TIME, int LIFE_TIME, int PRIORITY, int CORE, int ppid)
{
    PID = pid;
    PPID = ppid;
    startTime = START_TIME;
    ttl = LIFE_TIME;
    priority = PRIORITY;
    core = CORE;
}

Proceso::~Proceso()
{
}

void Proceso::decrementLifeTime(int quantity) {
    if (ttl > 0)
        ttl-=quantity;
}

void Proceso::toString()
{
    cout << "PID: " << PID << endl;
    cout << "PPID: " << PPID << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "Lifetime: " << ttl << " minutos" << endl;
    cout << "Priority: " << priority << endl;
    cout << "Core: " << core << endl;
}                                                                                                                                                                             ./include/Proceso/Proceso.h                                                                         0000777 0001750 0001750 00000001254 14706673655 016001  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef PROCESO_H
#define PROCESO_H

#include <iostream>

class Proceso {
    private:
        int PID;
        int PPID;
        int startTime;
        int ttl;
        int priority;
        int core;

        friend class Pila;
        friend class Cola;
        friend class Lista;
        friend class Scheduler;

    public:
        Proceso();
        Proceso(int pid, int START_TIME, int LIFE_TIME, int PRIORITY, int CORE, int ppid=1); // El PPID tiene que ir al final porque lleva un param por defecto
        ~Proceso();

        void decrementLifeTime(int quantity);
        void toString();

};

typedef Proceso* pproceso;

#endif // PROCESO_H                                                                                                                                                                                                                                                                                                                                                    ./include/Scheduler/                                                                                0000777 0001750 0001750 00000000000 14706661123 014500  5                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                ./include/Scheduler/ELScheduler.cpp                                                                 0000777 0001750 0001750 00000005242 14706703422 017350  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "ELScheduler.h"
#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include "Lista/NodoLista.h"
#include "Lista/Lista.h"

#include <iostream>
using namespace std;

Scheduler::Scheduler(int min)
{
    MIN_CORES = min;

    for (int i = 0; i < min; i++)
    {
        cores.append(Proceso());
    }
}

Scheduler::~Scheduler() {}

void Scheduler::init(int clk)
{
    for (int i = 0; i < MIN_CORES; i++)
    {
        addProcessToQueue(clk);
        addProcessToCore(clk);
    }
}

void Scheduler::addProcessToStack(Proceso p)
{
    procesos.push(p);
    procesos.sortTTL();
}

void Scheduler::addProcessToQueue(int time)
{
    if (!procesos.isEmpty())
    {
        procesos.sortTTL();
        colaEspera.push(procesos.top());
        colaEspera.sort();
        procesos.pop();
    }

    if (colaEspera.getLength() > 3)
    {
        addCore(time);
    }
}

void Scheduler::addProcessToCore(int time)
{

    /*for (int i = 0; i < cores.getLength(); i++)
    {
        Proceso core = cores.getIndex(i-1);

        if (core.PID == -1)
        {
            cores.appendIndex(colaEspera.first(), i);
            colaEspera.pop();
            return;
        }
    }*/

   int i = 0;
   while(cores.getIndex(i).PID != -1) {
        cout << "El core " << i << "está lleno, voy a otro" << endl; 
        i++;
   }
   cores.appendIndex(colaEspera.first(), i);
   colaEspera.pop();

   for(int j = 0; j<cores.getLength(); j++) {
        if(cores.getIndex(i).PID == -1) { cout << "ERR" << endl; }
   }
}

void Scheduler::addCore(int time)
{
    cores.append(Proceso(6,6,6,6,6,6));
    addProcessToCore(time);
}

void Scheduler::popCore(int idx)
{
    cores.popIndex(idx);
    for (int i = idx; i < cores.getLength(); i++)
    {
        Proceso core = cores.getIndex(idx);
        core.core = core.core - 1;
    }
}

void Scheduler::freeCore(int core, int time)
{
    Proceso f = cores.getIndex(core);
    f.PID = -1;

    if (cores.getLength() > MIN_CORES)
    {
        popCore(core);
    }
}

void Scheduler::toString()
{
    addProcessToQueue(5);
    addProcessToQueue(5);
    addProcessToQueue(5);
    addProcessToQueue(5);
    addProcessToQueue(5);
    cout << "--------------" << endl;
    cout << "STACK: " << endl;
    procesos.showAll();
    cout << endl;
    cout << "QUEUE: " << endl;
    colaEspera.showQueue();
    cout << endl;
    cout << "CORES: " << endl;
    for (int i = 0; i < cores.getLength()-1; i++)
    {
        cout << "Core: " << i + 1 << " PID: " << cores.getIndex(i).PID << endl;
    }
}                                                                                                                                                                                                                                                                                                                                                              ./include/Scheduler/ELScheduler.h                                                                   0000777 0001750 0001750 00000001544 14706700206 017013  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef ELSCHEDULER_H
#define ELSCHEDULER_H

#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include "Lista/NodoLista.h"
#include "Lista/Lista.h"

class Scheduler {
    private:
        Pila procesos;
        Cola colaEspera; // Máximo 2 en espera, si no, crear otro core
        Lista cores;

        int MIN_CORES;

    public:
        Scheduler(int min);
        ~Scheduler();

        void init(int clk);

        void addProcessToStack(Proceso p);
        void addProcessToQueue(int time);
        void addProcessToCore(int time);
        void addCore(int time);
        void popCore(int idx);
        void freeCore(int core, int time);
        void check(int time);

        void sortStack();

        void toString();

        
};

#endif                                                                                                                                                            ./include/Scheduler/Scheduler.cpp                                                                   0000777 0001750 0001750 00000010451 14706661123 017126  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "Scheduler.h"
#include "Pila/Pila.h"
#include <iostream>
#include <vector>
using namespace std;

Scheduler::Scheduler()
{
    std::cout << "El scheduler se ha iniciado!" << std::endl;
}

Scheduler::~Scheduler() {}

void Scheduler::addProcessToQueue()
{
    if (!procesos.isEmpty()) //TODO: Habría que añadir si (!procesos.isEmpty() && procesos.top().startTime <= SYS_CLK) 
    {
        procesos.sortTTL(); // Ordenar la pila de procesos
        colaEspera.push(procesos.top());
        colaEspera.sort(); // Ordenar la cola
        procesos.pop();
    }
}

void Scheduler::addProcessToCore(int time)
{
    if (!colaEspera.isEmpty())
    {
        if (core_1.PID == -1)
        {
            core_1 = colaEspera.first();
            core_1.ttl = core_1.ttl + time;
            core_1.core = 1;
            colaEspera.pop();
        }
        else if (core_2.PID == -1)
        {
            core_2 = colaEspera.first();
            core_2.ttl = core_2.ttl + time;
            core_2.core = 2;
            colaEspera.pop();
        }
        else if (core_3.PID == -1)
        {
            core_3 = colaEspera.first();
            core_3.ttl = core_3.ttl + time;
            core_3.core = 3;
            colaEspera.pop();
        }
        else
        {
            cout << "Todos los núcleos están ocupados, espera" << endl;
        }
    }
}

void Scheduler::freeCore(int core, int time)
{
    switch (core)
    {
    case 1:
        if (core_1.PID != -1)
        {
            tiempos.push_back(time - core_1.startTime);

            cout << "El proceso con PID: " << core_1.PID << " ha acabado, se ha sacado del core 1" << endl;
            core_1.PID = -1;
        }
        break;

    case 2:
        if (core_2.PID != -1)
        {
            tiempos.push_back(time - core_2.startTime);

            cout << "El proceso con PID: " << core_2.PID << " ha acabado, se ha sacado del core 2" << endl;
            core_2.PID = -1;
        }
        break;

    case 3:
        if (core_3.PID != -1)
        {
            tiempos.push_back(time - core_3.startTime);

            cout << "El proceso con PID: " << core_3.PID << " ha acabado, se ha sacado del core 3" << endl;
            core_3.PID = -1;
        }
        break;

    default:
        break;
    }

    addProcessToQueue();
    addProcessToCore(time);
}

void Scheduler::showProcesos()
{
    procesos.showAll();
}

void Scheduler::showQueue()
{
    colaEspera.showQueue();
}

void Scheduler::printCores()
{
    cout << "Core 1: " << core_1.PID << "\n Core 2: " << core_2.PID << "\n Core 3: " << core_3.PID << endl;
}

void Scheduler::addProcess(Proceso p)
{
    procesos.push(p);
    procesos.sortTTL();
}

void Scheduler::check(int time)
{
    bool pilaOK = false;

    // MIRAR SI HAY ALGO QUE SE PUEDA METER EN LA COLA DE ESPERA
    while (!pilaOK && !procesos.isEmpty())
    {
        if (procesos.top().startTime <= time)
        {
            cout << "Tengo que añadir el PID " << procesos.top().PID << " a la cola porque: " << procesos.top().startTime << " <= " << time << endl;
            addProcessToQueue();
        }
        else
        {
            pilaOK = true;
        }
    }

    addProcessToCore(time);
    addProcessToCore(time);
    addProcessToCore(time);

    if (core_1.ttl <= time)
    {
        freeCore(1, time);
    }

    if (core_2.ttl <= time)
    {
        freeCore(2, time);
    }

    if (core_3.ttl <= time)
    {
        freeCore(3, time);
    }
}

void Scheduler::init(int clk)
{
    addProcessToQueue();
    addProcessToQueue();
    addProcessToQueue();

    addProcessToCore(clk);
    addProcessToCore(clk);
    addProcessToCore(clk);
}

// Función que indica si todos los procesos han sido completados
bool Scheduler::allProcessesCompleted()
{
    if (procesos.isEmpty() && colaEspera.isEmpty() && core_1.PID == -1 && core_2.PID == -1 && core_3.PID == -1)
    {
        return true;
    }
    return false;
}

void Scheduler::clearProcesses()
{
    procesos.clear();
    colaEspera.clear();
    core_1.PID = -1;
    core_2.PID = -1;
    core_3.PID = -1;
}

Pila Scheduler::getProcesos()
{
    return procesos;
}

vector<int> Scheduler::getTiempos()
{
    return tiempos;
}                                                                                                                                                                                                                       ./include/Scheduler/Scheduler.h                                                                     0000777 0001750 0001750 00000001675 14706663652 016614  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include <vector>
using namespace std;


class Scheduler{
    private:
        Pila procesos;
        Cola colaEspera;
        vector<int> tiempos;

        Proceso core_1;
        Proceso core_2;
        Proceso core_3;

    public:
        Scheduler();
        ~Scheduler();
        
        void addProcessToQueue();
        void addProcessToCore(int time);
        void freeCore(int core, int time);
        void addProcess(Proceso p);
        void showProcesos();
        void showQueue();
        void printCores();
        void check(int time);

        void sortP();
        void init(int clk);
        bool allProcessesCompleted();
        void clearProcesses();
        Pila getProcesos();
        vector<int> getTiempos();
};

#endif                                                                   ./include/System33.h                                                                                0000777 0001750 0001750 00000000616 14706455443 014401  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef SYSTEM33_H
#define SYSTEM33_H

#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
#include "Pila/NodoPila.h"
#include "Pila/NodoPila.cpp"
#include "Pila/Pila.h"
#include "Pila/Pila.cpp"
#include "Cola/NodoCola.h"
#include "Cola/NodoCola.cpp"
#include "Cola/Cola.h"
#include "Cola/Cola.cpp"
#include "Scheduler/Scheduler.h"
#include "Scheduler/Scheduler.cpp"

#endif                                                                                                                  ./include/sysWOW.h                                                                                  0000777 0001750 0001750 00000001006 14706455400 014145  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #ifndef SYSTEM33_H
#define SYSTEM33_H

#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
#include "Pila/NodoPila.h"
#include "Pila/NodoPila.cpp"
#include "Pila/Pila.h"
#include "Pila/Pila.cpp"
#include "Cola/NodoCola.h"
#include "Cola/NodoCola.cpp"
#include "Cola/Cola.h"
#include "Cola/Cola.cpp"
#include "Lista/NodoLista.h"
#include "Lista/NodoLista.cpp"
#include "Lista/Lista.h"
#include "Lista/Lista.cpp"
#include "Scheduler/ELScheduler.h"
#include "Scheduler/ELScheduler.cpp"

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ./src/                                                                                              0000777 0001750 0001750 00000000000 14706661123 011726  5                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                ./src/main.cpp                                                                                      0000777 0001750 0001750 00000010662 14706661123 013366  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "System33.h"
#include <iostream>
#include <vector>

using namespace std;

int SYS_CLK = 0;
Scheduler scheduler;

void incrementTime(int cantidad) { SYS_CLK += cantidad; }

// 1: Crear la pila de procesos
void createProcessStack()
{
    Proceso p1(1, 5, 5, 8, -1, 3); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2(2, 5, 10, 7, -1, 1);
    Proceso p3(3, 5, 10, 9, -1, 1);
    Proceso p4(4, 5, 10, 8, -1, 1);
    Proceso p5(5, 5, 6, 1, -1, 1);

    scheduler.addProcess(p1);
    scheduler.addProcess(p2);
    scheduler.addProcess(p3);
    scheduler.addProcess(p4);
    scheduler.addProcess(p5);

    cout << "Procesos creados y añadidos a la pila." << endl;
}

// 2: Mostrar los procesos que se iniciarán
void showProcessStack()
{
    cout << "PIDs a cargar: ";
    scheduler.showProcesos();
}

// 3: Borrar la pila de procesos
void clearProcessStack()
{
    scheduler.clearProcesses();
    cout << "Pila de procesos borrada." << endl;
}

// 4: Mostrar la cola de espera de procesos
void showProcessQueue()
{
    scheduler.showQueue();
}

// 5: Mostrar los detalles de los procesos en ejecución
void showCoreDetails()
{
    scheduler.printCores();
}

// 6: Simular que han pasado N minutos
void simulateTime()
{
    int minutes;
    do
    {
        cout << "Ingrese la cantidad de minutos a simular (o -1 para salir): ";
        cin >> minutes;
        if (minutes != -1)
        {
            incrementTime(minutes);
            scheduler.check(SYS_CLK);
            cout << "----------------\n\n";
            cout << "PILA: ";
            scheduler.showProcesos();
            cout << endl;
            scheduler.showQueue();
            cout << endl;
            cout << "CORES: " << endl;
            scheduler.printCores();
        }
    } while (minutes != -1);
}

// 7: Simular el funcionamiento de todos los procesos, devuelve el tiempo medio de estancia en el SO de los procesos
void simulateAllProcesses()
{



    while (!scheduler.allProcessesCompleted())
    {
        incrementTime(1);
        scheduler.check(SYS_CLK);

        cout << "----------------\n\n";
        cout << "PILA: ";
        scheduler.showProcesos();
        cout << endl;
        scheduler.showQueue();
        cout << endl;
        cout << "CORES: " << endl;
        scheduler.printCores();
    }

    vector<int> tiempos = scheduler.getTiempos();
    int tiempoTotalP = 0;

    int numeroTiempos = tiempos.size();

    for (int tiempo : tiempos)
    {
        tiempoTotalP += tiempo;
    }

    cout << "Todos los procesos han sido ejecutados." << endl;
    cout << "El tamaño de tiempos es de: " << numeroTiempos << endl;
    cout << "El tiempo total de estancia de los recursos en SO es de " << tiempoTotalP << " minutos." << endl;
    cout << "El tiempo medio de estancia en el SO de los procesos es de: " << tiempoTotalP / numeroTiempos << " minutos." << endl;
}

int main()
{
    int option;
    do
    {
        cout << "---------------------------------------------------------" << endl;
        cout << "\nMenu:\n";
        cout << "1. Crear la pila de procesos\n";
        cout << "2. Mostrar los procesos que se iniciarán\n";
        cout << "3. Borrar la pila de procesos\n";
        cout << "4. Mostrar la cola de espera de procesos\n";
        cout << "5. Mostrar los detalles de los procesos en ejecución\n";
        cout << "6. Simular que han pasado N minutos\n";
        cout << "7. Simular el funcionamiento de todos los procesos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;
        cout << "\n---------------------------------------------------------" << endl;

        switch (option)
        {
        case 1:
            createProcessStack();
            break;
        case 2:
            showProcessStack();
            break;
        case 3:
            clearProcessStack();
            break;
        case 4:
            showProcessQueue();
            break;
        case 5:
            showCoreDetails();
            break;
        case 6:
            simulateTime();
            break;
        case 7:
            simulateAllProcesses();
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (option != 0);

    return 0;
}                                                                              ./src/mein.cpp.txt                                                                                  0000777 0001750 0001750 00000006466 14705446203 014216  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                #include "../include/Proceso/Proceso.h"
#include "../include/Proceso/Proceso.cpp"
#include "../include/Pila/NodoPila.h"
#include "../include/Pila/NodoPila.cpp"
#include "../include/Pila/Pila.h"
#include "../include/Pila/Pila.cpp"
#include "../include/Cola/Cola.cpp"
#include "../include/Cola/Cola.h"
#include "../include/Scheduler/scheduler.h"
#include "../include/Scheduler/scheduler.cpp"
#include <iostream>
using namespace std;

// Necesitamos un mínimo de 10 procesos (p1...p10) que pertenecerán a una pila.
// Una vez ya en la pila, los procesos serán enviados a uno de los 3 núcleos (3 colas), o a la cola de espera.
Pila procesos;
Cola nucleo1;
Cola nucleo2;
Cola nucleo3;
Cola colaEspera;
Scheduler scheduler;
int opcion;
int minutos;

// 1) Crear la pila de procesos, los procesos los creamos manualmente.
void opcion1()
{
	Proceso p1(1, 1, 1, 0, 1, 1);
	Proceso p2(2, 33, 1, 0, 9, 2);
	Proceso p3(3, 214, 1, 0, 2, 3);
	Proceso p4(4, 352, 1, 0, 7, 1);
	Proceso p5(5, 122, 1, 0, 3, 2);
	Proceso p6(6, 11, 1, 0, 2, 3);
	Proceso p7(7, 649, 1, 0, 3, 1);
	Proceso p8(8, 324, 1, 0, 5, 2);
	Proceso p9(9, 342, 1, 0, 7, 3);
	Proceso p10(10, 786, 1, 0, 2, 1);

	procesos.push(p1);
	procesos.push(p2);
	procesos.push(p3);
	procesos.push(p4);
	procesos.push(p5);
	procesos.push(p6);
	procesos.push(p7);
	procesos.push(p8);
	procesos.push(p9);
	procesos.push(p10);
}

// 2) Mostrar todos los procesos de la pila (podemos utilizar el método showAll).
void opcion2()
{
	procesos.showAll();
}

// 3) Borrar la pila de procesos
void opcion3()
{
	procesos.~Pila();
}

// 4) Mostrar la cola de espera de procesos.
void opcion4()
{
	colaEspera.showQueue();
}

// 5) Mostrar los detalles de los procesos que se encuentra en ejecución (en los 3 núcleos)
void opcion5()
{
	nucleo1.showQueue();
	nucleo2.showQueue();
	nucleo3.showQueue();
}

// 6) Simular que han pasado N minutos. Escribir en pantalla los datos de los procesos que llegan a las colas, y los que salen.
void opcion6()
{
	scheduler.simulate(minutos);
}

// 7) Simular el funcionamiento (escribiendo en pantalla todos los datos de los procesos), supongo que hasta que todos los procesos terminen.
void opcion7()
{
	scheduler.simulateComplete();
}

// Vamos a crear un menú para que el usuario pueda seleccionar alguna de las opciones anteriores.
int main()
{
	do
	{
		cout << "Menu:\n";
		cout << "1. Crear la pila de procesos\n";
		cout << "2. Mostrar la pila de procesos\n";
		cout << "3. Borrar la pila de procesos\n";
		cout << "4. Mostrar la cola de espera\n";
		cout << "5. Mostrar los detalles de los procesos en ejecucion\n";
		cout << "6. Simular que han pasado N minutos\n";
		cout << "7. Simular el funcionamiento completo\n";
		cout << "8. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			opcion1();
			break;
		case 2:
			opcion2();
			break;
		case 3:
			opcion3();
			break;
		case 4:
			opcion4();
			break;
		case 5:
			opcion5();
			break;
		case 6:
			cout << "Ingrese el numero de minutos: ";
			cin >> minutos;
			opcion6();
			break;
		case 7:
			opcion7();
			break;
		case 8:
			cout << "Saliendo...\n";
			break;
		default:
			cout << "Opcion invalida\n";
			break;
		}
	} while (opcion != 8);

	return 0;
}                                                                                                                                                                                                          ./src/pruebaManúMain.cpp                                                                           0000777 0001750 0001750 00000000000 14706453334 015742  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                ./src/test_lista.cpp                                                                                0000777 0001750 0001750 00000002671 14706703144 014616  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                // #include "System33.h"
#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"

#include "Pila/NodoPila.h"
#include "Pila/NodoPila.cpp"
#include "Pila/Pila.h"
#include "Pila/Pila.cpp"

#include "Cola/NodoCola.h"
#include "Cola/NodoCola.cpp"
#include "Cola/Cola.h"
#include "Cola/Cola.cpp"

#include "Lista/NodoLista.h"
#include "Lista/NodoLista.cpp"
#include "Lista/Lista.h"
#include "Lista/Lista.cpp"

#include "Scheduler/ELScheduler.h"
#include "Scheduler/ELScheduler.cpp"

#include <iostream>
using namespace std;

int SYS_CLK = 0;

int main()
{
    Proceso p1(1, 5, 5, 8, -1, 3); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2(2, 5, 10, 7, -1, 1);
    Proceso p3(3, 5, 10, 9, -1, 1);
    Proceso p4(4, 5, 10, 8, -1, 1);
    Proceso p5(5, 5, 6, 1, -1, 1);
    Proceso p6(6, 5, 5, 8, -1, 3); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p7(7, 5, 10, 7, -1, 1);
    Proceso p8(8, 5, 10, 9, -1, 1);
    Proceso p9(9, 5, 10, 8, -1, 1);
    Proceso p10(10, 5, 6, 1, -1, 1);

    Scheduler s(3); // Minimo 3 cores

    s.addProcessToStack(p1);
    s.addProcessToStack(p2);
    s.addProcessToStack(p3);
    s.addProcessToStack(p4);
    s.addProcessToStack(p5);
    s.addProcessToStack(p6);
    s.addProcessToStack(p7);
    s.addProcessToStack(p8);
    s.addProcessToStack(p9);
    s.addProcessToStack(p10);

    s.init(SYS_CLK);

    s.toString();

    return 0;
}
                                                                       ./test_compile.sh                                                                                   0000777 0001750 0001750 00000000110 14706701755 014163  0                                                                                                    ustar   roberto                         roberto                                                                                                                                                                                                                clear
g++ -I./include src/test_lista.cpp -g -o lista
# gdb lista
./lista                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        