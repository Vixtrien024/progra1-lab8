
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "DataLoader.h"

using namespace std;

class CheeseRepository {
public:
    CheeseRepository();

    int GetAvailableQuantity(const string& cheeseType) const;
    void UpdateQuantity(const string& cheeseType, int newQuantity);

private:
    unordered_map<string, vector<string>> data_;
};
