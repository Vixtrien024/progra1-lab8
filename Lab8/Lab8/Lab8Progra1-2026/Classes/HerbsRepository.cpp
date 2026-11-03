#include "HerbsRepository.h"
#include <fstream>
#include <stdexcept>

using namespace std;

namespace {

string ResolveHerbsPath() {
    ifstream direct("herbs.txt");
    if (direct) {
        return "herbs.txt";
    }

    ifstream dataDir("Data/herbs.txt");
    if (dataDir) {
        return "Data/herbs.txt";
    }

    ifstream dataDirWindows("Data\\herbs.txt");
    if (dataDirWindows) {
        return "Data\\herbs.txt";
    }

    return "herbs.txt";
}

}

HerbsRepository::HerbsRepository()
    : filePath_(ResolveHerbsPath()) {
    data_ = DataLoader::LoadFromFile(filePath_);
}

int HerbsRepository::GetAvailableQuantity(const string& herbType) const {
    auto it = data_.find(herbType);

    if (it == data_.end() || it->second.empty()) {
        throw invalid_argument("Hierba desconocida: " + herbType);
    }

    return stoi(it->second[0]);
}

void HerbsRepository::UpdateQuantity(const string& herbType, int newQuantity) {
    if (newQuantity < 0) {
        throw invalid_argument("Cantidad invalida");
    }

    auto it = data_.find(herbType);

    if (it == data_.end() || it->second.empty()) {
        throw invalid_argument("Hierba desconocida: " + herbType);
    }

    it->second[0] = to_string(newQuantity);

    ofstream archivo(filePath_, ios::trunc);

    if (!archivo) {
        throw runtime_error("No se pudo guardar " + filePath_);
    }

    for (const auto& hierba : data_) {
        archivo << hierba.first << ": ";

        for (size_t i = 0; i < hierba.second.size(); ++i) {
            if (i > 0) {
                archivo << ", ";
            }
            archivo << hierba.second[i];
        }

        archivo << "\n";
    }

    if (!archivo) {
        throw runtime_error("No se pudo guardar " + filePath_);
    }
}
