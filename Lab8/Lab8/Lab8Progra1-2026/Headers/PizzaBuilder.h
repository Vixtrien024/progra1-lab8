#pragma once
#include <vector>
#include <string>
#include "TomatoesRepository.h"
#include "HerbsRepository.h"
#include "IngredientSelector.h"
#include "CheeseRepository.h"
#include "MeatsRepository.h"

class PizzaBuilder {
public:
    PizzaBuilder();

    void BuildPizza();
    void DisplayFinalPizza() const;

private:
    void WaitForEnterAndClear();
    bool QuiereSeguirAgregandoTomate();
    void SelectTomatoes();
    void IrAlSiguienteIngrediente();
    void SelectCheese();
    void SelectHerb();
    void SelectMeat();
    void MostrarGrupo(const std::string& nombre, const std::vector<std::string>& ingredientes) const;
    int ContarTiposAgregados() const;

    TomatoesRepository tomatoRepo_;
    HerbsRepository herbsRepo_;
    CheeseRepository cheeseRepo_;
    MeatsRepository meatRepo_;

    // Cada miembro llena su lista desde su método Select.
    std::vector<std::string> selectedTomatoes_;
    std::vector<std::string> selectedCheeses_;
    std::vector<std::string> selectedMeats_;
    std::vector<std::string> selectedHerbs_;

    const std::vector<std::string> availableTomatoes_ = {
        "Cherry", "Roma", "Beefsteak", "Heirloom", "Grape"
    };

    const std::vector<std::string> availableHerbs_ = {
        "Basil", "Parsley", "Oregano", "Thyme",
        "Rosemary", "Cilantro", "Sage", "Chives"
    };

    const std::vector<std::string> availableCheeses_ = {
        "Mozzarella", "Cheddar", "Parmesan",
        "Cream Cheese", "Gouda", "Blue Cheese", "Feta"
    };

    const std::vector<std::string> availableMeats_ = {
        "Pepperoni",
        "Bacon",
        "Chicken",
        "Shrimp",
        "Mignon",
        "Ham",
        "Sausage",
        "Prosciutto"
    };
};
