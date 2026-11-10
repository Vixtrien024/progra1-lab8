
#include "MeatsRepository.h"
#include "DataLoader.h"
#include <stdexcept>
#include <fstream>
#include <string>

using namespace std;

// Constructor: carga las carnes desde el archivo
MeatsRepository::MeatsRepository() {
    data_ = DataLoader::LoadFromFile("meats.txt");
}

// Consulta la cantidad disponible
int MeatsRepository::GetAvailableQuantity(
    const string& meatType) const {

    auto it = data_.find(meatType);

    if (it == data_.end()) {
        throw invalid_argument("Carne desconocida: " + meatType);
    }

    return stoi(it->second[0]);
}

// Actualiza la cantidad y guarda los cambios
void MeatsRepository::UpdateQuantity(
    const string& meatType, int newQuantity) {

    auto it = data_.find(meatType);

    if (it == data_.end()) {
        throw invalid_argument("Carne desconocida: " + meatType);
    }

    if (newQuantity < 0) {
        throw invalid_argument("Cantidad invalida");
    }

    // Buscar el archivo de carnes
    string path = "meats.txt";
    ifstream prueba(path);

    if (!prueba.is_open()) {
        path = "Data/meats.txt";
        prueba.clear();
        prueba.open(path);
    }

    if (!prueba.is_open()) {
        throw runtime_error("No se encontro meats.txt");
    }

    prueba.close();

    // Guardar el inventario actualizado
    ofstream archivo(path);

    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir meats.txt");
    }

    for (const auto& carne : data_) {
        int cantidad = stoi(carne.second[0]);

        if (carne.first == meatType) {
            cantidad = newQuantity;
        }

        archivo << carne.first << ": "
            << cantidad << "\n";
    }

    archivo.close();

    if (!archivo) {
        throw runtime_error("Error al guardar meats.txt");
    }

    it->second[0] = to_string(newQuantity);
}
