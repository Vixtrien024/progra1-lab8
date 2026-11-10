
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "DataLoader.h"

using namespace std;

class MeatsRepository {
public:
    MeatsRepository();

    int GetAvailableQuantity(const string& meatType) const;
    void UpdateQuantity(const string& meatType, int newQuantity);

private:
    unordered_map<string, vector<string>> data_;
};
