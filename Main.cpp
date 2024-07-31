#include <iostream>
#include <locale>
#include <string>
#include <cstdlib> 

// Definición de la estructura del nodo
struct Num {
    int data;
    Num* next;
};

// Clase para la lista enlazada simple
class ListNum {
public:
    ListNum() : head(nullptr) {}
    ~ListNum() {        // Liberar toda la memoria utilizada por los nodos
        Num* current = head;
        while (current != nullptr) {
            Num* next = current->next;
            delete current;
            current = next;
        }
        std::cout << "Memoria de la lista liberada." << std::endl;
    }

    // Función para insertar un nuevo nodo al final de la lista
    void insert(int value) {
        Num* newNum = new Num();
        newNum->data = value;
        newNum->next = nullptr;
        if (head == nullptr) {
            head = newNum;
        } else {
            Num* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNum;
        }
    }

    // Función para eliminar un nodo con un valor específico
    void remove(int value) {
        if (head == nullptr) return;
        if (head->data == value) {
            Num* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Num* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return;
        Num* NumToDelete = temp->next;
        temp->next = temp->next->next;
        delete NumToDelete;
    }

    // Función para imprimir la lista
    void print() const {
        Num* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "null" << std::endl;
    }

private:
    Num* head;
};

int main() {
    // Configurar la consola para usar UTF-8
    std::setlocale(LC_ALL, "en_US.UTF-8");

    // Imprimir datos decorados
    std::cout << "*******************************" << std::endl;
    std::cout << "* Angel Guillermo de Jesús    *" << std::endl;
    std::cout << "*       Pérez Jiménez         *" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "*         202100215           *" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "*     Estructura de datos     *" << std::endl;
    std::cout << "*******************************" << std::endl;

    // Crear una lista enlazada
    ListNum list;
    // Menú de opciones
    std::string opcion;
    do {
        // Mostrar opciones al usuario
        std::cout << "\nSeleccione una opción:" << std::endl;
        std::cout << "1. Agregar un número a la lista" << std::endl;
        std::cout << "2. Eliminar un número de la lista" << std::endl;
        std::cout << "3. Ver la lista" << std::endl;
        std::cout << "F. Salir" << std::endl;
        std::cout << "Opción: ";
        std::cin >> opcion;
        // Procesar la opción seleccionada
        if (opcion == "1") {
            // Agregar un número a la lista
            std::string input;
            std::cout << "Ingrese el número que desea agregar: ";
            std::cin >> input;
            // Validar y convertir a entero
            int numToAdd;
            try {
                numToAdd = std::stoi(input);
            } catch (std::invalid_argument& e) {
                std::cerr << "Error: Ingrese un número válido." << std::endl;
                continue;
            } catch (std::out_of_range& e) {
                std::cerr << "Error: El número es demasiado grande." << std::endl;
                continue;
            }
            // Agregar el número a la lista
            list.insert(numToAdd);
            std::cout << "Número agregado correctamente." << std::endl;
            list.print(); // Mostrar la lista actualizada
        } else if (opcion == "2") {
            // Eliminar un número de la lista
            list.print(); // Mostrar la lista actual
            std::string input;
            std::cout << "Ingrese el número que desea eliminar: ";
            std::cin >> input;
            // Validar y convertir a entero
            int numToRemove;
            try {
                numToRemove = std::stoi(input);
            } catch (std::invalid_argument& e) {
                std::cerr << "Error: Ingrese un número válido." << std::endl;
                continue;
            } catch (std::out_of_range& e) {
                std::cerr << "Error: El número es demasiado grande." << std::endl;
                continue;
            }
            // Eliminar el número de la lista
            list.remove(numToRemove);
            std::cout << "Número eliminado correctamente." << std::endl;
            list.print(); // Mostrar la lista actualizada
        } else if (opcion == "3") {
            // Ver la lista
            list.print();
        }
    // Salir del programa si la opción seleccionada es "F"
    } while (opcion != "F" && opcion != "f");
// Salida del programa
    return 0;
    // Fin del programa
}