
#include "CheeseRepository.h"
#include "DataLoader.h"
#include <stdexcept>
#include <fstream>
#include <string>

using namespace std;

// Constructor: carga los quesos desde el archivo
CheeseRepository::CheeseRepository() {
    data_ = DataLoader::LoadFromFile("cheese.txt");
}

// Consulta la cantidad disponible
int CheeseRepository::GetAvailableQuantity(
    const string& cheeseType) const {

    auto it = data_.find(cheeseType);

    if (it == data_.end()) {
        throw invalid_argument("Queso desconocido: " + cheeseType);
    }

    return stoi(it->second[0]);
}

// Actualiza la cantidad y guarda los cambios
void CheeseRepository::UpdateQuantity(
    const string& cheeseType, int newQuantity) {

    auto it = data_.find(cheeseType);

    if (it == data_.end()) {
        throw invalid_argument("Queso desconocido: " + cheeseType);
    }

    if (newQuantity < 0) {
        throw invalid_argument("Cantidad invalida");
    }

    // Buscar el mismo archivo que carga DataLoader
    string path = "cheese.txt";
    ifstream prueba(path);

    if (!prueba.is_open()) {
        path = "Data/cheese.txt";
        prueba.clear();
        prueba.open(path);
    }

    if (!prueba.is_open()) {
        throw runtime_error("No se encontro cheese.txt");
    }

    prueba.close();

    // Guardar el inventario actualizado
    ofstream archivo(path);

    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir cheese.txt");
    }

    for (const auto& queso : data_) {
        int cantidad = stoi(queso.second[0]);

        if (queso.first == cheeseType) {
            cantidad = newQuantity;
        }

        archivo << queso.first << ": "
                << cantidad << "\n";
    }

    archivo.close();

    if (!archivo) {
        throw runtime_error("Error al guardar cheese.txt");
    }

    it->second[0] = to_string(newQuantity);
}
