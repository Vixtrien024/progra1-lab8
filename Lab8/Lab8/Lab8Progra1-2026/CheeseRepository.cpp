
#include "CheeseRepository.h"
#include <stdexcept>
#include <fstream>
#include <utility>

using namespace std;

CheeseRepository::CheeseRepository() {
    data_ = DataLoader::LoadFromFile("cheese.txt");
}

int CheeseRepository::GetAvailableQuantity(
    const string& cheeseType) const {

    auto it = data_.find(cheeseType);

    if (it == data_.end()) {
        throw invalid_argument("Queso desconocido: " + cheeseType);
    }

    return stoi(it->second[0]);
}

void CheeseRepository::UpdateQuantity(
    const string& cheeseType, int newQuantity) {

    auto it = data_.find(cheeseType);

    if (it == data_.end()) {
        throw invalid_argument("Queso desconocido: " + cheeseType);
    }

    if (newQuantity < 0) {
        throw invalid_argument("Cantidad invalida");
    }

    string path = "cheese.txt";
    ifstream prueba(path);

    if (!prueba) {
        path = "Data/cheese.txt";
    }

    it->second[0] = to_string(newQuantity);

    ofstream archivo(path);

    if (!archivo) {
        throw runtime_error("No se pudo guardar cheese.txt");
    }

    for (const auto& queso : data_) {
        archivo << queso.first << ": "
                << queso.second[0] << "\n";
    }
}
